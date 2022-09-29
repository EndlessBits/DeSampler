#pragma once

#include "ofMain.h"

class Sound {
public:
	void setup();
	void exit();
	void update();
	void draw(const ofRectangle& rect);	// rect 0..1

	// Установить звук, и рисовать его потом
	void set_sound(vector<float>& mono_sample, int sample_rate);
	// Воспроизвести звук
	void play_sound();


	void audioOut(ofSoundBuffer& output);
	void audioIn(ofSoundBuffer& input);

protected:
	ofSoundStream sound_stream_;

};

extern Sound SOUND;

