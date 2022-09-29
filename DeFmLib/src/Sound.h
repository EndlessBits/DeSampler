#pragma once

#include "ofMain.h"

class Sound {
public:
	void setup();
	void exit();
	void update();
	void draw(const ofRectangle& rect_pix);

	// Установить звук, и рисовать его потом
	void set_sound(vector<float>& mono_sound, int sample_rate);
	// Воспроизвести звук
	void play_sound();


	void audioOut(ofSoundBuffer& output);
	void audioIn(ofSoundBuffer& input);

protected:
	int stream_sr_ = 0;
	ofSoundStream sound_stream_;

	vector<float> mono_sound_;		// TODO change using mutex
	int sound_sr_ = 0;
	int playing_ = 0;
	int play_pos_ = 0;

};

extern Sound SOUND;

