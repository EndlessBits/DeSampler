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
const int PadsCountY = 3;
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
// https://snipp.ru/handbk/vk-code
const int KeysVK[KeysCount] = {
		// Pads
		'Q','W','E','R','T','Y','U','I',//'O','P',
		'A','S','D','F','G','H','J','K',//'L',VK_OEM_1,
		'Z','X','C','V','B','N','M',VK_OEM_COMMA,//VK_OEM_PERIOD,VK_OEM_2,
		// Instruments
		'1', '2', '3',
		// Complexity
		'4', '5', '6',
		// Control
		VK_SPACE		//Rec sample
	};

// Titles and positions

const glm::int2 PadCorner = glm::int2(0, 2);
const glm::int2 InstrCorner = glm::int2(0, 0);
const glm::int2 ComplexityCorner = glm::int2(4, 0);
const glm::int2 ControlCorner = glm::int2(0, 1);

const string PadBanksTitles[PadsCountY] = { "A","B","C" };
const string InstrTitles[InstrCount] = { "Tone", "Drum", "Sample" };
const string ComplexityTitles[ComplexityCount] = { "Pure", "Soft", "Natural" };
const string ControlTitles[ControlCount] = { "Rec Sample" };
