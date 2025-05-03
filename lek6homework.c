#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define MAXN 1000

unsigned char hex_to_byte(const char* hex) {
    unsigned int byte;
    sscanf(hex, "%2x", &byte);
    return (unsigned char) byte;
}

int read_input(char* filename, char* str) {
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

void encrypt(char* input, char* key) {
    unsigned int length = strlen(input);

    int padded_length = ((length + 7) / 8) * 8;
    unsigned char padded_input[padded_length];
    unsigned char output[padded_length];

    int difference_length = padded_length - length;
    memcpy(padded_input, input, length);
    memset(padded_input + length, difference_length, difference_length);

    DES_key_schedule key_schedule;
    DES_set_key ((DES_cblock*) key, &key_schedule);

    for(int i = 0; i < padded_length; i += 8)
    {
        DES_ecb_encrypt ((DES_cblock*) (padded_input + i),
            (DES_cblock*) (output + i), &key_schedule, DES_ENCRYPT);
    }

    save_results("Lek6crpyt.txt", output);
    for(int i = 0; i < padded_length; i++)
    {
        printf("%02x", output[i]);
    }
}

int main() {

    char filename[MAXN];
    char filenameKey[MAXN];
    unsigned char input[MAXN];
    unsigned char key[KEY_SIZE];

    scanf("%s", filename);
    read_input(filename, input);

    scanf("%s", filenameKey);
    read_input(filenameKey, key);

    //encrypt

    void encrypt(input, key);

    free(filename);

    //decrypt

    scanf("%s", filename);
    read_input(filename, input);

    int hex_len = strlen(input);
    if(hex_len % 2 != 0)
    {
        printf("Invalid hex input!\n");
        return EXIT_FAILURE;
    }

    int cipher_len = hex_len / 2;
    unsigned char cipher[cipher_len];
    for(int i = 0; i < cipher_len; i++)
    {
        cipher[i] = hex_to_byte(&input[i * 2]);
    }

    unsigned char decrypted[cipher_len];
    DES_key_schedule key_schedule;
    DES_set_key( (DES_cblock*) key, &key_schedule);

    for(int i = 0; i < cipher_len; i += 8)
    {
        DES_ecb_encrypt((DES_cblock*) (cipher + i),
            (DES_cblock*) (decrypted + i), &key_schedule, DES_DECRYPT);
    }

    unsigned char pad_value = decrypted[cipher_len - 1];
    if(pad_value > 8) {
        pad_value = 0;   
    }

    int original_len = cipher_len - pad_value;
    fwrite(decrypted, 1, original_len, stdout);
    printf("\n");

    save_results("Lek6decrypt.txt", decrypted);
    return EXIT_SUCCESS;
}