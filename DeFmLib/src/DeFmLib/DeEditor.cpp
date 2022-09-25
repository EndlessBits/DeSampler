#include "DeEditor.h"

//--------------------------------------------------------------
void DeEditor::setup(DeEnvelopes* envelopes) {
	envelopes_ = envelopes;
	rect_pix_ = ofRectangle(0, 0, 100, 100);

	int n = envelopes_->Amps.size();
	editors_.resize(1+2*n);
	int k = 0;
	for (int i = 0; i < n + 1; i++) {
		if (i == 0) {
			editors_[k].setup_data(DeEditGraphViewType::Pins, &envelopes_->Phases);
			editors_[k].setup_view("Phases", DeEditGraphViewType::Pins, ofRectangle(0.05, 0.05, 0.1, 0.1));
			k++;
		}
		else {
			int j = i - 1;
			string num = ofToString(j + 1);
			editors_[k].setup_data(&envelopes_->Freqs[j].times(), &envelopes_->Freqs[j].values());
			editors_[k].setup_view("Freq " + num, DeEditGraphViewType::Lines, ofRectangle(0.05 + 0.12 * j, 0.20, 0.1, 0.1));
			k++;

			editors_[k].setup_data(&envelopes_->Amps[j].times(), &envelopes_->Amps[j].values());
			editors_[k].setup_view("Amp " + num, DeEditGraphViewType::Lines, ofRectangle(0.05 + 0.12 * j, 0.35, 0.1, 0.1));
			k++;
		}
	}
}

//--------------------------------------------------------------
void DeEditor::save_to_file(const string& file_name) {

}

//--------------------------------------------------------------
void DeEditor::load_from_file(const string& file_name) {

}

//--------------------------------------------------------------
void DeEditor::draw(ofRectangle rect_pix) {
	rect_pix_ = rect_pix;
	for (auto& editor : editors_) {
		editor.draw(rect_pix_);
	}
}


glm::vec2 DeEditor::screen_to_uniform(float x, float y)
{
	return 	glm::vec2(ofMap(x, rect_pix_.x, rect_pix_.getRight(), 0, 1),
		ofMap(y, rect_pix_.y, rect_pix_.getBottom(), 0, 1));
}

//--------------------------------------------------------------
void DeEditor::mouse_moved(int x, int y) {
	auto pos_pix = glm::vec2(x, y);
	bool editing = (editor_);
	for (auto& editor : editors_) {
		editor.mouse_moved(pos_pix, editing);
	}
}

//--------------------------------------------------------------
bool DeEditor::mouse_pressed(int x, int y) {
	auto pos_pix = glm::vec2(x,y);
	for (auto &editor: editors_) {
		if (editor.mouse_pressed(pos_pix)) {
			editor_ = &editor;
			return true;
		}
	}
	return false;	
}

//--------------------------------------------------------------
void DeEditor::mouse_dragged(int x, int y) {
	if (editor_) {
		editor_->mouse_dragged(glm::vec2(x, y));
	}
}

//--------------------------------------------------------------
void DeEditor::mouse_released(int x, int y) {
	if (editor_) {
		editor_->mouse_released(glm::vec2(x, y));
		editor_ = nullptr;
	}
}

//--------------------------------------------------------------
