#include "InputKeys.h"

#include "gui_generated.h"
#include "ofxWindows.h"

extern ofxKuTextGui gui;	//access to GUI object

InputKeys INPUT_KEYS;

//--------------------------------------------------------------
void InputKeys::setup(){

}

//--------------------------------------------------------------
void InputKeys::update(){
	cout << "space " << ofxWindows::capture_key_state(VK_SPACE)
		<< ", left " << ofxWindows::capture_key_state(VK_LEFT)
		<< ", A " << ofxWindows::capture_key_state('A')
		<< ", S " << ofxWindows::capture_key_state('S')
	<< endl;

}

//--------------------------------------------------------------
void InputKeys::draw() {

}

//--------------------------------------------------------------
