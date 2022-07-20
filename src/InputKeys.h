#pragma once

#include "ofMain.h"

/*
From Microsoft GDK docs:
Standard keyboards can only report four to six key presses at a time, 
and even high-end gaming keyboards rarely support more than 12-16 keys at once.

Virtual key codes:
https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

*/

class InputKeys {
public:
	void setup();
	void close();

	void update();
	void draw();

};

extern InputKeys INPUT_KEYS;