#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

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
    char cipher[MAXN];

    scanf("%s", cipher);
    read_cipher(filename, cipher);

    char comPro[20];
    printf("Command:");
    scanf("%s", comPro);

    if(strcmp(comPro, "bruteForce") == 0 || strcmp(comPro, "brute force") == 0){
         
        for (int key = 0; key < ALPHA_LENGTH; key++) {
            char* plaintext = cezar_decipher(cipher, key);
            printf("%s, key = %d -> %s\n", cipher, key, plaintext);
            save_results(("file%d.txt",key), plaintext);
            free(plaintext);
        }
    }
    else if (strcmp(comPro, "letter") == 0 || strcmp(comPro, "Letter") == 0) {

        char letters[COMMON_COUNT] = {'e', 't','a','o','i','n','s','r','h','l'};
        int most_common_letter = get_max_index(count_frequencies(cipher)) + 'a';
        for(int i = 0; i < COMMON_COUNT; i++) {
            int key = abs(most_common_letter - letters[i]);
            printf("The key is: %d\n", key);
            char* plaintext = cezar_decipher(cipher, key);
            printf("%s\n", plaintext);
            free(plaintext);
        }
    }

    return EXIT_SUCCESS;
}