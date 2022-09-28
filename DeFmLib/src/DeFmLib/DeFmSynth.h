#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelopes.h"

/*
����������, ��� ������� ���������� ��������� � ���������
X - ����������� �����

7 �����������:
     /X2
   X1
  /  \X3
X0   
  \  /X5
   X4
     \X6


A0*wave(t*(F0
           + A1*wave(t*(F1 + A2*wave(t*F2) + A3*wave(t*F3)))
           + A4*wave(t*(F4 + A5*wave(t*F5) + A6*wave(t*F6)))
           ))

Fi - �������, Ai - ���������, �������� �� ������� ��� ���������,
�� 0 �� 1 - � ��������� � �������, ��� ���������������.

����� ���������:
- � ������ "����" ��� ����� ���� � ����� �������� - ������� ���� �����, ����� ��������.
- � ������ "�������" - ���� �� ����� �������� �����
wave �����������.

*/


class DeFmSynth {
public:
    void setup(DeParams* p);
    vector<float> synth(float duration_ms, int sample_rate, DeEnvelopes* envelopes);

    static const int n_ops = 7; // ����� ���������� � �����������

protected:

    int sample_rate_ = 0;
    float dphase_ = 0;

    DeParams* p_ = nullptr;

    // ��������� ������ �����, -1..1,
    // Phase - ������ ������� ���
    // A, F - ������� �������� � ������ � ��������� 0..1
    float get_sample(float* Phase, const float* A, const float* F);

    float wave(float& phase, float freq);
};

