#include "DeFmSynth.h"


/*
A0*wave(t*(F0
           + A1*wave(t*(F1 + A2*wave(t*F2) + A3*wave(t*F3)))
           + A4*wave(t*(F4 + A5*wave(t*F5) + A6*wave(t*F6)))
           ))
*/

//--------------------------------------------------------------
// Генерация сэмпла звука, -1..1,
// A, F - массивы амплитуд и частот в диапазоне 0..1

#define AA(i) p->d2a(A[i])
#define FF(i) p->l2f(F[i])
#define WAVE(f) p->wave(t*(f))


float DeFmSynth::get_sample(float t, float* A, float* F, DeParams* p) {
    return AA(0) * WAVE(FF(0) 
                        + AA(1) * WAVE(FF(1) + AA(2) * WAVE(FF(2)) + AA(3) * WAVE(FF(3)))
                        + AA(4) * WAVE(FF(4) + AA(5) * WAVE(FF(5)) + AA(6) * WAVE(FF(6)))
                       );
}

//--------------------------------------------------------------


