#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "ofxSoundUtils.h"

// Operator creates sound using pre-rendered modulator frequencies (it can be const too)

enum class FMOperatorType
{
	Const = 0,
	Ramp,
	Sin,
	Square,
	Triangle,
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
	void generate_sound(SoundSample& modulator, SoundSample &sample, int offset);

	FMOperatorType type = FMOperatorType::Const;

	int duration(int sr);
	float duration_ms = 0;


};
