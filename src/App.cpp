#include "App.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void App::setup(){

	time0_ = ofGetElapsedTimef();
	INPUT_KEYS.setup();
	UI.setup();
	INSTR.setup();
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
