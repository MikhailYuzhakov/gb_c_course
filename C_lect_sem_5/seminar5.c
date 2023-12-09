#include <stdio.h>

int middle(int, int); //задание 1
int factorial(int);  //задание 2
int grow_up(int); //задание 3
int is_digit(char);
int count_digit_text(void);

int main () {
    // printf("Average of two numbers = %d\n", middle(10, 20));
    // printf("Factorial of number = %d\n", factorial(7));
    // grow_up(1243) ? printf("YES") : printf("NO");
    printf("Digits count = %d\n", count_digit_text());
}

int middle(int a, int b) {
    return (a + b) / 2;
}

int factorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int grow_up(int a) {
    int res = 1;
    while (a > 0)
    {
        if (a % 10 < (a / 10) % 10) {
            return 0;
        }
        a /= 10;
    }
    return res;
}

int count_digit_text(void) {
    char c;
    int res = 0;
    while ((c = getchar()) != '.')
    {
        res += is_digit(c);
    }
    return res;
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}