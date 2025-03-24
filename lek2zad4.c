#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

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

char* cezar_cipher(char* str, int key){
    int length = strlen(str);
    char* cipher = (char*) malloc (sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        if (str [i] >= 'a' && str[i] <= 'z') {
            cipher[i]= ((str[i] - 'a') + key) % 26 + 'a';
        }
        else if (str [i] >= 'A' && str[i] <= 'Z') {
            cipher[i]= ((str[i] - 'A') + key) % 26 + 'A';
        }
        else if(str [i] >= '0' && str [i] <= '9') {
            cipher[i]= ((str[i] - '0') + key) % 10 + '0';
        }
        
        else {
            cipher[i] = str[i];
        }
    }
    return cipher;
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

    char comPro[20];

    printf("Command:");
    scanf("%s", comPro);

    while(strcmp(comPro, "END") != 0) {

        char filename[MAXN];
        char str[MAXN];
        int key;

        if (strcmp(comPro, "cipher") == 0 || strcmp(comPro, "Cipher") == 0) {
        
            printf("Name of the file: ");
            scanf("%s", filename);
            read_cipher(filename, str);

            printf("Type in the key: ");
            scanf("%i", &key);

            char* cipher = cezar_cipher(str, key);
            printf("%s", cipher);
            printf("\n\n\n");
            save_results("cryptedText.txt", cipher);
            free(cipher);
        }

        else if (strcmp(comPro, "decipher") == 0 || strcmp(comPro, "Decipher") == 0) {
            printf("Name of the file: ");
            scanf("%s", filename);
            read_cipher(filename, str);

            printf("Type in the key: ");
            scanf("%i", &key);

            char* decipher = cezar_decipher(str, key);
            printf("%s", decipher);
            printf("\n\n\n");
            save_results("plainText.txt", decipher);
            free(decipher);
        }

        else {
            printf("Wrong command! Please try again!\n\n\n");
        }

        printf("Command: ");
        scanf("%s", comPro);
    }

    return (EXIT_SUCCESS);
}