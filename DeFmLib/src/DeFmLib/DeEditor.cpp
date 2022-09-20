#include "DeEditor.h"

//--------------------------------------------------------------
void DeEditor::setup(DeEnvelopes* envelopes) {
	envelopes_ = envelopes;
	rect_ = ofRectangle(0, 0, 100, 100);
}

//--------------------------------------------------------------
void DeEditor::save_to_file(const string& file_name) {

}

//--------------------------------------------------------------
void DeEditor::load_from_file(const string& file_name) {

}

//--------------------------------------------------------------
void DeEditor::draw(ofRectangle rect) {
	rect_ = rect;
}


glm::vec2 DeEditor::screen_to_uniform(float x, float y)
{
	return 	glm::vec2(ofMap(x, rect_.x, rect_.getRight(), 0, 1), 
		ofMap(y, rect_.y, rect_.getBottom(), 0, 1));
}

//--------------------------------------------------------------
void DeEditor::mouse_moved(int x, int y) {

}

//--------------------------------------------------------------
bool DeEditor::mouse_pressed(int x, int y) {
	auto pos = screen_to_uniform(x, y);
	for (auto &editor: editors_) {
		if (editor.mouse_pressed(pos)) {
			editor_ = &editor;
			return true;
		}
	}
	return false;	
}

//--------------------------------------------------------------
void DeEditor::mouse_dragged(int x, int y) {
	if (editor_) {
		editor_->mouse_dragged(screen_to_uniform(x, y));
	}
}

//--------------------------------------------------------------
void DeEditor::mouse_released(int x, int y) {
	if (editor_) {
		editor_->mouse_released(screen_to_uniform(x, y));
		editor_ = nullptr;
	}
}

//--------------------------------------------------------------
