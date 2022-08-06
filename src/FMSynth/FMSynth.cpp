#include "FMSynth.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void FMSynth::setup(){
}

//--------------------------------------------------------------
void FMSynth::exit() {

}

//--------------------------------------------------------------
void FMSynth::update(){

}

//--------------------------------------------------------------
void FMSynth::draw() {

}

//--------------------------------------------------------------
// It's expected that sample rate is set
void FMSynth::generate_sound(SoundSample& sample)
{
	int sr = sample.sample_rate;
	de_assert(sr > 0, "FMSynth::generate_sound - bad sample rate");
	int offset = 0;
	int d = duration(sr);
	sample.allocate(d);
	for (auto& f : fragments_)
	{
		int written;
		f.generate_sound(sample, offset, written);
		offset += written;
	}

}

//--------------------------------------------------------------
int FMSynth::duration(int sr)
{
	int d = 0;
	for (auto& f : fragments_) {
		d += f.duration(sr);
	}
	return d;
}

//--------------------------------------------------------------
