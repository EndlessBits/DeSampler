#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "FMFragment.h"
#include "ofxSoundUtils.h"

class FMSynth {
public:
	void setup();
	void exit();
	void update();
	void draw();

	// It's expected that sample rate is set
	void generate_sound(SoundSample &sample);	

	// Most sound information contained at the started moments,
	// so we distribute fragments more at the beginning and less at the end.
	// Distributions: x^2, x^p, a^x.
	vector<FMFragment> fragments_;

	int duration(int sr);

};
