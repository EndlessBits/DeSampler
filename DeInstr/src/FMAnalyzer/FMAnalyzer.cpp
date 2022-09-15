#include "FMAnalyzer.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object

//--------------------------------------------------------------
void FMAnalyzer::setup() {
}

//--------------------------------------------------------------
void FMAnalyzer::exit() {

}

//--------------------------------------------------------------
void FMAnalyzer::update() {

}

//--------------------------------------------------------------
void FMAnalyzer::draw() {

}

//--------------------------------------------------------------
void FMAnalyzer::reconstruct(const SoundSample& sample, FMSynth& synth)
{
	// Fragments distribution:
	// Most sound information contained at the started moments,
	// so we distribute fragments more at the beginning and less at the end.
	// Distributions: x^2, x^p, a^x.

	// Depending on type, we can have only 1-2 fragments, several, many.

	// sample rate:
	// for raw analysis we use lower sample rates, and then increate it.

}

//--------------------------------------------------------------
