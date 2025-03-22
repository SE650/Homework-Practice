#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool* erastoten(int n) {

    bool* mem = (bool*) malloc(sizeof(bool) * (n + 1));
    memset(mem, false, sizeof(bool) * (n+1));
    
    for(int i = 2; i <= n; i++) {
        if(mem[i]==false){
            for (int j = i+i; j<= n; j+= i) {
                mem[j] = true;
            }
        }
    }
    return mem;
}

    void printNumbers(bool* a, int n) {

        for(int i = 0; i <= n; i++){
            if(a[i] == false) {
                printf("%2d ", i);
            }
        }
 
    }

int main () {

    int num;
    printf("Type the number: ");
    scanf("%d", &num);

    bool* res = erastoten(num);
    printNumbers(res, num);
    free(res);

    return EXIT_SUCCESS;
}