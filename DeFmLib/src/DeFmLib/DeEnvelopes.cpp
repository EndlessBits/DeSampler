#include "DeEnvelopes.h"

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

}

//--------------------------------------------------------------
void DeEnvelopes::load_from_file(const string& file_name) {

}

//--------------------------------------------------------------
