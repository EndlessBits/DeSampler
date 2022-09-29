#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	title_ = "DeFmLib";
	cout << "--------------------------------------------------" << endl;
	cout << title_ << endl;
	cout << "1..9 - load preset, Shift+1..9 - save preset" << endl;
	cout << "L, Shift+S - load/save last opened or saved preset" << endl;
	cout << "Space - play sound" << endl;
	cout << "--------------------------------------------------" << endl;
	ofSetWindowTitle(title_);

	ofBackground(32);

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

	// Запуск звука
	sound_.setup();

}

//--------------------------------------------------------------
void ofApp::load_preset(int i) {
	if (i == -1) i = preset_;
	if (i == -1) return;

	preset_ = i;
	string file_name = "preset" + ofToString(i + 1) + ".fm";
	envelopes_.load_from_file(file_name);

	ofSetWindowTitle(title_ + " - " + file_name);
}

//--------------------------------------------------------------
void ofApp::save_preset(int i) {
	if (i == -1) i = preset_;
	if (i == -1) return;

	preset_ = i;
	string file_name = "preset" + ofToString(i + 1) + ".fm";
	envelopes_.save_to_file(file_name);

	ofSetWindowTitle(title_ + " - " + file_name);
}

//--------------------------------------------------------------
void ofApp::play_sound() {
	float duration_sec = 2;
	int sample_rate = 22050;
	vector<float> mono_sound = synth_.synth(duration_sec, sample_rate, &envelopes_);
	sound_.set_sound(mono_sound, sample_rate);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	float W = ofGetWidth();
	float H = ofGetHeight();
	// Прямоугольник для рисования редактора - также используется редактором для работы с мышью
	ofRectangle rect(0, 0, W, H);
	ofRectangle sound_rect(0.05 * W, 0.8 * H, 0.82 * W, 0.15 * H);

	editor_.draw(rect);
	sound_.draw(sound_rect);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key >= '1' && key <= '9') {
		load_preset(int(key - '1'));
	}
	if (key == '!') save_preset(0);
	if (key == '@') save_preset(1);
	if (key == '#') save_preset(2);
	if (key == '$') save_preset(3);
	if (key == '%') save_preset(4);
	if (key == '^') save_preset(5);
	if (key == '&') save_preset(6);
	if (key == '*') save_preset(7);
	if (key == '(') save_preset(8);

	if (key == 'l') load_preset();
	if (key == 'S') save_preset();

	if (key == ' ') play_sound();

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	editor_.mouse_moved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	editor_.mouse_dragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	editor_.mouse_pressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	editor_.mouse_released(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
