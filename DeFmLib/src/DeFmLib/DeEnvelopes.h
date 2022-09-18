#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// Набор огибающих для синтезатора
class DeEnvelopes {
public:
	void setup(const DeEnvelopeParams& params, DeParams *p);
	void save_to_file(const string &file_name);
	void load_from_file(const string& file_name);

	vector<DeEnvelope> Phases;	// values() хранят начальные фазы для каждого оператора синтезатора
	vector<DeEnvelope> Amps;
	vector<DeEnvelope> Freqs;
protected:
	DeParams* p_ = 0;

};
