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

	vector<FMFragment> fragments_;

	int duration(int sr);

};
