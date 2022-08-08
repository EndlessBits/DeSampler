#pragma once

#include "ofMain.h"

// FM synth shared params between fragments and operators
class FMShared {
public:
	float freq0 = 1;
	float freq1 = 5000;
	float vol0 = 0;
	float vol1 = 1;

	float ramp_to_volume(float x);	// Convert 0..1 to exp-scale volume
	float ramp_to_freq(float x);	// Convert 0..1 to exp-scale freq
	float volume_to_ramp(float x);	
	float freq_to_ramp(float x);
};
