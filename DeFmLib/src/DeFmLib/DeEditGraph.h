#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// �������� ������ ������� - ����� ����������� ��� �������������� ���������, � ����� ��������� ���
class DeEditGraph {
public:
	void setup_view(const string& title, ofRectangle rect);	// rect 0..1
	void setup_data(const vector<float>* times, vector<float>* values);
	void setup_data(vector<float>* values);	// times �������� ����������

	void draw();
	void mouse_moved(const glm::vec2& pos);  // x,y 0..1
	bool mouse_pressed(const glm::vec2& pos);
	void mouse_dragged(const glm::vec2& pos);
	void mouse_released(const glm::vec2& pos);
protected:
	string title_;
	ofRectangle rect_;

	vector<float> times_internal_;	// ��� ������ ����� ������ ������ values
	const vector<float>* ptimes_ = nullptr;
	vector<float>* pvalues_ = nullptr;
};
