#include "InputKeys.h"

#include "gui_generated.h"
#include "ofxWindows.h"

extern ofxKuTextGui gui;	//access to GUI object

InputKeys INPUT_KEYS;

//--------------------------------------------------------------
void InputKeys::setup(){
	state_.resize(KeysCount);
}

//--------------------------------------------------------------

int InputKeys::get_key_VK(int i) {	// Convert key index to virtual keyboard index
	de_assert(i >= 0 && i < KeysCount, "get_key_VK: Bad key index " + ofToString(i));
	return KeysVK[i];
}

//--------------------------------------------------------------
void InputKeys::close() {

}

//--------------------------------------------------------------
void InputKeys::update() {
	/*auto& ev = get_events();
	for (auto& e : ev) {
		cout << "  event " << int(e.key.type) << " " << e.key.index << ": " << int(e.state) << endl;
	}*/
/*	cout << "space " << ofxWindows::capture_key_state(VK_SPACE)
		<< ", left " << ofxWindows::capture_key_state(VK_LEFT)
		<< ", A " << ofxWindows::capture_key_state('A')
		<< ", S " << ofxWindows::capture_key_state('S')
	<< endl;
	*/

}

//--------------------------------------------------------------
KeyDescr InputKeys::key_index_to_descr(int i) {
	de_assert(i >= 0 && i < KeysCount, "key_index_to_descr: Bad key index " + ofToString(i));
	KeyDescr descr;
	if (i < KeyIndexInstr) {		// Pads
		descr.type = KeyTypePad;
		descr.index = i - KeyIndexPads;
	}
	else if (i < KeyIndexComplexity) { // Instruments
		descr.type = KeyTypeInstr;
		descr.index = i - KeyIndexInstr;
	}
	else if (i < KeyIndexControl) {		// Complexity
		descr.type = KeyTypeComplexity;
		descr.index = i - KeyIndexComplexity;
	}
	else {								// Control
		descr.type = KeyTypeControl;
		descr.index = i - KeyIndexControl;
	}
	return descr;
}

//--------------------------------------------------------------
vector<KeyEvent> InputKeys::get_events() {	// Compute current events
	events_.clear();
	for (int i = 0; i < KeysCount; i++) {
		int8 new_state = (ofxWindows::capture_key_state(get_key_VK(i)) != 0);
		if (new_state != state_[i]) {
			state_[i] = new_state;
			events_.push_back({ key_index_to_descr(i), new_state });
		}
	}
	return events_;
}

//--------------------------------------------------------------
