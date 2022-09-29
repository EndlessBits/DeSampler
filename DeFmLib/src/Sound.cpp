#include "Sound.h"
#include "DeTypesAssert.h"


//--------------------------------------------------------------
void Sound::setup() {
	//sound_stream_.printDeviceList();
	auto devices = sound_stream_.getDeviceList(ofSoundDevice::Api::MS_DS);
	cout << devices << endl;
	de_assert(!devices.empty(), "No sound devices");

	ofSoundStreamSettings settings;
	settings.setInDevice(devices[0]);
	settings.setOutDevice(devices[0]);

	// settings.api = ofSoundDevice::Api::PULSE;
	//auto devices = sound_stream_.getMatchingDevices("default");


	stream_sr_ = 22050;

	int buffer_size = 128;

	settings.setOutListener(this);
	settings.sampleRate = stream_sr_;
	settings.numOutputChannels = 2;
	settings.numInputChannels = 2;
	settings.bufferSize = buffer_size;
	sound_stream_.setup(settings);

}

//--------------------------------------------------------------
void Sound::exit() {
	sound_stream_.close();
}

//--------------------------------------------------------------
void Sound::audioOut(ofSoundBuffer& output) {
	if (playing_) {
		const float volume = 0.6f;
		for (int i = 0; i < output.getNumFrames(); i++) {
			float value = (play_pos_++ < mono_sound_.size()) ? mono_sound_[i] : 0;
			value *= volume;
			output.getSample(i, 0) = value;
			output.getSample(i, 1) = value;

		}
		if (play_pos_ >= mono_sound_.size()) {
			play_pos_ = int(mono_sound_.size()) - 1;
			playing_ = 0;
		}
	}
}

//--------------------------------------------------------------
void Sound::audioIn(ofSoundBuffer& input) {
	// TODO currently not works, use separate sound in (specify in settings)
}

//--------------------------------------------------------------
void Sound::update() {


}

//--------------------------------------------------------------
void Sound::draw(const ofRectangle& rect_pix) {
	ofSetColor(200);
	ofSetColor(160);
	ofNoFill();
	ofDrawRectangle(rect_pix);

	int n = mono_sound_.size();
	if (n > 0) {
		float x0 = rect_pix.x;
		float y0 = rect_pix.y;
		int w = rect_pix.width;
		float h2 = rect_pix.height / 2;

		ofSetColor(255);
		for (int i = 0; i < w; i++) {
			float v = mono_sound_[(i * n) / w] * h2;
			ofDrawLine(x0 + i, y0 + h2, x0 + i, y0 + h2 - v);
		}
	}

}

//--------------------------------------------------------------
void Sound::set_sound(vector<float>& mono_sound, int sample_rate) {
	mono_sound_ = mono_sound;
	sound_sr_ = sample_rate;
}

//--------------------------------------------------------------
void Sound::play_sound() {
	if (!mono_sound_.empty()) {
		play_pos_ = 0;
		playing_ = 1;
	}
}

//--------------------------------------------------------------
