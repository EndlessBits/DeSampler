#include "Sound.h"


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


	int buffer_size = 128;

	settings.setOutListener(this);
	settings.sampleRate = 44100;
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
	INSTR.at_update();
}

//--------------------------------------------------------------
void Sound::audioIn(ofSoundBuffer& input) {
	// TODO currently not works, use separate sound in (specify in settings)
}

//--------------------------------------------------------------
void Sound::update(){


}

//--------------------------------------------------------------
void Sound::draw(const ofRectangle& rect) {


}

//--------------------------------------------------------------
void Sound::set_sound(vector<float>& mono_sample, int sample_rate) {

}

//--------------------------------------------------------------
void Sound::play_sound() {

}

//--------------------------------------------------------------
