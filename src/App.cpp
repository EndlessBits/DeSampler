#include "App.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void App::setup(){

	time0_ = ofGetElapsedTimef();
	INPUT_KEYS.setup();
	UI.setup();
	INSTR.setup();

	SOUND.setup();
}

//--------------------------------------------------------------
void App::exit() {
	SOUND.exit();
}

//--------------------------------------------------------------
void App::update(){	
	float time = ofGetElapsedTimef();
	float dt = time - time0_;
	time0_ = time;

	INPUT_KEYS.update();
	INSTR.update();

}

//--------------------------------------------------------------
void App::draw() {
	INSTR.draw();

}

//--------------------------------------------------------------
