#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void isPrime(bool c) {
    if (c) {
        printf("The number is prime\n");
    } else {
        printf("The number is not prime\n");
    }
}

void check (int a) {
    bool prime = true;
    double end = sqrt((double)a);
    for(int i=2; i<= end; i++){
        if (a % i == 0) {
            prime = false;
        }
    }
    isPrime(prime);
    
}

int main () {

    int num;
    printf("Insert the number: ");
    scanf("%d", &num);
    check(num);

    return EXIT_SUCCESS;
}