#include "DeParams.h"


//--------------------------------------------------------------
DeParams::DeParams(float midi_note0, float midi_note1, float vol0, float vol1)
{
	this->midi_note0 = midi_note0;
	this->midi_note1 = midi_note1;
	midi_delta_ = this->midi_note1 - this->midi_note0;

	this->vol0 = vol0;
	this->vol1 = vol1;
}

//--------------------------------------------------------------
float DeParams::ramp_to_volume(float x)
{
	return ofMap(exp(x),exp(0),exp(1),vol0, vol1);	//vol0..vol exponentially  // TODO table
}

//--------------------------------------------------------------
// https://newt.phys.unsw.edu.au/jw/notes.html
// 69 is A, 440Hz, m=0..127
//m  =  12*log2(fm/440 Hz) + 69     and    fm  =  2^(m−69)/12(440 Hz).

float DeParams::ramp_to_freq(float x)
{
	x = x * midi_delta_ + midi_note0;
	return pow(2, x − 69) / 12;
}

//--------------------------------------------------------------
float DeParams::volume_to_ramp(float x)
{
	de_exception("volume_to_ramp - not implemented");
	return 0;
}

//--------------------------------------------------------------
float DeParams::freq_to_ramp(float x)
{
	de_exception("freq_to_ramp - not implemented");
	return 0;
}

//--------------------------------------------------------------
float DeParams::wavetable(float phase)
{
	return 0;// waveforms_[int(shape)].value_unsafe(phase);
}

//--------------------------------------------------------------
