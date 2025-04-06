#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt(char* plaintext, char* key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);

    char* cipher = (char*) malloc(sizeof(char) * (text_length + 1));
    memset(cipher, '\0', sizeof(char) * (text_length + 1));

    char* key_ptr = key;
    for(int i = 0; i < text_length; i++)
    {
        if(isalpha(plaintext[i]))
        {
            int shift = tolower(*key_ptr) - 'a';


            if(islower(plaintext[i]))
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            }
            else
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            }
            key_ptr++;
            if (*key_ptr=='\0') {
                key_ptr=key;
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }

    cipher[text_length] = '\0';
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

int main() {
    char filename[MAXN];
    
    printf("Name of the file: ");
    scanf("%s", filename);
    char str[MAXN];
    read_cipher(filename, str);

    if (read_cipher(filename, str) != EXIT_FAILURE) {
    char filename2[MAXN];
    
    printf("Name of the file with the key: ");
    scanf("%s", filename2);
    char key[MAXN];
    read_cipher(filename2, key);

    char* cipher = vigenere_encrypt(str, key);
    printf("%s", cipher);
    save_results("lek4encrypt.txt", cipher);
    free(cipher);
    return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}