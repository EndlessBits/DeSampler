#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// Огибающие синтезатора

class DeEnvelopes {
public:
	void setup(int n_ops, const DeEnvelopeParams& params);
	void save_to_file(const string &file_name);
	void load_from_file(const string& file_name);

	vector<float> Phases;	  // Начальные фазы
	vector<DeEnvelope> Amps;  // Амплитуды
	vector<DeEnvelope> Freqs; // Частоты
protected:

};
