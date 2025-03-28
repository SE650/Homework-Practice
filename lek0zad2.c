#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool* erastoten(int n) { //bool фунцкия за Ератостен с параметър int n.

    bool* mem = (bool*) malloc(sizeof(bool) * (n + 1)); // Тук се заделя памет за булев указател с размер n + 1 (защото започваме от 0.) чрез фунцкията malloc() от stdlib.h
    memset(mem, false, sizeof(bool) * (n+1)); //Тук се инициализират всички елементи в масива да са false.
    
    for(int i = 2; i <= n; i++) { //функцията, с която ще ползваме решето на Ератостен като започне от 2 (защото 0 и 1 не са прости числа) до числото n.
        if(mem[i]==false){
            for (int j = i+i; j<= n; j+= i) { //на вътрешният цикъл, j e 2 пъти i, защото в ерастотен, всяко число след n няма да е просто. Ако числото не е просто, значи масив от елемент n e true.
                mem[j] = true;
            }
        }
    }
    return mem; // връщаме bool масива след като свърши цикъла и се върщаме на следващата линия в main()
}

    void printNumbers(bool* a, int n) { // void функция за извеждане на числата в конзолата като output с параметри bool а с указател и int n.

        for(int i = 0; i <= n; i++){  // извеждаме for цикъл от 0 до n
            if(a[i] == false) { 
                printf("%2d ", i); //при всеки елемент от масива, който е false се означава като просто число и се извежда на конзолата. Това се повтаря в цикъла от 0 до n. И така получаваме резулатата
            }
        }
 
    }

int main () {

    int num; //създаваме int оператор 
    printf("Type the number: "); 
    scanf("%d", &num); // въвеждаме числото, което ще използваме

    bool* res = erastoten(num); // създаваме bool оператор с указател, който получава стойност от функцията erastoten с параметър num като последното число.
    printNumbers(res, num); //след като получхме bool масив с резултати true or false, викаме функцията printNumbers, за да ги изведен. Задаваме като параметри res (bool масива) и num (числото, което написахме.)
    free(res); // Изискването на задачата: Изиксва се, защото ако не ни е нужен масива, за да не претоварим динамичната памет, ползваме функцията free за res (bool масива) и се освобождава паметта.

    return EXIT_SUCCESS;
}
