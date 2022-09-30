#include "DeParams.h"


//--------------------------------------------------------------
void DeParams::setup(const DeParamsSettings& settings)
{
	s_ = settings;
	midi_delta_ = s_.midi_note1 - s_.midi_note0;

	db_delta_ = s_.db1 - s_.db0;
	float amp0 = db_to_amp_raw(s_.db0);
	float amp1 = db_to_amp_raw(s_.db1);
	db_k_ = 1.0f / (amp1 - amp0);			// mapping v in [amp0, amp1] -> k*v + a in [0,1]
	db_a_ = -db_k_ * amp0;

	mi_k_ = s_.mi1 - s_.mi0;
	mi_a_ = s_.mi0;
}

//--------------------------------------------------------------
// https://hydrogenaud.io/index.php?topic=86414.0
// db = 20*log10(amplitude)
//      6.02 * log2(Amplitude)
//amplitude = pow(2, dB/6.02), or pow(10, dB/20)

inline float DeParams::db_to_amp_raw(float db) {
	return pow(10.0f, db / 20.0f);
}

//--------------------------------------------------------------
//db to amp, 0..1->0..1
float DeParams::d2a(float x)
{
	x = x * db_delta_ + s_.db0;
	return db_k_ * db_to_amp_raw(x) + db_a_;
}

//--------------------------------------------------------------
// https://newt.phys.unsw.edu.au/jw/notes.html
// 69 is A, 440Hz, m=0..127
// m = 12*log2(fm/440 Hz) + 69 and fm = 2^((m-69)/12) * (440 Hz).

// linear to frequency, 0..1->Hz
float DeParams::l2f(float x)
{
	x = x * midi_delta_ + s_.midi_note0;
	return pow(2, (x - 69.0f) / 12.0f) * 440.0f;
}

//--------------------------------------------------------------
float DeParams::mi(float x)
{
	return mi_k_ * x + mi_a_;
}

//--------------------------------------------------------------
// Треугольная волна
// phase 0..1
float DeParams::wave(float phase)
{
	phase = phase * 4.0f - 2.0f;	// -2..2
	return ((phase >= 0) ? 1 : -1)    // sign
		* (1.0f - fabs(fabs(phase) - 1.0f));   //fabs(phase) 0..2
}


//--------------------------------------------------------------
