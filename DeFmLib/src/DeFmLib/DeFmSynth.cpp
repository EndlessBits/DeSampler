#include "DeFmSynth.h"

//--------------------------------------------------------------
void DeFmSynth::setup(DeParams* p) {
    p_ = p;
}

//--------------------------------------------------------------
vector<float> DeFmSynth::synth(float duration_ms, int sample_rate) {
    de_assert(p_, "DeFmSynth::synth - please call setup()");
    de_assert(sample_rate > 0, "DeFmSynth::synth - bad sample_rate");
    de_assert(duration_ms > 0, "DeFmSynth::synth - bad duration_ms");

    sample_rate_ = sample_rate;
    dphase_ = 1.0 / float(sample_rate);
    int n = int(duration_ms) * sample_rate;


    vector<float> sound(n);
    for (int i = 0; i < n; i++) {
        sound[i] = get_sample()
    }
    return sound;
}

//--------------------------------------------------------------
/*
A0*wave(t*(F0
           + A1*wave(t*(F1 + A2*wave(t*F2) + A3*wave(t*F3)))
           + A4*wave(t*(F4 + A5*wave(t*F5) + A6*wave(t*F6)))
           ))
*/

// Генерация сэмпла звука, -1..1,
// Phase - массив текущих фаз
// A, F - массивы амплитуд и частот в диапазоне 0..1

#define AA(i) p_->d2a(A[i])
#define FF(i) p_->l2f(F[i])
#define WAVE(i, f) wave(Phase[i], f)


float DeFmSynth::get_sample(float* Phase, const float* A, const float* F) {
    return AA(0) * WAVE(0, FF(0)
                        + AA(1) * WAVE(1, FF(1) + AA(2) * WAVE(2, FF(2)) + AA(3) * WAVE(3, FF(3)))
                        + AA(4) * WAVE(4, FF(4) + AA(5) * WAVE(5, FF(5)) + AA(6) * WAVE(6, FF(6)))
                       );
}

//--------------------------------------------------------------
float DeFmSynth::wave(float &phase, float freq) {
    float res = p_->wave(phase);
    phase += fmodf(freq * dphase_,1);
    return res;
}

//--------------------------------------------------------------



