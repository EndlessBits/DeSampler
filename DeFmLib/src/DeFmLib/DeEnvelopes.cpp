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
	file.push_back(ofToString(n));
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
		int m = amp.size();
		file.push_back(ofToString(m));
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
void DeEnvelopes::load_from_file(const string& file_name) {
	cout << "Loading preset from " << file_name << endl;

}

//--------------------------------------------------------------
