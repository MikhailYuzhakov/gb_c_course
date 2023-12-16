#include <stdio.h>
#include <inttypes.h>

/**
 * @brief 
 * Задача 1. В прямом порядке.
 */
void print_num(int num) {
    if (num == 0) return;
    print_num(num / 10);
    printf("%d ", num % 10);
}

/**
 * @brief 
 * Задача 2. От A до B.
 */
void from_a_to_b(int a, int b) {
    printf("%d ", a);
    if (a == b) return;
    if (a < b) from_a_to_b(++a, b);
        else from_a_to_b(--a, b);
}

/**
 * @brief 
 * Задача 3. Количество 1
 * @param n 
 * @return int 
 */
int count_bits(int n) {
    static uint8_t counter = 0;
    if (n == 0) return counter;
    if (n % 2 == 1) counter++;
    count_bits(n / 2);
}

/**
 * @brief 
 * Задача 4. Все нечетные.
 */
void all_odd(void) {
    int number;
    scanf("%d", &number);
    if (number == 0) return;
    if (number % 2 == 1) printf("%d ", number);
    all_odd();
}

/**
 * @brief 
 * Задача 5. Сколько раз встречается символ a
 * @return int 
 */
int acounter(void) {
    char symbol;
    static uint16_t counter = 0;;
    scanf("%c", &symbol);
    if (symbol == '.') return counter;
    if (symbol == 'a') counter++;
    acounter();
}

/**
 * @brief 
 * Задача 6. Возвести в степень
 * @param n 
 * @param p 
 * @return int 
 */
int recurs_power(int n, int p) {
    static int result = 1;
    if (n < -100 || n > 100 || p < 0 || p > 100) {
        printf("ALERT! Available range: n ∈ [-100; 100] and p ∈ [0, 100]\n");
        return 0;
    }
    if (p == 0) return result;
    result *= n;
    recurs_power(n, --p);
}

int main() {
    print_num(12345);
    from_a_to_b(5, 10);
    printf("%d ", count_bits(255));
    all_odd();
    printf("%d", acounter());
    printf("%d", recurs_power(100, 2));
}