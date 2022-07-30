#pragma once

#include "ofMain.h"
#include "Types.h"

// Keyboard layout

enum KeyType: int {
	KeyTypeUnknown = -1,
	KeyTypePad = 0,
	KeyTypeInstr = 1,
	KeyTypeComplexity = 2,
	KeyTypeControl = 3
};

const int PadsCols = 8;
const int PadsRows = 4;
const int PadsCount = PadsCols * PadsRows;

const int InstrCount = 4;
const int ComplexityCount = 4;

enum KeyControlType : int {
	KeyControlRecSample = 0,
	ControlCount = 1
};

const int8 KeyIndexPads = 0;
const int8 KeyIndexInstr = PadsCount;
const int8 KeyIndexComplexity = PadsCount + InstrCount;
const int8 KeyIndexControl = PadsCount + InstrCount + ComplexityCount;
const int8 KeysCount = PadsCount + InstrCount + ComplexityCount + ControlCount;
