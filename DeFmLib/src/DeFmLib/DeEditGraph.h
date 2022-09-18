#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// �������� �������� - ����� ����������� ��� �������������� ���������, � ����� ��������� ���
class DeEditGraph {
public:
	void setup_view(const string& title, ofRectangle rect);	// rect 0..1
	void setup_data(const vector<float>* times, vector<float>* values);
	void setup_data(vector<float>* values);	// times �������� ����������

	void draw();
	void mouse_moved(int x, int y);
	bool mouse_pressed(int x, int y);
	void mouse_dragged(int x, int y);
	void mouse_released(int x, int y);
protected:
	string title_;
	ofRectangle rect_;

	vector<float> times_internal_;	// ��� ������ ����� ������ ������ values
	const vector<float>* ptimes_ = nullptr;
	vector<float>* pvalues_ = nullptr;
};
