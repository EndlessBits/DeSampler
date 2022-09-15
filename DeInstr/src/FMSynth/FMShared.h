#pragma once

#include "ofMain.h"
#include "FMWaveform.h"

// FM synth shared params between fragments and operators
class FMShared {
public:
	FMShared() {}
	FMShared(float freq0, float freq1, float vol0, float vol1, int wavetable_lenth);

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

	// Wavetables
	float wavetable_unsafe(float phase, FMWaveformShape shape);
protected:
	// Init
	void setup_internal();	// Called automatically by FMInstrument

	vector<FMWaveform> waveforms_;
};
