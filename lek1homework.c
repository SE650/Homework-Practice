#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 1000 //прави се definе за да се ползват по-големи числа или Macros многократно

char* cezar_cipher(char* txt, int key) { // функция за криптичране че шифер на Цезар с параметър за текст масива и за числото, което е ключът.
    int length = strlen(txt); //strlen се ползва за да покаже колко символа има в char масива. 
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));  // Тук се заделя памет за текстовия масив с размер length + 1 чрез фунцкията malloc() от stdlib.h
    for(int i = 0; i < length; i++) { //цикъл for за да се провери всеки символ в масива
        
        if (txt[i] >= 'a' && txt[i] <= 'z') { //ползват се if функции, за да се знаят дали символът е upper, lower или digit. В първият if, е за малки букви
            cipher[i] = (txt[i] - 'a' + key) % 26 + 'a'; // Ползва се тази формула като ползваме % 26, защото буквите на английската азбука са 26.
        } else if (txt[i] >='A' && txt[i] <= 'Z') {
            cipher[i] = (txt[i] - 'A' + key) % 26 + 'A'; //Задача 1: Същата формула, но този път пишем буквите с големи букви като заменим 'а' с 'А'
        } else if (txt[i] >='0' && txt[i] <= '9'){
            cipher[i] = (txt[i] - '0' + key) % 10 + '0'; //Задача 1: Формулата тука се променя, защото има 10 единични числа. Заместваме 'а' с '0' и вместо %26, пишем %10
        } else {
            cipher[i] = txt[i]; //Всички останали знаци като запетай, точки и прочие не се криптират.
        }
    }
    cipher[length] = '\0';
    return cipher; //Връща се разултатът
}

int main () {

    char a[MAXN]; //Правим масив а за текста, който ще напишем и MAXN e define да е 1000
    printf("Type in the text: "); 
    scanf("%[^\n]s" ,a); //Задача 2: Чрез [^\n], може да приеме и интервали, без да прави проблеми програмата като пишем текста. Тук пишем текста.

    int k; //Прави се оператор за ключа
    printf("Type in the number for the Caesar cipher to work: ");
    scanf("%d", &k); // Тук пишем числото, което ще криптира текста.

    char* cipher = cezar_cipher(a, k); //правим char с указател, който ще има резултатът на функцията cezar_cipher с параметри a (текстовият масив) и k (ключът)
    printf("%s", cipher); //извежда се резултатът от криптираният текст.

    char *filename = "CryptedText.txt"; //Задача 3: Правим нов оператор за да има име файла

    FILE *fp = fopen(filename, "wb"); //Отваряме файла чрез fopen и пишем filename
    fprintf(fp, "%s", cipher); //Ползва се fprintf() за да се запише резултатът от cipher в текстовият файл, като ползваме fp.
    fclose(fp); //Затваряме файла и е записан с fclose()

    free(cipher); //Освобождаваме място чрез free()
    return EXIT_SUCCESS;    
}
