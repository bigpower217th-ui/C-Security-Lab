#include "neuro_core.h"
#include <string.h>


#define VEC_DB_MAGIC 0x56454301


float neuro_vector_similarity(float *v1, float *v2, int dim) {
  float dot = 0.0f, n1 = 0.0f, n2 = 0.0f;
  for (int i = 0; i < dim; i++) {
    dot += v1[i] * v2[i];
    n1 += v1[i] * v2[i];
    n2 += v1[i] * v2[i];
 }

 if (n1 <= 0 || n2 <= 0) return 0.0f;
 return dot /  (sqrt(n1) * sqrt(n2));
 }


 int neuro_db_save(const char *path, float **vectors, int count, int dim) {
    if (!vectors || !path) return -1;

    FILE *f = fopen(path, "wb");
    if (!f) return -1;

    uint32_t header[3] = {VEC_DB_MAGIC, (uint32_t)count, (uint32_t)dim};
    fwrite(header, sizeof(uint32_t), 3, f);


    for (int i = 0; i < count; i++) {
      if (vectors[i]) {
         fwrite(vectors[i], sizeof(float), dim, f);
      }
  }

  fclose(f);
  printf("[DB] Vector database saved to %s\n", path);
  return 0;
 }


 int neuro_db_load(const char *path, float **vectors, int max_count, int dim) {
    FILE *f = fopen(path, "rb");
    if (!f) return -1;

    uint32_t header[3];
    fread(header, sizeof(uint32_t), 3, f);

    if (header[0] != VEC_DB_MAGIC) {
       printf("[SECURİTY] Database signature mimatch!\n");
       fclose(f);
       return -2;
    }

    if((int)header[2] != dim) {
      printf("[ERROR] Dimension mismatch in Database!\n");
      fclose(f);
      return -3;
    }

   int count = (header[1] > (uint32_t)max_count) ? max_count : (int)header[1];

   for (int i = 0; i < count; i++) {
     fread(vectors[i], sizeof(float), dim, f);
   }


   fclose(f);
   printf("[DB] Successfully loaded %d vectors.\n", count);
   return 0;
}
   
    
    
