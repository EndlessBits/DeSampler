#include "FMFragment.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void FMFragment::setup(){
}

//--------------------------------------------------------------
void FMFragment::exit() {

}

//--------------------------------------------------------------
void FMFragment::update(){

}

//--------------------------------------------------------------
void FMFragment::draw() {

}

//--------------------------------------------------------------
// It's expected that memory is allocated
void FMFragment::generate_sound(SoundSample& out_buffer, int offset, int& written)
{
	int sr = out_buffer.sample_rate;
	int d = duration(sr);
	written = d;
	de_assert(offset + d <= out_buffer.data.size(), "FMFragment::generate_sound - allocated sample length inconsistency");
	

}

//--------------------------------------------------------------
int FMFragment::duration(int sr)
{
	return ofxSoundUtils::ms_to_samples(duration_ms, sr);
}

//--------------------------------------------------------------
