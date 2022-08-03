#include "Sound.h"

#include "gui_generated.h"
#include "InputKeys.h"
#include "UI.h"
#include "Instrument.h"


extern ofxKuTextGui gui;	//access to GUI object
Sound SOUND;

//--------------------------------------------------------------
void Sound::setup() {
	//sound_stream.printDeviceList();
	auto devices = sound_stream.getDeviceList(ofSoundDevice::Api::MS_DS);
	cout << devices << endl;
	de_assert(!devices.empty(), "No sound devices");

	ofSoundStreamSettings settings;
	settings.setInDevice(devices[0]);
	settings.setOutDevice(devices[0]);

	// settings.api = ofSoundDevice::Api::PULSE;
	//auto devices = sound_stream.getMatchingDevices("default");


	int buffer_size = 128;

	settings.setOutListener(this);
	settings.sampleRate = 44100;
	settings.numOutputChannels = 2;
	settings.numInputChannels = 2;
	settings.bufferSize = buffer_size;
	sound_stream.setup(settings);

}

//--------------------------------------------------------------
void Sound::exit() {
	sound_stream.close();
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
void Sound::draw() {


}

//--------------------------------------------------------------
