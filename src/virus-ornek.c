#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {

        printf("\033[1;31m bu bir virüs örneğidir white hat hacker ---\n");

        uslep(1000000);
    }
    return 0;
}