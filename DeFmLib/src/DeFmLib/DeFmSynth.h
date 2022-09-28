#pragma once

#include "ofMain.h"
#include "DeTypesAssert.h"
#include "DeParams.h"
#include "DeEnvelopes.h"

/*
Синтезатор, для синтеза использует параметры и огибающие
X - Треугольная волна

7 генераторов:
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

Fi - частоты, Ai - амплитуды, меняются по времени как огибающие,
от 0 до 1 - и громкость и частота, оба логарифмические.

Точки огибающих:
- у режима "звук" для одной ноты и звука барабана - вначале идут часто, потом медленно.
- у режима "сложный" - идут до конца довольно часто
wave треугольная.

*/


class DeFmSynth {
public:
    void setup(DeParams* p);
    vector<float> synth(float duration_ms, int sample_rate, DeEnvelopes* envelopes);

    static const int n_ops = 7; // число операторов в синтезаторе

protected:

    int sample_rate_ = 0;
    float dphase_ = 0;

    DeParams* p_ = nullptr;

    // Генерация сэмпла звука, -1..1,
    // Phase - массив текущих фаз
    // A, F - массивы амплитуд и частот в диапазоне 0..1
    float get_sample(float* Phase, const float* A, const float* F);

    float wave(float& phase, float freq);
};

