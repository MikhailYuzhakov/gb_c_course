#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

/**
 * @brief 
 * Задача 1. Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
 */
void task1() {
    int a = 1, b = 5, sum = 0;
    printf("Задача 1. Сумма квадратов маленьких чисел.\na = %d, b = %d\n", a, b);
    if (a <= b) {
        for (uint8_t i = a; i <= b; i++)
        {
            sum += i*i;
        }
        printf("Сумма квадратов = %d\n", sum);
    } else
    {
        printf("Неверные входные данные.\n");
    }   
}

/**
 * @brief 
 * Задача 2. Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
 */
void task2() {
    int a = 1234, count = 0;
    printf("Задача 2. Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.\na = %d\n", a);
    while (a > 0)
    {
        a /= 10;
        count++;
    }
    count == 3 ? printf("YES\n") : printf("NO\n");
}

/**
 * @brief 
 * Задача 3. Ввести целое число и определить, верно ли, что все его цифры четные.
 */
void task3() {
    int a = 2694;
    bool isEven = true;
    printf("Задача 3. Все цифры четные.\na = %d\n", a);
    while (a > 0)
    {
        if ((a % 10) % 2 == 0) {
            isEven &= true;
        } else {
            isEven &= false;
        }
        a /= 10;
    }
    isEven ? printf("YES\n") : printf("NO\n");
}

int intPow(int number, int degree) {
    int result = number;
    for (int i = 1; i < degree; i++)
    {
        result *= number;
    }
    return result;
}

int countDigits(int number) {
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}
/**
 * @brief 
 * Задача 4. Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.
 */
void task4() {
    #define BASE 10
    int a = 123456789, b = 0, digitsNumber = countDigits(a);
    printf("Задача 4. Перевернуть число\na = %d\n", a);
    for (int i = digitsNumber - 1; i > 0; i--)
    {
        b += (a % BASE) * intPow(BASE, i);
        a /= 10;
    }
    b += a;
    printf("Число наоборот = %d\n", b);
}

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

int digitsMultiply(int number) {
    int mltpl = 1, a = number;
    while (a > 0)
    {
        mltpl *= a % 10;
        a /= 10;
    } 
    return mltpl;
}

bool isLuckyNumber(int number) {
    // printf("number = %d   digitsMultiply = %d   digitsSum = %d\n", number, digitsMultiply(number), digitsSum(number));
    if (digitsMultiply(number) == digitsSum(number)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 
 * Задача 5. Ввести натуральное число и напечатать все числа от 10 до введенного числа у которых сумма цифр равна произведению цифр
 */
void task5() {
    #define FROM 10
    int a = 1000;
    printf("Задача 5. Все счастливые числа\na = %d\n", a);
    for (int i = FROM; i <= a; i++) {
        if (isLuckyNumber(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
}