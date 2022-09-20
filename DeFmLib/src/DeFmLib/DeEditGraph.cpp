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
void DeEditGraph::draw() {

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
