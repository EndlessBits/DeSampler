#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelopes.h"
#include "DeEditGraph.h"

// Редактор огибающих

class DeEditor {
public:
	void setup(DeEnvelopes* envelopes);
	void draw(ofRectangle rect_pix);
	void mouse_moved(int x, int y);
	bool mouse_pressed(int x, int y);
	void mouse_dragged(int x, int y);
	void mouse_released(int x, int y);

protected:
	DeEnvelopes* envelopes_ = nullptr;
	ofRectangle rect_pix_;		// Прямоугольник для последнего рисования, используется для вычислений с мышью

	vector<DeEditGraph> editors_;
	DeEditGraph* editor_ = nullptr;	// Текущий редактируемый график

	glm::vec2 screen_to_uniform(float x, float y);

	
};
