#pragma once

#include "ofMain.h"
#include "Types.h"
#include "InputKeys.h"

struct InstrumentState {
	vector<int8> pads;
	int8 instr = 0;
	int8 complexity = 0;
	vector<int8> control;
	InstrumentState();
};

struct Instrument {
	void setup();
	void update();
	void draw();

	void at_update();	// update in audio thread

protected:
	InstrumentState state_;
	void process_keyboard_events();
	void on_pad_changed(int8 i, int8 state);
	void on_instrument_selected(int8 i);
	void on_complexity_selected(int8 i);

	void on_rec_sample_changed(int8 state);


};

extern Instrument INSTR;
