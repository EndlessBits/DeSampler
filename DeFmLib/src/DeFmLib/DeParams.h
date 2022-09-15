#pragma once

#include "ofMain.h"
#include "FMWaveform.h"

// FM synth shared params between fragments and operators
class DeParams {
public:
	DeParams() {}
	DeParams(float freq0, int midi_note1, float vol0, float vol1, int wavetable_lenth);

	// Parameters
	float freq0 = 1;
	float freq1 = 5000;
	float vol0 = 0;
	float vol1 = 1;
	int wavetable_lenth = 1024;

	// Conversions
	float ramp_to_volume(float x);	// Convert 0..1 to exp-scale volume
	float ramp_to_freq(float x);	// Convert 0..1 to exp-scale freq
	float volume_to_ramp(float x);	
	float freq_to_ramp(float x);

	// Triangle wavetable
	float wavetable_unsafe(float phase);
protected:

};
