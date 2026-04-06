#include <stdio.h>
int main() {

    double sayi1 = 0.0, sayi2 = 0.0, sonuc = 0.0;
    char islem = 'x'; 

    while(1) {

    fprintf(stdout, "<sayi1> <islem> <sayi2> : ");
    scanf("%lf %c %lf", &sayi1, &islem, &sayi2);

    switch (islem)
    {
        case '+':
            sonuc = sayi1 + sayi2;
            break;
        case '-':
            sonuc = sayi1 - sayi2;
            break;
        case '*':
            sonuc = sayi1 * sayi2;
            break;
        case '/':
            sonuc = sayi1 / sayi2;
            break;
        default:
            fprintf(stderr, "Geçersiz işlem!\n");
            return 1;
    }

    printf("Sonuç: %g\n", sonuc);
}
    return 0;
}