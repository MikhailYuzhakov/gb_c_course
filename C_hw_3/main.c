#include <stdio.h>
#include <inttypes.h>
#include <locale.h>

//Задача 1. Наибольшее из пяти чисел
void task1() {
    int n1, n2, n3, n4, n5, max;
    scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
    max = n1 > n2 ? n1 : n2;
    max = max > n3 ? max : n3;
    max = max > n4 ? max : n4;
    max = max > n5 ? max : n5;
    printf("max = %d\n", max);
}

// Задача 2. Наименьшее из пяти чисел
void task2() {
    int n1, n2, n3, n4, n5, min;
    scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
    min = n1 < n2 ? n1 : n2;
    min = min < n3 ? min : n3;
    min = min < n4 ? min : n4;
    min = min < n5 ? min : n5;
    printf("min = %d\n", min);
}

//Задача 3. В порядке возрастания
void task3() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    //2 варианта
    // n1 < n2 ? n2 < n3 ? printf("YES") : printf("NO") : printf("NO");
    n1 < n2 && n2 < n3 ? printf("YES") : printf("NO");
}

//Задача 4. Ввести номер месяца и вывести название времени года.
void task4() {
    uint8_t month_number;
    printf("Enter the month number: \n");
    scanf("%d", &month_number);
    month_number == 12 || month_number < 3 ?     printf("WINTER") :
        month_number > 2 && month_number < 6 ? printf("AUTUMN") :
            month_number > 5 && month_number < 9 ? printf("SUMMER") :
                month_number > 8 && month_number < 12 ? printf("SPRING") :
                    printf("WRONG NUMBER!");  
}

int main() {
    setlocale(LC_ALL, "Rus");
    printf("Task 1\n");
    task1();
    printf("\nTask 2\n");
    task2();
    printf("\nTask 3\n");
    task3();
    printf("\n\nTask 4\n");
    task4();
}