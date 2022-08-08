#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "FMFragment.h"
#include "FMShared.h"
#include "ofxSoundUtils.h"

// FM Synthesizer:
//   FM Shared - sets ranges for frequencies and volumes.
//   FM Fragment 1, FM Fragment 2, FM Fragment 3,... - fragments of sound in time
//         Each FM Fragment consists of graph of FM Operators.

class FMSynth {
public:
	// Structure
	void setup(FMShared shared, vector<float> durations_ms, vector<FMFragment> fragments);

	void test_topology();
	void test_generation();

	// Sound generation
	// It's expected that sample rate is set
	void generate_sound(SoundSample& out_buffer);


protected:
	// Synth structure
	FMShared shared_;				// common parameters
	vector<float> durations_ms_;	// durations of audio fragments
	vector<FMFragment> fragments_;  // audio fragments

	int size_ = 0;
	float duration_ms_ = 0;

	// Sound generation


};
