#include <stdio.h>

#define SIZE 3

void matrisiYazdir(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int matris[SIZE][SIZE];
    int dondurulmus[SIZE][SIZE];

    printf("%dx%d boyutunda matris elemanlarını giriniz:\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("Matris[%d][%d]: ", i, j);
      if (scanf("%d", &matris[i][j]) != 1) {
          printf("geçersiz giriş!\n");
          return 1;
      }
        }
    


for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
        dondurulmus[j][SIZE - 1 - i] = matris[i][j];
}
}

printf("\n---Orjinal Matris---\n");
matrisiYazdir(matris);
printf("\n---90 derece sağa dönmüş matris---\n");
matrisiYazdir(dondurulmus);

return 0;
    }
}