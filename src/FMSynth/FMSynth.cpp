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
// It's expected that sample rate is set
void FMSynth::generate_sound(SoundSample& out_buffer)
{
	int sr = out_buffer.sample_rate;
	de_assert(sr > 0, "FMSynth::generate_sound - bad sample rate");
	int offset = 0;
	int d = ofxSoundUtils::ms_to_samples(duration_ms_, sr);
	out_buffer.allocate(d);
	for (int i=0; i<size_; i++)
	{
		auto& f = fragments_[i];
		auto d = ofxSoundUtils::ms_to_samples(durations_ms_[i], sr);
		f.allocate_buffers(d);		// TODO for multiple generation can allocate it once
		f.generate_sound(out_buffer, offset, d);
		offset += d;
	}

}

//--------------------------------------------------------------
void FMSynth::test_topology()
{
	cout << "Test topology" << endl;

	FMShared shared({ 1, 5000, 0, 1 });
	vector<FMFragment> frags(1);
	{
		auto& f = frags[0];
		f.setup(&shared, { 1000 }, { FMOperator(&shared, FMOperatorWave::Sine, {440, 660}, {0.5, 0.5}) });

	}


}

//--------------------------------------------------------------
void FMSynth::test_generation()
{
	cout << "Test generation" << endl;

}

//--------------------------------------------------------------
