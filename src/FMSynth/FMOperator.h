#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "ofxSoundUtils.h"
#include "FMWaveform.h"

// FM Operator generates sound using given pre-rendered modulator buffer.
// It has ramp for its own carrier frequency and ramp for output volume.
// It writes result into some buffer (other operator input or audio input) additively.


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

class FMShared;

class FMOperator 
{
public:
	FMOperator() {}
	FMOperator(FMShared* shared, FMWaveformShape shape, const FMLinearRamp& freq_ramp, const FMLinearRamp& vol_ramp);

	// Structure 
	void setup(FMShared *shared, FMWaveformShape shape, const FMLinearRamp &freq_ramp, const FMLinearRamp &vol_ramp);

	// Sound generation
	// It's expected that memory for sample is allocated
	// modulator can be an nullptr, so sample rate is used from sample
	void render_sound_add(SoundSampleType* modulator, SoundSampleType* out_buffer, int sr, int duration);

protected:
	FMShared* shared_ = nullptr;
	FMWaveformShape shape_ = FMWaveformShape::Sine;

	FMLinearRamp freq_ramp_;
	FMLinearRamp vol_ramp_;

};
