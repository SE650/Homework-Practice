#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void isPrime(bool c) { //функция за извеждане на резултат дали числото е просто или не чрез указател bool c.
    if (c) { 
        printf("The number is prime\n"); //понеже разботим с boolean оператор, ако той е True, значи ще изведе текста.
    } else { 
        printf("The number is not prime\n"); //тук е обратното.
    }
}

void check (int a) { //функция за проверка на числото дали е просто или не. 
    bool prime = true; //задаваме оператора boolean, който е верен.
    double end = sqrt((double)a); //Изискването на задачата: ето тук оптимизираме кода като използваме квадратен корен на даденото число от библиотека math.c.
    // Ще се използва, 
    for(int i=2; i<= end; i++){ 
        if (a % i == 0) {
            prime = false; //проверяваме дали дали има остатък 0. Ако има остатък 0, значи не е просто числo и prime става false.
        }
    }
    isPrime(prime); // викаме функцията isPrime, след for цикъла и задаваме като параметър prime за проверка. 
    
}

int main () {

    int num; // създаваме указател за цяло число
    printf("Insert the number: ");
    scanf("%d", &num); // пишем числото
    check(num); // вкаме функцията check за да започне проверката и задаваме като параметър num.

    return EXIT_SUCCESS;
}
