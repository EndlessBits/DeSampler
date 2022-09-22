#include "DeEditGraph.h"

//--------------------------------------------------------------
// rect 0..1
void DeEditGraph::setup_view(const string& title, DeEditGraphViewType view_type, ofRectangle rect) {
	title_ = title;
	view_type_ = view_type;
	rect_ = rect;
}

//--------------------------------------------------------------
void DeEditGraph::setup_data(const vector<float>* times, vector<float>* values) {
	de_assert(times->size() == values->size(), "DeEditGraph::setup_data - different sizes");
	ptimes_ = times;
	pvalues_ = values;
	n_ = pvalues_->size();
}

//--------------------------------------------------------------
// times ставятся равномерно
void DeEditGraph::setup_data(DeEditGraphViewType time_view_type, vector<float>* values) {
	// Создаем times_internal_
	DeEnvelopeParams params;
	params.size = values->size();
	switch (time_view_type) {
	case DeEditGraphViewType::Lines: 
		params.type = DeEnvelopeType::Equidistant;
		break;
	case DeEditGraphViewType::Bars:
		params.type = DeEnvelopeType::EquidistantBars;
		break;
	default: de_exception("DeEditGraph::setup_data - bad time_view_type")
	}
	times_internal_ = DeEnvelope::generate_times(params);

	ptimes_ = &times_internal_;
	pvalues_ = values;
	n_ = pvalues_->size();
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
void DeEditGraph::mouse_moved(const glm::vec2& pos_pix) {

}

//--------------------------------------------------------------
glm::vec2 DeEditGraph::internal_to_pix(const glm::vec2& p) {
	return glm::vec2(rect_pix_.x + p.x * rect_pix_.width,
		rect_pix_.y + p.y * rect_pix_.height);
}

//--------------------------------------------------------------
// Координаты точки
glm::vec2 DeEditGraph::point_pix(int i) {
	return internal_to_pix(glm::vec2((*ptimes_)[i], (*pvalues_)[i]));
	auto& t = *ptimes_;
}

//--------------------------------------------------------------
// Область распознавания для мыши
ofRectangle DeEditGraph::mouse_rect_pix(int i) {
	glm::vec2 p = point_pix(i);
	switch (view_type_) {
	case DeEditGraphViewType::Lines:
		return ofRectangle(p.x - mouse_rad_pix, p.y - mouse_rad_pix,
			2 * mouse_rad_pix + 1, 2 * mouse_rad_pix + 1);
	case DeEditGraphViewType::Bars:
		return ofRectangle(p.x - mouse_rad_pix, p.y - mouse_rad_pix,
			2 * mouse_rad_pix + 1, 2 * mouse_rad_pix + 1);
	default:
		de_exception("DeEditGraph::mouse_area_pix - bad view_type");
		return ofRectangle(0, 0, 1, 1);
	}
}

//--------------------------------------------------------------
bool DeEditGraph::mouse_pressed(const glm::vec2& pos_pix) {
	for (int i = 0; i < n_; i++) {
		if (mouse_rect_pix(i).inside(pos_pix)) {
			edit_index_ = i;
			edit_pos_ = pos_pix;
			return true;
		}
	}
	return false;	
}

//--------------------------------------------------------------
void DeEditGraph::mouse_dragged(const glm::vec2& pos_pix) {
	if (edit_index_ >= 0) {
		// TODO
	}
}

//--------------------------------------------------------------
void DeEditGraph::mouse_released(const glm::vec2& pos_pix) {
	mouse_dragged(pos_pix);
	if (edit_index_ >= 0) {
		edit_index_ = -1;
	}
}

//--------------------------------------------------------------
