#pragma once

#include "ofMain.h"
#include "Types.h"

struct UIClass {
	void setup();

	// x, y - position in buttons
	void draw_button(glm::int2 pos0, int x, int y, string title, int state);
};

extern UIClass UI;