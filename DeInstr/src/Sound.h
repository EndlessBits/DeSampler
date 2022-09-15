#pragma once

#include "ofMain.h"

class Sound {
public:
	void setup();
	void exit();
	void update();
	void draw();

	void audioOut(ofSoundBuffer& output);
	void audioIn(ofSoundBuffer& input);
	ofSoundStream sound_stream;
};

extern Sound SOUND;

