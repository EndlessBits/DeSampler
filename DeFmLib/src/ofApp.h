#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelopes.h"
#include "DeEditor.h"
#include "DeFmSynth.h"
#include "Sound.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	string title_;

	DeParams params_;			// ��������� ����������� 0..1 � ��������� � �������
	DeEnvelopes envelopes_;		// ��������� �����������
	DeEditor editor_;			// �������� ���������
	DeFmSynth synth_;			// ����������, ��� ������� ���������� ��������� � ���������

	void load_preset(int i = -1);
	void save_preset(int i = -1);
	int preset_ = -1;
	
	Sound sound_;
	void play_sound();			// ������������� � ������������� ����
};
