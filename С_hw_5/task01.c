#include <stdio.h>
#include <inttypes.h>
/**
 * @brief 
 * Определяет, сколько зерен попросил положить на N-ую клетку изобретатель шахмат.
 * @param N номер шахматной клетки
 * @return int количество зерен
 */
uint64_t countSeeds(int N) {
    int count = 0;
    if (N > 0 && N < 65) {
        count++;
        for (char i = 0; i < N - 1; i++)
        {
            count *= 2;
        }
        return count;
    } else {
        printf("Not valid cell quantity");
    }
}

/**
 * @brief 
 * Задача 1. Сколько зерен на доске?
 */
int main(int args, char** argv) {
   printf("%d\n", countSeeds(2));
   return 0;
}