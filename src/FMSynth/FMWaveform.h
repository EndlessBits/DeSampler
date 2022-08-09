#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "ofxSoundUtils.h"
#include "SoundSample.h"

// Wavetable synth for FM Operator.

enum class FMWaveformShape: int
{
	Square = 0,
	Sine = 1,
	//Saw = 2,
	//Triangle = 3,
	//Noise = 4,
	N = 2
};

class FMWaveform
{
public:
	void setup(FMWaveformShape shape, int length);	// length in audio samples
	float value_unsafe(float phase);		// period 1

protected:
	int length_ = 0;
	vector<SoundSampleType> wavetable_;
}; 

