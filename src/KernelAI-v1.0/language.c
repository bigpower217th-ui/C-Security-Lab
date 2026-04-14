#include "neuro_core.h"
#include <string.h>


float text_to_vector(const char *word) {
   float vec = 0.0f;
   for (int i = 0; word[i] != '\0'; i++) {
      vec += (float)word[i];
     }

     return fmodf(vec, 10.0f) / 10.0f;
    }

    void process_input_text(const char *input, float *vector_out, int dim) {
       char temp[256];
       strncpy(temp, input, sizeof(temp));

       char *token = strtok(temp, " ");
       int count = 0;

       while (token != NULL && count < dim) {
           vector_out[count] = text_to_vector(token);
           token = strtok(NULL, " ");
           count++;
         }
}   
