/**
 * @file main.c
 * @author YuzhakovMihail
 * @brief Lecture004 GeekBrains C
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <inttypes.h>

void example001() {
    int a = 1, b = 1, expr = 3;
    switch (expr)
    {
    case 2:
        a *= 2;
        break;
    case 3:
        a +=5;
    default:
        break;
    }
    printf("a=%d", a);
}

void example002() {
    int input;
    scanf("%d", &input);
    switch (input)
    {
        case 1: printf("one\n"); break;
        case 2: printf("two\n"); break;
        case 3: printf("three\n"); break;
        default: break;
    }
}

//ввести целое число и определить кол-во цифр в нем
void example003() {
    int n, counter;
    printf("Input number = ");
    scanf("%d", &n);
    while (n != 0)
    {
        n = n / 10;
        counter++;
    }
    printf("Numbers count = %d", counter);
}

//получить все натуральные делители числа n
void example004() {
    uint32_t n, divider;
    printf("Input number = ");
    scanf("%" PRIu32, &n);
    divider = n;
    while (divider != 0)
    {
        if (n % divider == 0) 
            printf("%d ", divider);
        divider--;
    }
}

//оператор continue используется для немедленного перехода к следующей итерации цикла
//break прерывает выполнение текущего цикла
void example005() {
    char c;
    for (int i = 0; i < 5; i++)
    {
        if (i == 3) continue; //не выведет 3
        printf("%d", i);
    }
    for (;;) {
        printf("\nPress any key. Q to quit: ");
        scanf("%c", &c);
        if (c == 'Q' || c == 'q') break;
    }
}

//метка goto label: используется для организации сложного потока управления
//используется для отслеживания ошибок
void example006() {
    printf("Hello");
    goto skip;
    printf("World");
skip:
}

/*
Область видимости переменных
локальная - блок (функция), в которой она объявлена
глобальная - программный файл, начиная со строки объявления.
*/

//описание целых констант enum - перечислимое типа.
//определение констант через макрос define
//перед копмпиляцией в коде будет произведена замена идентификатора на последовательность симоволов.
void example007() {
    enum { NAME_LENGHT = 25 };
    #define NAME_LEN 26
    printf("%d %d", NAME_LENGHT, NAME_LEN);
}

//вычисление корней квадратного уравнения  + меню
void example008() {
    char Choice;
    while (1)
    {
        printf("1. Calculation\n");
        printf("0. Exit\n");
        printf("Press Q or q to quit\n");
NO_PRINT:
        scanf("%c", &Choice);
        switch (Choice)
        {
        case '1': 
            printf("Equation calculating...");
            break;
        case '0':
        case 'q':
        case 'Q':
            return;
        break;
        case 0x0A:
        goto NO_PRINT;
            break;
        default:
            printf("Unexpected choice!\n");
            break;
        }
    }
    
}

//считаем квадраты и кубы чисел
void sem001() {
    int n;
    printf("Enter the number (<=100) = ");
    scanf("%d", &n);
    if (n < 100) {
        for (int i = 1; i <= n; i++)
        {
            printf("%d %d %d", n, n*n, n*n*n);
        }   
    } else {
        printf("Number greater then 100");
    }
}

//не работает
void sem002() {
    int n1, n2;
    printf("Enter the numbers = ");
    scanf("%d%d", &n1, &n2);
    for (int i = n2; i >= n1; i--)
    {
        printf("%d", i*i*i);
    }
}

//првоерить есть ли две последовательно совпадающих цифры в числе - не работает
void sem003() {
    int n1 = 1, n2 = 0;
    int n = 1242;

    while (n > 0 && n1 != n2)
    {
        n1 = n % 10;
        n /= 10;
        n2 = n % 10;
    }

    if (n1 == n2) {
        printf("YES");
    } else
    {
        printf("NO");
    }
}

void sem004() {
    unsigned int a, count = 0;
    do
    {
        scanf("%d", &a);
        count++;
    } while (a != 0);
    printf("%d", count - 1);
}

//если сумма числа == 10...
void sem005() {
    int number = -7003, sum = 0;
    if (number < 0) number *= -1;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    if (sum == 10) {
        printf("YES");
    } else {
        printf("NO");
    }
}

//проверка на простоту
void sem006() {
    int number = 1;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0) {
            printf("NO");
            return;
        } 
    }
    printf("YES");
}

int main() {
    // example001();
    // example002();
    // example003();
    // example004();
    // example005();
    // example006();
    // example007();
    // example008();
    // sem002();
    // sem003();
    // sem004();
    // sem005();
    sem006();
}