#include "FMWaveform.h"
#include "Types.h"
#include "gui_generated.h"

extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void FMWaveform::setup(FMWaveformShape shape, int length)	// length in audio samples
{
	de_assert(length > 0, "FMWaveform::setup - bad length");
	length_ = length;
	wavetable_.resize(length);
	switch (shape)
	{
	case FMWaveformShape::Square:
		for (int i = 0; i < length; i++)
			wavetable_[i] = (i < length/2)?1:-1;
		break;
	case FMWaveformShape::Sine:
		for (int i = 0; i < length; i++)
			wavetable_[i] = sin(float(i) * M_TWO_PI / length);
		break;

	/*case FMWaveformShape::Triangle:
		de_exception("FMWaveformShape::Triangle not implemented");
		break;
	case FMWaveformShape::Saw:
		de_exception("FMWaveformShape::Saw not implemented");
		break;
	case FMWaveformShape::Noise:
		de_exception("FMWaveformShape::Noise not implemented");
		break;
		*/
	default:
		de_exception("FMWaveform::setup - bad shape");
	}

}

//--------------------------------------------------------------
float FMWaveform::value_unsafe(float phase)		// period 1
{
	return wavetable_[int(fmodf(phase, 1.0f) * length_)];
}

//--------------------------------------------------------------
