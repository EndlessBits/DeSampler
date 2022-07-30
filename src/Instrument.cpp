#include "Instrument.h"

#include "gui_generated.h"
#include "ofxWindows.h"

extern ofxKuTextGui gui;	//access to GUI object

Instrument INSTR;

//--------------------------------------------------------------
void Instrument::setup() {

}

//--------------------------------------------------------------
void Instrument::update() {
	// Now get events here, but later will put into audio thread
	process_keyboard_events();
}

//--------------------------------------------------------------
void Instrument::process_keyboard_events() {
	auto events = INPUT_KEYS.get_events();
	for (auto& ev : events) {
		switch (ev.key.type) {
		case KeyTypePad:
			on_pad_changed(ev.key.index, ev.state);
			break;
		case KeyTypeInstr:
			if (ev.state)
				on_instrument_selected(ev.key.index);
			break;
		case KeyTypeComplexity:
			if (ev.state)
				on_complexity_selected(ev.key.index);
			break;
		case KeyTypeControl:
			switch (ev.key.index) {
			case KeyControlRecSample:
				on_rec_sample_changed(ev.state);
				break;
			default:
				de_exception("Instrument::process_keyboard_events: Bad key KeyTypeControl index");
			}
			break;
		default:
			de_exception("Instrument::process_keyboard_events: Bad key type");
		}
	}

}

//--------------------------------------------------------------
void Instrument::on_pad_changed(int8 i, int8 state) {

}

//--------------------------------------------------------------
void Instrument::on_instrument_selected(int8 i) {

}

//--------------------------------------------------------------
void Instrument::on_complexity_selected(int8 i) {

}

//--------------------------------------------------------------
void Instrument::on_rec_sample_changed(int8 state) {

}

//--------------------------------------------------------------
void Instrument::draw() {

}

//--------------------------------------------------------------
