#pragma once

#include "ofMain.h"

// FM synth shared params between fragments and operators
struct FMParams {
	float ramp_to_volume(float x);	// Convert 0..1 to exp volume
	float ramp_to_freq(float x);	// Convert 0..1 to exp freq
};
