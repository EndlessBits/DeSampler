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
void DeEditGraph::mouse_moved(int x, int y) {

}

//--------------------------------------------------------------
bool DeEditGraph::mouse_pressed(int x, int y) {

	return false;	// TODO
}

//--------------------------------------------------------------
void DeEditGraph::mouse_dragged(int x, int y) {

}

//--------------------------------------------------------------
void DeEditGraph::mouse_released(int x, int y) {

}

//--------------------------------------------------------------
