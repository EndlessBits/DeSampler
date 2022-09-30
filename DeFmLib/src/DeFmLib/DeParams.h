#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"

// ѕараметры конвертации 0..1 в амплидуту и частоту
struct DeParamsSettings {
	float midi_note0 = 21;
	float midi_note1 = 108;
	float db0 = -40;
	float db1 = 0;
	float mi0 = 0;
	float mi1 = 10;
};


class DeParams {
public:
	DeParams() {}
	void setup(const DeParamsSettings &settings);

	// Conversions
	/// db to amp, 0..1->0..1
	float d2a(float x);
	/// linear to frequency, 0..1->Hz
	float l2f(float x);

	/// 0..1 в индекс модул€ции (modulation index)
	float mi(float x);

	// “реугольна€ волна
	// phase 0..1
	float wave(float phase);
protected:
	// Ranges
	DeParamsSettings s_;

	float midi_delta_ = 0;

	float db_delta_ = 0;
	float db_k_ = 1;
	float db_a_ = 0;
	inline float db_to_amp_raw(float db);

	float mi_a_ = 0;
	float mi_k_ = 1;

};
