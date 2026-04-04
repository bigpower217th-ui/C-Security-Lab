#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
    char* key;
    char* value;
    struct Node* next;
};

struct Node* head = NULL;

void log_kaydet(const char* mesaj) {
    FILE* file = fopen("bellek_log.txt", "a");
    if (file == NULL) return;

    time_t simdi;
    time(&simdi);
    fprintf(file, "[%s] %s\n", strtok(ctime(&simdi), "\n"), mesaj);
    fclose(file);
}

char* dinamik_input() {
    char *str = malloc(sizeof(char));
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        str[i++] = c;
        str = realloc(str, i + 1);
    }
    str[i] = '\0';
    return str;
}

void insert(char* key, char* value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            free(temp->value);
            temp->value = strdup(value);
            log_kaydet("Anahtar guncellendi.");
            return;
        }
        temp = temp->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = head;
    head = newNode;

    char log_mesaji[512];
    snprintf(log_mesaji, sizeof(log_mesaji), "Eklendi: %s", key);
    log_kaydet(log_mesaji);
    printf("[BELLEK] Eklendi: %s\n", key);
}

void get(char* key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            printf("[SONUC] %s: %s\n", key, temp->value);
            char log_mesaji[512];
            snprintf(log_mesaji, sizeof(log_mesaji), "Sorgulandi: %s", key);
            log_kaydet(log_mesaji);
            return;
        }
        temp = temp->next;
    }
    printf("Hata '%s' bulunamadi.\n", key);
}

int main() {
    int secim;
    char k_buffer[1024];

    while(1) {
        printf("\n1- Veri ekle\n2- Veri getir\n3- Cikis\nSecim: ");
        if (scanf("%d", &secim) != 1) break;
        getchar();

        if (secim == 1) {
            printf("Anahtar: ");
            char* anahtar = dinamik_input();
            printf("Deger (sinir yok): ");
            char* deger = dinamik_input();

            insert(anahtar, deger);
            free(anahtar);
            free(deger);
        } else if (secim == 2) {
            printf("Anahtar: ");
            char* anahtar = dinamik_input();
            get(anahtar);
            free(anahtar);
        } else if (secim == 3) {
            break;
        }
    }

    return 0;
}
