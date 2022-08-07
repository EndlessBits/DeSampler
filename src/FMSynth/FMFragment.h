#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "ofxSoundUtils.h"

/*

     *
      \ 
       *
    * /   \
           *
    * \   /  
       * 
      / 
    *
*/

class FMFragment {
public:
	void setup();
	void exit();
	void update();
	void draw();

	// It's expected that memory for out_buffer is allocated and set its sample_rate
	void generate_sound(SoundSample & out_buffer, int offset, int &written);

	int duration(int sr);
	float duration_ms = 0;


};
