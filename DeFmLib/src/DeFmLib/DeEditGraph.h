#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelope.h"

// Тип отображения графика
enum class DeEditGraphViewType {
	Lines = 0,
	Bars = 1
};

// Редактор одного графика - может применяться для редактирования огибающих, а также начальных фаз
class DeEditGraph {
public:
	void setup_view(const string& title, DeEditGraphViewType view_type, ofRectangle rect);	// rect 0..1
	void setup_data(const vector<float>* times, vector<float>* values);
	void setup_data(DeEditGraphViewType time_view_type, vector<float>* values);	// times ставятся равномерно в зависимости от типа

	void draw(const ofRectangle &global_rect_pix);
	void mouse_moved(const glm::vec2& pos_pix);  
	bool mouse_pressed(const glm::vec2& pos_pix);
	void mouse_dragged(const glm::vec2& pos_pix);
	void mouse_released(const glm::vec2& pos_pix);
protected:
	static const int mouse_rad_pix = 5;

	string title_;
	DeEditGraphViewType view_type_;
	ofRectangle rect_;

	ofRectangle rect_pix_;	// Выставляется при каждом кадре рисования

	vector<float> times_internal_;	// для случая когда заданы только values, не используется при Bars
	const vector<float>* ptimes_ = nullptr;
	vector<float>* pvalues_ = nullptr;
	int n_ = 0;

	// Редактируемая точка
	int edit_index_ = -1;
	glm::vec2 edit_pos_;

	glm::vec2 internal_to_pix(const glm::vec2 &p);
		
	// Координаты точки
	glm::vec2 point_pix(int i);

	// Область распознавания для мыши
	ofRectangle mouse_rect_pix(int i);
};
