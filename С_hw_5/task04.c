#include <stdio.h>
#include <inttypes.h>
/**
 * @brief 
 * Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования
 * @param N 
 * @return int сумма числе от 1 до N
 */
uint64_t numbersSum(uint16_t N) {
    uint64_t sum = 0;
    for (uint16_t i = 1; i <= N; i++) sum += i;
    return sum;
}

/**
 * @brief 
 * Задача 4. Сумма от 1 до N
 */
int main(int args, char** argv) {
    uint64_t N = 100;
    printf("Sum numbers from 1 to %d is = %d\n", N, numbersSum(N));
    return 0;
}