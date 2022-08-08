#pragma once

#include "ofMain.h"
#include "SoundSample.h"
#include "FMShared.h"
#include "FMOperator.h"
#include "ofxSoundUtils.h"

/* FM Fragment :
  Consists of several FM Operators, built into a graph.
  Operator can modulate other operator additively or output audio additively.

     *
      \ 
       *
    * /   \
           *
    * \   /  
       * 
      / 
    *
*/

class FMFragment {
public:    
    // Structure
    FMFragment(FMShared* shared, const vector<int>& connections, const vector<FMOperator>& operators);
    void setup(FMShared *shared, const vector<int> &connections, const vector<FMOperator> &operators);
   
    // Sound generation
	// It's expected that memory for out_buffer is allocated and set its sample_rate,
    // and allocate_buffers are called
    void allocate_buffers(int max_duration); 
    void render_sound(SoundSample& out_buffer, size_t offset, size_t duration);

protected:
    // Structure
    int size_ = 0;
    vector<int> connections_;   // Topological connection of operators, each operator additively writes to destination buffer, -1 means audio output
    vector<FMOperator> operators_;

    // Sound generation
    int max_duration_ = 0;
    vector<SoundSample> buffers_;    // Buffers for storing intermediate waveforms
    void clear_buffers();

};
