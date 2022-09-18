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

// Огибающая с диапазоном и значениями от 0 до 1
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

	/// Начать последовательное считывание значений, количеством duration_samples
	void sampling_begin(int duration_samples);

	/// Получить очередное значение
	float sampling_next_value();
protected:
	int size_ = 0;
	vector<float> times_;
	vector<float> values_;

	void init_equidistant();
	void init_slowingdown();

	// Семплинг
	int samples_ = 0;
	int sample_ = 0;
	int seg_index_ = 0;	// номер текущего отрезка сэмплирования
	float seg_k_ = 0;
	float seg_a_ = 0;

	// Вычислить параметры для семплирования очередного отрезка
	void set_segment(int index);
};
