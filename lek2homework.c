#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
char* cezar_decipher(char* str, int key){
    int length = strlen(str);
    char* plaintext = (char*) malloc (sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        if (str [i] >= 'a' && str[i] <= 'z') {
            plaintext[i]= ((str[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if (str [i] >= 'A' && str[i] <= 'Z') {
            plaintext[i]= ((str[i] - 'A') - key + 26) % 26 + 'A';
        } 
        else if(str [i] >= '0' && str [i] <= '9') {
            plaintext[i] = ((str[i] - '0') - key + 10) % 10 + '0';
        }
        else {
            plaintext[i] = str[i];
        }
    }
    return plaintext;
}

int read_cipher(char* filename, char* str) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening the file!");
        return EXIT_FAILURE;
    }

    if (fgets(str, MAXN, fp) == NULL) {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

void save_results(char* filename, char* text) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

int main () {

    char filename[MAXN];
    printf("Name of the file: ");
    scanf("%s", filename);
    char str[MAXN];
    read_cipher(filename, str);
    printf("Type in the key: ");
    int key;
    scanf("%i", &key);
    char* plaintext = cezar_decipher(str, key);
    printf("%s", plaintext);
    save_results("plaintext.txt", plaintext);
    free (plaintext);
    return EXIT_SUCCESS;
}