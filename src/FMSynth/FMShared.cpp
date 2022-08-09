#include "FMShared.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object

//--------------------------------------------------------------
FMShared::FMShared(float Freq0, float Freq1, float Vol0, float Vol1, int Wavetable_lenth)
{
	freq0 = Freq0;
	freq1 = Freq1;
	vol0 = Vol0;
	vol1 = Vol1;
	wavetable_lenth = Wavetable_lenth;
	setup_internal();
}

//--------------------------------------------------------------
void FMShared::setup_internal()
{
	waveforms_.resize(int(FMWaveformShape::N));
	for (int i = 0; i < int(FMWaveformShape::N); i++)
	{
		waveforms_[i].setup(FMWaveformShape(i), wavetable_lenth);
	}

}

//--------------------------------------------------------------
float FMShared::ramp_to_volume(float x)
{
	de_exception("ramp_to_volume - not implemented");
	return 0;
}

//--------------------------------------------------------------
float FMShared::ramp_to_freq(float x)
{
	de_exception("ramp_to_freq - not implemented");
	return 0;
}

//--------------------------------------------------------------
float FMShared::volume_to_ramp(float x)
{
	de_exception("volume_to_ramp - not implemented");
	return 0;
}

//--------------------------------------------------------------
float FMShared::freq_to_ramp(float x)
{
	de_exception("freq_to_ramp - not implemented");
	return 0;
}

//--------------------------------------------------------------
float FMShared::wavetable_unsafe(float phase, FMWaveformShape shape)
{
	return waveforms_[int(shape)].value_unsafe(phase);
}

//--------------------------------------------------------------
