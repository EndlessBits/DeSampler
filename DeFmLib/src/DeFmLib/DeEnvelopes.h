#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// ��������� �����������

class DeEnvelopes {
public:
	void setup(int n_ops, const DeEnvelopeParams& params);
	void save_to_file(const string &file_name);
	void load_from_file(const string& file_name);

	vector<float> Phases;	  // ��������� ����
	vector<DeEnvelope> Amps;  // ���������
	vector<DeEnvelope> Freqs; // �������
protected:

};
