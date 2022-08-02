#include "Instrument.h"

#include "gui_generated.h"
#include "ofxWindows.h"
#include "UI.h"

extern ofxKuTextGui gui;	//access to GUI object

Instrument INSTR;

//--------------------------------------------------------------
InstrumentState::InstrumentState() {
	pads.resize(PadsCount);
	control.resize(ControlCount);
}

//--------------------------------------------------------------
//--------------------------------------------------------------
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
	state_.pads[i] = state;
}

//--------------------------------------------------------------
void Instrument::on_instrument_selected(int8 i) {
	state_.instr = i;
}

//--------------------------------------------------------------
void Instrument::on_complexity_selected(int8 i) {
	state_.complexity = i;
}

//--------------------------------------------------------------
void Instrument::on_rec_sample_changed(int8 state) {
	state_.control[KeyControlRecSample] = state;
}

//--------------------------------------------------------------
void Instrument::draw() {
	// Pads
	for (int y = 0; y < PadsCountY; y++) {
		for (int x = 0; x < PadsCountX; x++) {
			UI.draw_button(PadCorner, x, y, PadBanksTitles[y] + ":" + ofToString(x + 1), 
				state_.pads[x+PadsCountX*y]);
		}
	}
	// Instr
	for (int x = 0; x < InstrCount; x++) {
		UI.draw_button(InstrCorner, x, 0, InstrTitles[x], (x== state_.instr));
	}
	// Complexity
	for (int x = 0; x < ComplexityCount; x++) {
		UI.draw_button(ComplexityCorner, x, 0, ComplexityTitles[x], (x== state_.complexity));
	}
	// Control
	for (int x = 0; x < ControlCount; x++) {
		UI.draw_button(ControlCorner, x, 0, ControlTitles[x], state_.control[x]);
	}
}

//--------------------------------------------------------------
