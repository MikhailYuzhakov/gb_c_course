#include <stdio.h>
#include <inttypes.h>

/**
 * @brief 
 * Функция находит НОД двух чисел
 * @param a первое число
 * @param b второе число
 * @return int наибольший общий делитель
 */
int NOD(int a, int b) {
    while (a != 0 && b != 0)
    {
        if (a > b) a = a % b;
            else b = b % a;
    }
    return a + b;
}

/**
 * @brief 
 * Задача 2. НОД
 */
int main(int args, char** argv) {
   printf("%d\n", NOD(14, 21));
   return 0;
}