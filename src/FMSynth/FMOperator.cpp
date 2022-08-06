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
// It's expected that memory for sample is allocated
void FMOperator::generate_sound(SoundSample& modulator, SoundSample& sample, int offset)
{
	int sr = sample.sample_rate;
	int d = modulator.duration();

}

//--------------------------------------------------------------
int FMOperator::duration(int sr)
{
	return ofxSoundUtils::ms_to_samples(duration_ms, sr);
}

//--------------------------------------------------------------
