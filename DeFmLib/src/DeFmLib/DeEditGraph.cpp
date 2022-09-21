#include "DeEditGraph.h"

//--------------------------------------------------------------
// rect 0..1
void DeEditGraph::setup_view(const string& title, ofRectangle rect) {
	title_ = title;
	rect_ = rect;
}

//--------------------------------------------------------------
void DeEditGraph::setup_data(const vector<float>* times, vector<float>* values) {
	ptimes_ = times;
	pvalues_ = values;
}

//--------------------------------------------------------------
// times ставятся равномерно
void DeEditGraph::setup_data(vector<float>* values) {
	// Создаем times_intermal_
	DeEnvelopeParams params;
	params.type = DeEnvelopeType::Equidistant;
	params.size = values->size();
	times_internal_ = DeEnvelope::generate_times(params);

	ptimes_ = &times_internal_;
	pvalues_ = values;
}

//--------------------------------------------------------------
void DeEditGraph::draw(const ofRectangle& global_rect_pix) {
	auto& glob = global_rect_pix;
	rect_pix_.x = ofLerp(glob.x, glob.getRight(), rect_.x);
	rect_pix_.y = ofLerp(glob.y, glob.getRight(), rect_.y);
	rect_pix_.width = ofLerp(0, glob.width, rect_.width);
	rect_pix_.height = ofLerp(0, glob.height, rect_.height);

	ofSetColor(255);
	ofNoFill();
	ofDrawRectangle(rect_pix_);
}

//--------------------------------------------------------------
void DeEditGraph::mouse_moved(const glm::vec2 &pos) {

}

//--------------------------------------------------------------
bool DeEditGraph::mouse_pressed(const glm::vec2& pos) {

	return false;	// TODO
}

//--------------------------------------------------------------
void DeEditGraph::mouse_dragged(const glm::vec2& pos) {

}

//--------------------------------------------------------------
void DeEditGraph::mouse_released(const glm::vec2& pos) {

}

//--------------------------------------------------------------
