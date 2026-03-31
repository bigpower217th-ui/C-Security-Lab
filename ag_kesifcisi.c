#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

char ag_miks[16] = "192.168.1";
char komut[100];

printf("\033[1;36m[Ağ tarama başlatıldı]\0330m\n");
printf("Hedef Ağa: %s.0/24\n", ag_miks);
printf("----------------------------\n");

for (int i = 1; i <= 254; i++) {

    snprintf(komut, sizeof(komut), "ping -c 1 -W 1 %s.%d > /dev/null 2>&1", ag_miks, i);
    int sonuc = system(komut);


    if (sonuc == 0) {
        printf("\033[1;32m%s.%d aktif\033[0m\n",ag_miks, i);

    } else {
    }
    }

    printf("-----------------------------\n");
    printf("[BİTTİ] Tarama tamamlandı.\n");

    return 0;
    }