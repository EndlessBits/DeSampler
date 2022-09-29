#pragma once

#include "ofMain.h"

class Sound {
public:
	void setup();
	void exit();
	void update();
	void draw(const ofRectangle& rect_pix);

	// ���������� ����, � �������� ��� �����
	void set_sound(vector<float>& mono_sound, int sample_rate);
	// ������������� ����
	void play_sound();


	void audioOut(ofSoundBuffer& output);
	void audioIn(ofSoundBuffer& input);

protected:
	ofSoundStream sound_stream_;

};

extern Sound SOUND;

