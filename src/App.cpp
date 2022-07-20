#include "App.h"

#include "gui_generated.h"
#include "InputKeys.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void App::setup(){

	time0_ = ofGetElapsedTimef();
	INPUT_KEYS.setup();
}

//--------------------------------------------------------------
void App::update(){	
	float time = ofGetElapsedTimef();
	float dt = time - time0_;
	time0_ = time;

	INPUT_KEYS.update();

}

//--------------------------------------------------------------
void App::draw() {
	INPUT_KEYS.draw();
}

//--------------------------------------------------------------
