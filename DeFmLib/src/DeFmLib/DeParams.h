#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"

// FM synth shared params between fragments and operators
class DeParams {
public:
	DeParams() {}
	DeParams(float midi_note0, float midi_note1, float db0, float db1);

	// Ranges
	float midi_note0 = 21;
	float midi_note1 = 108;
	float db0 = -40;
	float db1 = 0;

	// Conversions
	float ramp_to_volume(float x);	//0..1->0..1
	float ramp_to_freq(float x);	//0..1->Hz
	float volume_to_ramp(float x);
	float freq_to_ramp(float x);

	// Triangle wavetable
	float wavetable(float phase);
protected:
	float midi_delta_ = 0;
	float db_delta_ = 0;
	float db_k_ = 1;
	float db_a_ = 0;
	inline float db_to_amp_raw(float db);
};
