#pragma once

#include "ofMain.h"

class App {
public:
	void setup();
	void exit();
	void update();
	void draw();

	void keyPressed(int key);

	float time0_ = 0;
};
