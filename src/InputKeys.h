#pragma once

#include "ofMain.h"
#include "Types.h"
#include "KeyboardLayout.h"

/*
From Microsoft GDK docs:
Standard keyboards can only report four to six key presses at a time, 
and even high-end gaming keyboards rarely support more than 12-16 keys at once.

Virtual key codes:
https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
*/


// Keyboard events:

struct KeyDescr {
	KeyType type = KeyTypeUnknown;
	int index = 0;
};

struct KeyEvent {
	KeyDescr key;
	int8 state;
};

struct KeyboardState {
	KeyboardState() {
		reset();
	}
	void reset() {
		state = vector<int8>(KeysCount);
	}
	vector<int8> state;
};


class InputKeys {
public:
	void setup();
	void close();

	vector<KeyEvent> get_events();	// Compute current events

	void update();
	int get_key_VK(int i);	// Convert key index to virtual keyboard index, -1 means unknown
		
protected:
	KeyboardState state_;
	vector<KeyEvent> events_;

	void setup_key_vk();
	vector<int> key_vk_;		// VK numbers of all used keys

	KeyDescr key_index_to_descr(int i);
};

extern InputKeys INPUT_KEYS;