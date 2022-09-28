#include "DeEnvelopes.h"
#include "ofxKuFile.h"

//--------------------------------------------------------------
void DeEnvelopes::setup(int n_ops, const DeEnvelopeParams& params) {
	Phases.resize(n_ops);	
	Amps.resize(n_ops);
	Freqs.resize(n_ops);
	for (int k = 0; k < n_ops; k++) {
		Amps[k].setup("Amp" + ofToString(k + 1), params);
		Freqs[k].setup("Freq" + ofToString(k + 1), params);
	}
}

//--------------------------------------------------------------
void DeEnvelopes::save_to_file(const string& file_name) {
	cout << "Saving preset to " << file_name << endl;

	int prec = 4;			// Точность
	vector<string> file;
	file.push_back("FM preset " + file_name);
	int n = Amps.size();
	int m = Amps[0].size();
	file.push_back(ofToString(n));
	file.push_back(ofToString(m));
	{
		file.push_back("Phases");
		string s = "";
		for (auto& phase : Phases) {
			if (!s.empty()) s += " ";
			s += ofToString(phase, prec);
		}
		file.push_back(s);
	}
	for (int k = 0; k < n; k++) {
		file.push_back("Operator " + ofToString(k + 1));
		auto& amp = Amps[k];
		auto& freq = Freqs[k];
		file.push_back("Time\tFreq\tAmp");
		for (int i = 0; i < m; i++) {
			file.push_back(
				ofToString(amp.times()[i], prec)
				+ "\t" + ofToString(freq.values()[i], prec)
				+ "\t" + ofToString(amp.values()[i], prec)
			);
		}
	}
	de_assert(ofxKuFileWriteStrings(file, file_name), "Error saving " + file_name);
}

//--------------------------------------------------------------
struct DeFileReader {
	bool open_file(const string& file_name) {
		file = ofxKuFileReadStrings(file_name);
		U = 0;
		return (!file.empty());
	}
	string next() {
		string result = "";
		if (U < file.size()) {
			result = file[U];
		}
		else {
			cout << "  Can't read line " << U + 1 << ", file too small" << endl;
		}
		U++;
		return result;
	}

	vector<string> file;
	int U = 0;
};

//--------------------------------------------------------------
void DeEnvelopes::load_from_file(const string& file_name) {
	cout << "Loading preset from " << file_name << endl;
	DeFileReader reader;
	if (!reader.open_file(file_name)) {
		cout << "Empty file " << file_name << endl;
		return;
	}

	reader.next(); // file.push_back("FM preset " + file_name);
	int n = ofToInt(reader.next());
	de_assert(n > 0, "Bad number of operators");
	int m = ofToInt(reader.next());
	de_assert(m > 0, "Bad size of envelope");

	// Выделение памяти
	DeEnvelopeParams params;
	params.size = m;
	setup(n, params);

	reader.next(); // file.push_back("Phases");
	auto phases = ofSplitString(reader.next()," ");
	de_assert(phases.size() >= n, "Bad phases line");
	for (int i = 0; i < n; i++) {
		Phases[i] = ofToFloat(phases[i]);
	}
	for (int k = 0; k < n; k++) {
		reader.next(); //file.push_back("Operator " + ofToString(k + 1));
		auto& amp = Amps[k];
		auto& freq = Freqs[k];
		reader.next(); //file.push_back("Time\tFreq\tAmp");
		for (int i = 0; i < m; i++) {
			auto list = ofSplitString(reader.next(), "\t");
			de_assert(list.size() >= 3, "Bad line " + ofToString(reader.U));
			amp.times()[i] = ofToFloat(list[0]);
			freq.values()[i] = ofToFloat(list[1]);
			amp.values()[i] = ofToFloat(list[2]);
		}
	}

}

//--------------------------------------------------------------
