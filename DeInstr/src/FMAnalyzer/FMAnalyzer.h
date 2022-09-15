#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "FMSynth.h"

class FMAnalyzer {
public:
	void setup();
	void exit();
	void update();
	void draw();

	// Generate synth from sound sample
	void reconstruct(const SoundSample& sample, FMSynth &synth);
};
