#include <stdio.h>
#include <stdbool.h>

/**
 * @brief 
 * Считает сумму цифр числа
 * @param number 
 * @return int 
 */
int digitsSum(int number) {
    int sum = 0, a = number;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    sum += a;
    return sum;
}

/**
 * @brief 
 * Считает произведение цифр числа.
 * @param number 
 * @return int 
 */
int digitsMultiply(int number) {
    int mltpl = 1, a = number;
    while (a > 0)
    {
        mltpl *= a % 10;
        a /= 10;
    } 
    return mltpl;
}

/**
 * @brief 
 * Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению
 * @param n заданное число
 * @return bool счастливое число или нет
 */
bool is_happy_number(int n) {
    if (digitsMultiply(n) == digitsSum(n)) return true;
        else return false;
}

/**
 * @brief 
 * Задача 3. Сумма цифр равна произведению
 */
int main(int args, char** argv) {
   is_happy_number(528) ? printf("YES") : printf("NO");
   return 0;
}