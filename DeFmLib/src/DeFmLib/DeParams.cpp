#include "DeParams.h"


//--------------------------------------------------------------
DeParams::DeParams(float Freq0, int midi_note1, float Vol0, float Vol1, int Wavetable_lenth)
{
	freq0 = Freq0;
	freq1 = Freq1;
	vol0 = Vol0;
	vol1 = Vol1;
	wavetable_lenth = Wavetable_lenth;
}

//--------------------------------------------------------------
float DeParams::ramp_to_volume(float x)
{
	return ofMap(exp(x),exp(0),exp(1),vol0, vol1);	//vol0..vol exponentially  // TODO table
}

//--------------------------------------------------------------
// https://newt.phys.unsw.edu.au/jw/notes.html
// 69 is A, 440Hz, m=0..127
//m  =  12*log2(fm/440 Hz) + 69     and    fm  =  2(m−69)/12(440 Hz).

float DeParams::ramp_to_freq(float x)
{
	return ofMap(exp(x), exp(0), exp(1), freq0, freq1);	//freq0..freq1 exponentially  // TODO table
	return 0;
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
float DeParams::wavetable_unsafe(float phase, FMWaveformShape shape)
{
	return waveforms_[int(shape)].value_unsafe(phase);
}

//--------------------------------------------------------------
