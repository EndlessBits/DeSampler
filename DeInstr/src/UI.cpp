#include "UI.h"

#include "gui_generated.h"
#include "ofxWindows.h"

extern ofxKuTextGui gui;	//access to GUI object

UIClass UI;

//--------------------------------------------------------------
void UIClass::setup() {
	const int font_size = 16;
	font_.load("fonts/verdana.ttf", font_size);
}

//--------------------------------------------------------------
// x, y - position in buttons
void UIClass::draw_button(glm::int2 pos0, int x, int y, string title, int state) {
	const float x0 = 100;
	const float y0 = 100;
	const float w1 = 80;
	const float h1 = 70;
	const float spacex = 30;
	const float spacey = 30;
	const float font_y = -3;

	float X = x0 + (w1 + spacex) * (pos0.x + x);
	float Y = y0 + (h1 + spacey) * (pos0.y + y);

	if (state) {
		ofSetColor(200,200,100);
		ofFill();
		ofDrawRectangle(X, Y, w1, h1);
	}

	ofSetColor(255);
	ofNoFill();
	ofDrawRectangle(X, Y, w1, h1);
	font_.drawString(title, X, Y + font_y);
	
}

//--------------------------------------------------------------
