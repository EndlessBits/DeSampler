#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"

/*
X - ����������� �����

7 �����������:
X2\
  X1
X3/  \
     X0
X5\  /
  X4
X6/


A0*wave(t*(F0
           + A1*wave(t*(F1 + A2*wave(t*F2) + A3*wave(t*F3)))
           + A4*wave(t*(F4 + A5*wave(t*F5) + A6*wave(t*F6)))
           ))

Fi - �������, Ai - ���������, �������� �� ������� ��� ��������,
�� 0 �� 1 - � ��������� � �������, ��� ���������������.

����� �������� ������� ���� �����, ����� ��������.

wave ���������� � 1, �����������.


*/


class DeFmSynth {
public:
    static const int n = 7;
    // ��������� ������ �����, -1..1,
    // A, F - ������� �������� � ������ � ��������� 0..1
    float get_sample(float t, float* A, float* F, DeParams *p);

};

