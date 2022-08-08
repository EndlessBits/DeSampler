#include "FMFragment.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"
#include "Sound.h"


extern ofxKuTextGui gui;	//access to GUI object
	
//--------------------------------------------------------------
FMFragment::FMFragment(FMShared* shared, const vector<int>& connections, const vector<FMOperator>& operators)
{
	setup(shared, connections, operators);
}

//--------------------------------------------------------------
void FMFragment::setup(FMShared* shared, const vector<int>& connections, const vector<FMOperator>& operators)
{
	de_assert(connections.size() == operators.size(), "FMFragment::setup - connections and operators sizes are different");
	de_assert(!connections.empty(), "FMSynth::create_topology - empty topology");
	de_assert(connections.back() == -1, "FMSynth::create_topology - at least last index must be -1 for audio output");
	size_ = connections.size();
	connections_ = connections;

	operators_ = operators;
}

//--------------------------------------------------------------
void FMFragment::allocate_buffers(int max_duration)
{
	// TODO can optimize by not clearing not used buffers
	de_assert(max_duration_ > 0, "FMFragment::allocate_buffers - bad max_duration");
	de_assert(size_ > 0, "FMFragment::allocate_buffers - fragment is not inited");

	buffers_.resize(size_);
	for (auto& b : buffers_)
	{
		b.allocate(max_duration);
	}
}

//--------------------------------------------------------------
void FMFragment::clear_buffers()
{
	// TODO can optimize by not clearing not used buffers
	for (auto& b : buffers_)
	{
		b.fill_zero();
	}
}

//--------------------------------------------------------------
// It's expected that memory for out_buffer is allocated and set its sample_rate,
// and allocate_buffers are called
void FMFragment::render_sound(SoundSample& out_buffer, size_t offset, size_t duration)
{
	de_assert(size_ > 0, "FMFragment::render_sound - fragment is not inited");
	de_assert(max_duration_ > 0 && size_ == buffers_.size(), "FMFragment::render_sound - need to call allocate_buffers");
	de_assert(duration <= max_duration_, "FMFragment::render_sound - max_duration is too small");
	de_assert(offset + duration <= out_buffer.data.size(), "FMFragment::render_sound - allocated sample length inconsistency");

	int sr = out_buffer.sample_rate;
	
	clear_buffers();	
	for (int i = 0; i < size_; i++)
	{
		int write_index = connections_[i];
		SoundSampleType* modulator_data = buffers_[i].data_ptr();	// TODO optimize - if not used, put nullptr
		SoundSampleType* output_data = (write_index >= 0) ? buffers_[write_index].data_ptr() : (out_buffer.data_ptr() + offset);
		operators_[i].render_sound_add(modulator_data, output_data, sr, duration);
	}
}

//--------------------------------------------------------------
