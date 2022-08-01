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

const int PadsCountX = 8;
const int PadsCountY = 4;
const int PadsCount = PadsCountX * PadsCountY;

const int InstrCount = 3;
const int ComplexityCount = 3;

enum KeyControlType : int {
	KeyControlRecSample = 0,
	ControlCount = 1
};

const int8 KeyIndexPads = 0;
const int8 KeyIndexInstr = PadsCount;
const int8 KeyIndexComplexity = PadsCount + InstrCount;
const int8 KeyIndexControl = PadsCount + InstrCount + ComplexityCount;
const int8 KeysCount = PadsCount + InstrCount + ComplexityCount + ControlCount;

// Key codes
// https://docs.microsoft.com/ru-ru/windows/win32/inputdev/virtual-key-codes
const int KeysVK[KeysCount] = {
		// Pads
		'1','2','3','4','5','6','7','8',
		'Q','W','E','R','T','Y','U','I',
		'A','S','D','F','G','H','J','K',
		'Z','X','C','V','B','N','M',',',
		// Instruments
		VK_F5, VK_F6, VK_F7, 
		// Complexity
		VK_F1, VK_F2, VK_F3,
		// Control
		VK_SPACE		//Rec sample
	};

// Titles and positions

const glm::int2 PadCorner = glm::int2(0, 2);
const glm::int2 InstrCorner = glm::int2(5, 0);
const glm::int2 ComplexityCorner = glm::int2(0, 0);
const glm::int2 ControlCorner = glm::int2(0, 1);

const string PadBanksTitles[PadsCountY] = { "A","B","C","D" };
const string InstrTitles[InstrCount] = { "Tone", "Drum", "Sample" };
const string ComplexityTitles[ComplexityCount] = { "Pure", "Soft", "Natural" };
const string ControlTitles[ControlCount] = { "Rec Sample" };
