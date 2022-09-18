#include "DeEnvelope.h"

//--------------------------------------------------------------
void DeEnvelope::setup(const string& title, const DeEnvelopeParams& params) {
	de_assert(params.size >= 2, "DeEnvelope::setup - bad size");
	size_ = params.size;
	times_.resize(size_);
	values_.resize(size_);
	switch (params.type) {
	case DeEnvelopeType::Equidistant: init_equidistant(); break;
	case DeEnvelopeType::SlowingDown: init_slowingdown(); break;
	default:
		de_exception("DeEnvelope::setup - bad type");
	}

}

//--------------------------------------------------------------
void DeEnvelope::init_equidistant() {
	for (int i = 0; i < size_; i++) {
		times_[i] = float(i) / (size_ - 1);
	}
}

//--------------------------------------------------------------
void DeEnvelope::init_slowingdown() {
	for (int i = 0; i < size_; i++) {
		float x = float(i) / (size_ - 1);
		times_[i] = x * x;
	}
}

//--------------------------------------------------------------
int DeEnvelope::size() {
	return size_;
}

//--------------------------------------------------------------
vector<float>& DeEnvelope::times() {
	return times_;
}

//--------------------------------------------------------------
vector<float>& DeEnvelope::values() {
	return values_;
}

//--------------------------------------------------------------
const vector<float>& DeEnvelope::times() const {
	return times_;
}

//--------------------------------------------------------------
const vector<float>& DeEnvelope::values() const {
	return values_;
}

//--------------------------------------------------------------
string DeEnvelope::save_to_string() {
	string s;
	for (int i = 0; i < size_; i++) {
		if (i > 0) s += " ";
		s += ofToString(times_[i], 4) + " " + ofToString(values_[i], 4);
	}
	return s;
}

//--------------------------------------------------------------
void DeEnvelope::load_from_string(const string& line) {
	auto list = ofSplitString(line, " ");
	de_assert(list.size() % 2 == 0, "DeEnvelope::load_from_string - bad line");
	size_ = list.size() / 2;
	times_.resize(size_);
	values_.resize(size_);
	for (int i = 0; i < size_; i++) {
		times_[i] = ofToFloat(list[2 * i]);
		values_[i] = ofToFloat(list[2 * i + 1]);
	}
}

//--------------------------------------------------------------
/// Начать последовательное считывание значений, количеством duration_samples
void DeEnvelope::sampling_begin(int duration_samples) {
	samples_ = duration_samples;
	sample_ = 0;

	set_segment(0);
}

//--------------------------------------------------------------
// Вычислить параметры для семплирования очередного отрезка
void DeEnvelope::set_segment(int index) {
	de_assert(index >= 0 && index < size_, "DeEnvelope::set_segment - bad index");
	seg_index_ = index;
	float t0 = times_[index] * samples_;
	float t1 = times_[index+1] * samples_;
	float v0 = values_[index];
	float v1 = values_[index+1];
	//Коэффициенты для вычисления v = sample*k+a
	seg_k_ = (v1 - v0) / (t1 - t0);
	seg_a_ = -t0 * seg_k_ + v0;
}

//--------------------------------------------------------------
/// Получить очередное значение
float DeEnvelope::sampling_next_value() {
	de_assert(sample_ < samples_, "DeEnvelope::sampling_next_value - all samples are already read");
	float result = 
	sample_++;
}

//--------------------------------------------------------------
