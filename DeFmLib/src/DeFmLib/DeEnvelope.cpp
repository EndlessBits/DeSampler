#include "DeEnvelope.h"

//--------------------------------------------------------------
void DeEnvelope::setup(const string& title, const DeEnvelopeParams& params) {
	de_assert(params.size >= 2, "DeEnvelope::setup - bad size");
	size_ = params.size;
	times_ = generate_times(params);
	values_.resize(size_);
}

//--------------------------------------------------------------
/*static*/ vector<float> DeEnvelope::generate_times(const DeEnvelopeParams& params) {
	de_assert(params.size >= 2, "DeEnvelope::generate_times - bad size");
	int size = params.size;
	vector<float> times(size);
	switch (params.type) {
	case DeEnvelopeType::Equidistant:
		for (int i = 0; i < size; i++) {
			times[i] = float(i) / (size - 1);
		}
		break;
	case DeEnvelopeType::SlowingDown:
		for (int i = 0; i < size; i++) {
			float x = float(i) / (size - 1);
			times[i] = x * x;
		}
		break;
	case DeEnvelopeType::EquidistantPins:
		for (int i = 0; i < size; i++) {
			times[i] = float(i + 0.5) / size;
		}
		break;
	default:
		de_exception("DeEnvelope::generate_times - bad type");
	}
	return times;
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
	// Первый сэмпл
	int t0 = int(times_[index] * samples_);

	// Последний сэмпл. Гарантируем, чтобы последний сэмпл был samples_, 
	// чтобы не перелючался на несуществующий сегмент в конце
	int t1 = (index + 1 < size_) ? int(times_[index + 1] * samples_) : samples_;

	seg_index_ = index;
	seg_final_sample_ = t1;

	float v0 = values_[index];
	float v1 = values_[index + 1];
	//Коэффициенты для вычисления v = sample*k+a
	seg_k_ = (v1 - v0) / (t1 - t0);
	seg_a_ = -t0 * seg_k_ + v0;
}

//--------------------------------------------------------------
/// Получить очередное значение
float DeEnvelope::sampling_next_value() {
	de_assert(sample_ < samples_, "DeEnvelope::sampling_next_value - all samples are already read");
	float result = sample_ * seg_k_ + seg_a_;
	sample_++;
	// Переключение на следующий фрагмент
	if (sample_ == seg_final_sample_ && seg_index_ + 2 < size_) {
		set_segment(seg_index_ + 1);
	}
}

//--------------------------------------------------------------
