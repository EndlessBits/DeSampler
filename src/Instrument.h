#pragma once

#include "ofMain.h"
#include "Types.h"
#include "InputKeys.h"

struct Instrument {
	void setup();
	void update();
	void draw();

protected:
	vector<int8> pads_;
	int8 instr_ = 0;
	int8 complexity_ = 0;
	int8 rec_sample_ = 0;

	void process_keyboard_events();
	void on_pad_changed(int8 i, int8 state);
	void on_instrument_selected(int8 i);
	void on_complexity_selected(int8 i);

	void on_rec_sample_changed(int8 state);


};

extern Instrument INSTR;
