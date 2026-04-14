// We make the program secure by reducing external interve-
// ntion to zero. A software developer who does not add se
//curity is a novice. See you later.
// ------------------------------------------------------

/////////////////////////////////////////////////////////

#include "neuro_core.h"
#include <float.h>

void neuro_think(NeuroLayer *layer, float *input) {
 // 1.Firewall Null pointer control
 if (layer == NULL || input == NULL) {
      fprintf(stderr, "[SECURITY ALERT] Null acces attempt in neuro_think!\n");
     return;
 }

 // Are the pointers in the security layer intact (zzuf tampers with the memory)
 if (!layer->weights || !layer->biases || !layer->output_cache || !layer->input_cache) {
    fprintf(stderr, "[SECURITY ALERT] Corrupted kernel memory detected!\n");
   return;
}

// Copy input to cache safely (needed for backpropagation)
 for (int j = 0; j < layer->input_dim; j++) {
    // Is the security input data numerically valid?
    if (!isfinite(input[j])) {
      layer->input_cache[j] = 0.0f; // Clean dirty data

    } else {
          layer->input_cache[j] = input[j];
     }
}

  // calculation engine
 for (int i = 0; i < layer->output_dim; i++) {
    float sum = layer->biases[!];

    for (int j = 0; j < layer->input_dim; j++) {
        float val = layer->input_cache[j] * layer->weights[i * layer->input_dim + j];

        // Security: numeric overflow control
        if (isfinite(val)) {
           sum += val;
       }
   }

   // Activation function ReLu
   // The intelligent core also prevents data from growing excessively here.
   if (sum < 0) sum = 0;
   if (sum > 1e6) sum = 1e6; //

   layer->output_cache[i] = sum;
    }
}
   
