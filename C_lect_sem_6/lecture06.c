#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

int sumRec(int);
int fibonaci(int);
void recursionFor(int);
void print_rev(void);
void dec_to_bin(int);
uint32_t find_max(void);
void print_float_bit(float);
void float_compare(void);
void float_compare_right(void);

int main(int args, char** argv) {
    // printf("%d\n", sumRec(1234));
    // fibonaci(6);
    // recursionFor(10);
    // print_rev();
    // dec_to_bin(15);
    // printf("%d", find_max());
    // float f = 15.625;
    // print_float_bit(f);
    // float_compare();
    float_compare_right();
}

/**
 * @brief 
 * Сумма цифр числа рекурсивно (простая рекурсия)
 * @param num 
 * @return int 
 */
int sumRec(int num) {
    if (num > 0) 
        return num % 10 + sumRec(num / 10);
    else 
        return 0;
}

/**
 * @brief 
 * Считает числа Фиббоначи рекурсией, но одни и те же вычисления повторяются
 * @param n 
 * @return int 
 */
int fibonaci(int n) {
    if (n == 0) {
        printf("return 0\n");
        return 0;
    }
    if (n == 1) {
        printf("return 1\n");
        return 1;
    }
    int fib = fibonaci(n - 1) + fibonaci(n - 2);
    printf("fibonaci(%d) = %d\n", n, fib);
    return fib;
}

/**
 * @brief 
 * Замена цикла For рекурсией
 * @param i 
 * @param n 
 */
void recursionFor(int n) {
    static int i = 0;
    if (i == n)
        return;
    printf("%d ", i++);
    recursionFor(n);
}

/**
 * @brief 
 * Вывод введенной строки в обратной последовательности
 */
void print_rev(void) {
    char ch;
    scanf("%c", &ch);
    if (ch != '.') {
        print_rev();
    } else {
        return;
    }
    printf("%c", ch);
}

/**
 * @brief 
 * Рекурсивный перевод в двоичную СС
 * @param number 
 */
void dec_to_bin(int number) {
    if (number >= 2) {
        dec_to_bin(number / 2);
    }
    printf("%d", number % 2);
}

/**
 * @brief 
 * Ищем максимальное введенное число с помощью рекурсии
 * @return uint32_t 
 */
uint32_t find_max(void) {
    uint32_t number, max;
    scanf("%d", &number);
    if (number == 0) return 0;
    max = find_max();
    if (max < number) {
        max = number;
    }
    return max;
}

/**
 * @brief 
 * Отображение вещественного числа в двоичном виде
 * @param number 
 */
void print_float_bit(float number) {
    unsigned int fi;
    memcpy(&fi, &number, 4); //копируем участок памяти, который занимает вещ. переменная в участок памяти целочисленной переменной
    for (int i = 31; i >= 0; i--) {
        if (i == 30 || i == 22) printf(" "); //для красоты разделяет 
        if (fi & (1 << i)) putchar('1'); 
            else putchar('0');
    }
    putchar('\n');
}

/**
 * @brief 
 * Неверное сравнивание вещественных числе
 */
void float_compare(void) {
    float one = 1, one_error = 0;
    for (int i = 0; i < 10; i++, one_error += 0.1) {}
    one_error == one ? printf("YES\n") : printf("NO\n"); //напечатает NO
    printf("one = %.5f one_error = %.5f\n", one, one_error); //визуально числа равны
    print_float_bit(one);
    print_float_bit(one_error); //но в двоичном виде отличаются
}

/**
 * @brief 
 * Сраванивает вещественные числа через погрешность
 */
void float_compare_right(void) {
    const float EPS = 0.0000001;
    float a = 0.0000001;
    float b = 0.0000002;
    if (fabs(a - b) < EPS) printf("YES\n");
        else printf("NO\n");
}