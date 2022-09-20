#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"

// Параметры конвертации 0..1 в амплидуту и частоту

class DeParams {
public:
	DeParams() {}
	void setup(float midi_note0, float midi_note1, float db0, float db1);

	// Conversions
	/// db to amp, 0..1->0..1
	float d2a(float x);	
	/// linear to frequency, 0..1->Hz
	float l2f(float x);	

	// Треугольная волна
	// phase 0..1
	float wave(float phase);
protected:
	// Ranges
	float midi_note0 = 21;
	float midi_note1 = 108;
	float db0 = -40;
	float db1 = 0; 
	
	float midi_delta_ = 0;
	float db_delta_ = 0;
	float db_k_ = 1;
	float db_a_ = 0;
	inline float db_to_amp_raw(float db);

};
