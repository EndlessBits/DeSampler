#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// ��� ����������� �������
enum class DeEditGraphViewType {
	Lines = 0,
	Pins = 1
};

// �������� ������ ������� - ����� ����������� ��� �������������� ���������, � ����� ��������� ���
class DeEditGraph {
public:
	void setup_view(const string& title, DeEditGraphViewType view_type, ofRectangle rect);	// rect 0..1
	void setup_data(const vector<float>* times, vector<float>* values);
	void setup_data(DeEditGraphViewType time_view_type, vector<float>* values);	// times �������� ���������� � ����������� �� ����

	void draw(const ofRectangle &global_rect_pix);
	void mouse_moved(const glm::vec2& pos_pix, bool editing);  
	bool mouse_pressed(const glm::vec2& pos_pix);
	void mouse_dragged(const glm::vec2& pos_pix);
	void mouse_released(const glm::vec2& pos_pix);
protected:
	// ������ ������������ ���� �� �����
	static const int mouse_rad_pix = 7; //5; 

	string title_;
	DeEditGraphViewType view_type_;
	ofRectangle rect_;

	ofRectangle rect_pix_;	// ������������ ��� ������ ����� ���������

	vector<float> times_internal_;	// ��� ������ ����� ������ ������ values, �� ������������ ��� Pins
	const vector<float>* ptimes_ = nullptr;
	vector<float>* pvalues_ = nullptr;
	int n_ = 0;

	// �����, ��� ������� �������� ����
	int mouse_over_index_ = -1;

	// ������������� �����
	int edit_index_ = -1;
	float edit_delta_y_ = 0;

	// ����������� ����������
	bool edit_by_drawing_ = false;

	glm::vec2 internal_to_pix(const glm::vec2 &p);
	float pix_to_internal(float y);	// ������������ ��� ��������������
		
	// ���������� �����
	glm::vec2 point_pix(int i);

	// ������� ������������� ��� ����
	ofRectangle mouse_rect_pix(int i);
};
