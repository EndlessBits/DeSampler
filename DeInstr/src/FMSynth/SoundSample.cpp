#include "SoundSample.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object

//--------------------------------------------------------------
void SoundSample::allocate(int duration)
{
	data.resize(duration);
	fill(data.begin(), data.end(), 0);
}

//--------------------------------------------------------------
int SoundSample::duration() const
{
	return data.size();
}

//--------------------------------------------------------------
bool SoundSample::empty() const
{
	return data.empty();
}

//--------------------------------------------------------------
void SoundSample::fill_zero()
{
	fill(data.begin(), data.end(), 0);
}

//--------------------------------------------------------------
SoundSampleType* SoundSample::data_ptr()
{
	if (empty()) return nullptr;
	return data.data();

}

//--------------------------------------------------------------
