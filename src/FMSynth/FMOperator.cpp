#include "FMOperator.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void FMOperator::setup(){
}

//--------------------------------------------------------------
void FMOperator::exit() {

}

//--------------------------------------------------------------
void FMOperator::update(){

}

//--------------------------------------------------------------
void FMOperator::draw() {

}

//--------------------------------------------------------------
// It's expected that memory for out_buffer is allocated
// modulator can be an empty array, so sample rate is used from sample
void FMOperator::generate_sound_add(const SoundSample& modulator, SoundSample& out_buffer, int offset)
{
	int sr = out_buffer.sample_rate;
	int d = modulator.duration();
	if (modulator.data.empty())
	{

	}
	else 
	{
		de_assert(modulator.duration() == out_buffer.duration(), "FMOperator::generate_sound_add - Bad modulator or out_buffer size")
	}


}

//--------------------------------------------------------------
