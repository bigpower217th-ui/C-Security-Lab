// /////////////////////////////////////////////////////
// This AI Kernel is not heavy like Python, it is written                                                     //
// with the pure fast power C.                                                     //
// ıf I wrote this in Python it would be very heavy                                                    //
// Anyway, there will be an update to my Kernel AI kernel                                                     //
// soon                                                    //
// if there is a problem with my kernel AI use the issues tab                                                    //
////////////////////////////////////////////////////////

#define NEURE_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int input_dim;
    int output_dim;

    // Core Parameters
    float *weights;
    float *biases;

    float *output_cache;
    float *input_cache;
 } NeuroLayer;

 typedef struct {
    float learning_rate;
    float beta1;
    float beta2;
    float epsilon;
    unsigned long t;
} BrainConfig;

// -- Kernel API -- 

NeuroLayer* neuro_create_layer(int in_dim, int out_dim);
void neuro_init_config(BrainConfig *config);

void neuro_think(NeuroLayer *layer, float *input);

// evulation (Backward Propagation)
void neuro_evolve(NeuroLayer *layer, float *error, BrainConfig *config);

// Memory Management
void neuro_free_layer(NeuroLayer *layer);

#endif // NEURO_CORE_H
