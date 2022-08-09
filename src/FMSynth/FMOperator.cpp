#include "FMOperator.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
FMOperator::FMOperator(FMShared* shared, FMWaveformShape shape, const FMLinearRamp& freq_ramp, const FMLinearRamp& vol_ramp)
{
	setup(shared, shape, freq_ramp, vol_ramp);
}

//--------------------------------------------------------------
void FMOperator::setup(FMShared* shared, FMWaveformShape shape, const FMLinearRamp& freq_ramp, const FMLinearRamp& vol_ramp)
{
	de_assert(shared, "FMOperator::setup - shared == nullptr");

	shared_ = shared;
	shape_ = shape;
	freq_ramp_ = freq_ramp;
	vol_ramp_ = vol_ramp;
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
		float phase = 0;
		float phase_shift1Hz = ofxSoundUtils::sample_rate_to_phase_shift(sr);
		for (int i = 0; i < duration; i++)
		{
			float vol = shared_->ramp_to_volume(vol_ramp_.value(i, duration)); // Volume ramp
			float freq = shared_->ramp_to_freq(freq_ramp_.value(i, duration)); // Frequency ramp 
			freq += modulator[i];		// Frequency modulation
			float phase_shift = phase_shift1Hz * freq;	// TODO may use integer arithmetics, see Endless Synth
			out_buffer[i] += vol * shared_->wavetable_unsafe(phase, shape_);
			phase += phase_shift;
		}
	}


}

//--------------------------------------------------------------
