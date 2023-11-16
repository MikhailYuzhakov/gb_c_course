#include <stdio.h>
#include <locale.h>

void task1() {
    int num1, num2, num3;
    printf("1. Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("Numbers sum: %d", num1 + num2 + num3);
}

void task2() {
    int num1, num2, num3;
    printf("\n2. Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("Numbers sum: %d\nNumbers multiply: %d", num1 + num2 + num3, num1 * num2 * num3);
}

void task3() {
    int num1, num2;
    printf("\n3. Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Numbers diff: %d", num1 - num2);
}

void task4() {
    int x = 1231;
    printf("\n4. Average value numbers digit of %d = %.2f", x, ((x/1000) + (x%1000)/100 + (x%100)/10 + x%10) / 4.); 
}

int main() {
    setlocale(LC_ALL, "Rus");
    task1();
    task2();
    task3();
    task4();
}

