#include "FMOperator.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
FMOperator::FMOperator(FMShared* shared, FMOperatorWave wave, const FMLinearRamp& freq_ramp, const FMLinearRamp& amp_ramp)
{
	setup(shared, wave, freq_ramp, amp_ramp);
}

//--------------------------------------------------------------
void FMOperator::setup(FMShared* shared, FMOperatorWave wave, const FMLinearRamp& freq_ramp, const FMLinearRamp& amp_ramp)
{
	de_assert(shared, "FMOperator::setup - shared == nullptr");

	shared_ = shared;
	wave_ = wave;
	freq_ramp_ = freq_ramp;
	amp_ramp_ = amp_ramp;
}

//--------------------------------------------------------------
// It's expected that memory for out_buffer is allocated
// modulator can be an nullptr, so sample rate is used from sample
void FMOperator::render_sound_add(SoundSampleType* modulator, SoundSampleType* out_buffer, int sr, int duration)
{
	de_assert(out_buffer, "FMOperator::render_sound_add - out_buffer == nullptr");
	if (modulator == nullptr)
	{
		// No modulator, TODO implement
		de_exception("FMOperator::render_sound_add - modulator == nullptr case not implemented");
	}
	else 
	{
		// Modulator presented
		for (int i = 0; i < duration; i++)
		{
			//float amp = FM
		}
	}


}

//--------------------------------------------------------------
