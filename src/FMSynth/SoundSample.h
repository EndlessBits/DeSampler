#pragma once

#include "ofMain.h"

// Audio buffer

typedef float SoundSampleType;

struct SoundSample {
	int sample_rate = 44100;	

	vector<SoundSampleType> data;
	void allocate(int duration);
	int duration() const;
	bool empty() const;
	void fill_zero();
	SoundSampleType* data_ptr();
};
