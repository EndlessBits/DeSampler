#pragma once

#include "ofMain.h"

struct SoundSample {
	int sample_rate = 44100;
	vector<float> data;
};
