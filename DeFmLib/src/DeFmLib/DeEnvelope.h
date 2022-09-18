#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"

enum class DeEnvelopeType : int {
	Equidistant = 0,
	SlowingDown = 1
};

struct DeEnvelopeParams {
	DeEnvelopeType type = DeEnvelopeType::Equidistant;
	int size = 0;
};

// ��������� � ���������� � ���������� �� 0 �� 1
class DeEnvelope {
public:
	void setup(const string& title, const DeEnvelopeParams &params);
	string save_to_string();
	void load_from_string(const string& line);

	int size();
	vector<float>& times();
	vector<float>& values();
	const vector<float>& times() const;
	const vector<float>& values() const;

	/// ������ ���������������� ���������� ��������, ����������� duration_samples
	void sampling_begin(int duration_samples);

	/// �������� ��������� ��������
	float sampling_next_value();
protected:
	int size_ = 0;
	vector<float> times_;
	vector<float> values_;

	void init_equidistant();
	void init_slowingdown();

	// ��������
	int samples_ = 0;
	int sample_ = 0;
	int seg_index_ = 0;	// ����� �������� ������� �������������
	float seg_k_ = 0;
	float seg_a_ = 0;

	// ��������� ��������� ��� ������������� ���������� �������
	void set_segment(int index);
};
