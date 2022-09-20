#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	string title = "DeFmLib";
	cout << "--------------------------------------------------" << endl;
	cout << title;
	cout << "--------------------------------------------------" << endl;
	ofSetWindowTitle(title);

	// Параметры конверсии
	float midi_note0 = 21;
	float midi_note1 = 108;
	float db0 = -40;
	float db1 = 0;

	// Параметры огибающих
	DeEnvelopeParams env_params;
	env_params.type = DeEnvelopeType::Equidistant;
	env_params.size = 10;

	params_.setup(midi_note0, midi_note1, db0, db1);

	envelopes_.setup(DeFmSynth::n_ops, env_params);
	editor_.setup(&envelopes_);

	synth_.setup(&params_);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// Прямоугольник для рисования редактора - также используется редактором для работы с мышью
	ofRectangle rect(0, 0, ofGetWidth(), ofGetHeight());
	editor_.draw(rect);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	editor_.mouse_moved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	editor_.mouse_dragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	editor_.mouse_pressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	editor_.mouse_released(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
