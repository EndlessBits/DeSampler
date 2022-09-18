#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// ����� ��������� ��� �����������
class DeEnvelopes {
public:
	void setup(const DeEnvelopeParams& params, DeParams *p);
	void save_to_file(const string &file_name);
	void load_from_file(const string& file_name);

	vector<DeEnvelope> Phases;	// values() ������ ��������� ���� ��� ������� ��������� �����������
	vector<DeEnvelope> Amps;
	vector<DeEnvelope> Freqs;
protected:
	DeParams* p_ = 0;

};
