#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char key[50];
    char value[256];
    struct Node* next;
};

struct Node* head = NULL;

void insert(char* key, char* value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            strcpy(temp->value, value);
            return;
        }
        temp = temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = head;
    head = newNode;
    printf ("[BELLEK] '%s' anahtarı kaydedildi.\n", key);
}

void get(char* key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            printf("[SONUC] '%s': %s\n", key, temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("[HATA] '%s' anahtar bulunamadı.\n", key);
}

int main() {
    int secim;
    char k[50];
    char v[256];
    while (1) {
        printf("1- Ekle\n2- Getir\n3- Çıkış\nSeçim: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("Anahtar: ");
                scanf("%s", k);
                printf("Değer: ");
                scanf("%s", v);
                insert(k, v);
                break;
            case 2:
                printf("Anahtar: ");
                scanf("%s", k);
                get(k);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}