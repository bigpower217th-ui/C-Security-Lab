#include <stdio.h>
int main() {
    double sayi = 0.0, sayi2 = 0.0, sonuc = 0.0;
    char islem = 'x';

    fprintf(stdout, "Birinci ,sayiyi girin: ");
    scanf("%lf", &sayi);
    fprintf(stdout, "İşlemi girin (+, -, *, /): ");
    scanf(" %c", &islem);
    fprintf(stdout, "İkinci sayiyi girin: ");
    scanf("%lf", &sayi2);

    switch(islem) {
        case '+':
            sonuc = sayi + sayi2;
            break;
        case '-':
            sonuc = sayi - sayi2;
            break;
        case '*':
            sonuc = sayi * sayi2;
            break;
        case '/':
            sonuc = sayi / sayi2;
            break;
        default:
            fprintf(stderr, "Geçersiz işlem!\n");
            return 1;
    }

    fprintf(stdout, "Sonuç: %.0lf\n", sonuc);
    return 0;
}