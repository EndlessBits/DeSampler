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
// modulator can be an empty array, so sample rate is used from sample
void FMOperator::generate_sound_add(const SoundSample& modulator, SoundSample& out_buffer, int offset)
{
	int sr = out_buffer.sample_rate;
	int d = out_buffer.duration();
	if (modulator.data.empty())
	{
		// No modulator

	}
	else 
	{
		// Modulator presented
		de_assert(modulator.duration() == d, "FMOperator::generate_sound_add - Bad modulator or out_buffer size");
		for (int i = 0; i < d; i++)
		{
			//float amp = FM
		}
	}


}

//--------------------------------------------------------------
