#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"

// FM synth shared params between fragments and operators
class DeParams {
public:
	DeParams() {}
	DeParams(float midi_note0, float midi_note1, float vol0, float vol1);

	// Parameters
	float midi_note0 = 21;
	float midi_note1 = 108;
	float vol0 = 0;
	float vol1 = 1;
	int wavetable_lenth = 1024;

	// Conversions
	float ramp_to_volume(float x);	// Convert 0..1 to exp-scale volume
	float ramp_to_freq(float x);	// Convert 0..1 to exp-scale freq
	float volume_to_ramp(float x);	
	float freq_to_ramp(float x);

	// Triangle wavetable
	float wavetable(float phase);
protected:
	float midi_delta_ = 0;
};
