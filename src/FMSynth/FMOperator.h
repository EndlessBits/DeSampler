#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "ofxSoundUtils.h"

// Operator creates sound using pre-rendered modulator frequencies (it can be const too)

// Freq ramp and amplitude ramps are included at each operator.
// Here thay are linear, but we should use their as arguments for exp.
struct FMLinearRamp
{
	float value0 = 0;
	float value1 = 0;
	float value(int i, int duration) const {
		if (duration > 1)
		{
			// Note: last value not approach value1, last point is excluded - it's required for continuing
			return (value1 - value0) * i / duration + value0;
		}
		return value0;
	}
}; 

// Wave shape
enum class FMOperatorWave
{
	Sine = 0,
	Triangle,
	Square,
	Saw,
	Noise
};

class FMOperator 
{
public:
	void setup();
	void exit();
	void update();
	void draw();

	// It's expected that memory for sample is allocated
	// modulator can be an empty array, so sample rate is used from sample
	void generate_sound_add(const SoundSample& modulator, SoundSample &out_buffer, int offset);

	FMOperatorWave wave = FMOperatorWave::Sine;
	FMLinearRamp amp_ramp;
	FMLinearRamp freq_ramp;


};
