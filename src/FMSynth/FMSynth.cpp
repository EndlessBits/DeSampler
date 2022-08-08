#include "FMSynth.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"
#include <numeric>


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
void FMSynth::setup(FMShared shared, vector<float> durations_ms, vector<FMFragment> fragments){
	de_assert(!durations_ms.empty(), "FMSynth::setup - array durations_ms is empty");
	de_assert(!fragments.empty(), "FMSynth::setup - array fragments is empty");
	de_assert(durations_ms.size() == fragments.size(), "FMSynth::setup - arrays durations_ms and fragments have different sizes");

	shared_ = shared;
	durations_ms_ = durations_ms;
	fragments_ = fragments;

	size_ = durations_ms.size();
	duration_ms_ = accumulate(durations_ms_.begin(), durations_ms_.end(), 0);
}

//--------------------------------------------------------------
int FMSynth::get_duration(int i, int sr)
{
	return ofxSoundUtils::ms_to_samples(durations_ms_[i], sr);
}

//--------------------------------------------------------------
int FMSynth::get_duration(int sr)
{
	return ofxSoundUtils::ms_to_samples(duration_ms_, sr);
}

//--------------------------------------------------------------
void FMSynth::allocate_buffers(int sr)
{
	for (int i = 0; i < size_; i++)
	{
		fragments_[i].allocate_buffers(get_duration(i, sr));
	}
	out_buffer_.allocate(get_duration(sr));
}

//--------------------------------------------------------------
// It's expected that sample rate is set
void FMSynth::render_sound()
{
	de_assert(!out_buffer_.empty(), "FMSynth::render_sound - need to call allocate_buffers");
	int sr = out_buffer_.sample_rate;
	int offset = 0;
	
	// Clear buffer
	out_buffer_.fill_zero();

	// Render
	for (int i=0; i<size_; i++)
	{
		auto& f = fragments_[i];
		auto d = ofxSoundUtils::ms_to_samples(durations_ms_[i], sr);
		f.render_sound(out_buffer_, offset, d);
		offset += d;
	}

}

//--------------------------------------------------------------
void FMSynth::test_topology()
{
	cout << "Test topology" << endl;

	setup({ 1, 5000, 0, 1 },	// Shared freq0,1 vol0,1
		{ 1000 },				// Durations
		{	// Fragments
			FMFragment( &shared_, { -1 }, { 
				FMOperator(&shared_, FMOperatorWave::Sine, {440, 660}, {0.5, 0.5}) 
			})
		}
		);

}

//--------------------------------------------------------------
void FMSynth::test_generation()
{
	cout << "Test generation" << endl;

	int sr = 44100;
	allocate_buffers(sr);
	render_sound();

}

//--------------------------------------------------------------
