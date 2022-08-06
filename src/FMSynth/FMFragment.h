#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "ofxSoundUtils.h"

class FMFragment {
public:
	void setup();
	void exit();
	void update();
	void draw();

	// It's expected that memory is allocated
	void generate_sound(SoundSample &sample, int offset, int &written);

	int duration(int sr);
	float duration_ms = 0;


};
