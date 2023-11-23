#include <stdio.h>
#include <inttypes.h>



void task1() {
    printf("+---------------------------------------------------------------------+\n");
    printf("|               | Byte(s)  |                  |                       |\n");
    printf("|    Type       \\of memory/                Min|                    Max|\n");
    printf("|                 \\     /                     |                       |\n"); 
    printf("+------------------+-+------------------------+-----------------------+\n"); 
    printf("|%18s|%d|                    %"PRId8"|                          %"PRId8"|\n","int8_t", sizeof(int8_t),INT8_MIN,INT8_MAX); 
    printf("|%18s|%d|                       %"PRIu8"|                          %"PRIu8"|\n","uint8_t", sizeof(uint8_t),0,UINT8_MAX);
    printf("|%18s|%d|                  %"PRId16"|                        %"PRId16"|\n","int16_t", sizeof(int16_t),INT16_MIN,INT16_MAX); 
    printf("|%18s|%d|                       %"PRIu16"|                        %"PRIu16"|\n","uint16_t", sizeof(uint16_t),0,UINT16_MAX);
    printf("|%18s|%d|                       %"PRIu32"|                       %"PRIu32"|\n","uint32_t", sizeof(uint32_t),0,UINT32_MAX);
    printf("|%18s|%d|                       %"PRIu64"|                 %"PRIu64"|\n","uint64_t", sizeof(uint64_t),0,UINT64_MAX);
}

//на входе 2 целых числа, на выходе 2 целых числа
void task2() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a >= b) {
        printf("%d %d", b, a);
    } else {
        printf("%d %d", a, b);
    }
}

void task3() {
    int a, b, max, min;
    scanf("%d%d", &a, &b);
    max = a > b ? a : b;
    min = a < b ? a : b;
    printf("%d %d", min, max);
}


void task4() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d", a > b ? a : b, a < b ?  b : a);
}

//найти максимум из трех чисел
void task5() {
    int a, b, c, max;
    scanf("%d%d%d", &a, &b, &c);
    max = a > b ? a : b;
    max = max > c ? max : c;
    printf("max = %d", max);
}

//найти максмум из цифр (сдедал через тернарный оператор)
void task6() {
    int n1, n2, n3, n4, n5, max, min;
    scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
    max = n1 > n2 ? n1 : n2;
    max = max > n3 ? max : n3;
    max = max > n4 ? max : n4;
    max = max > n5 ? max : n5;
    printf("max = %d\n", max);

    min = n1 < n2 ? n1 : n2;
    min = min < n3 ? min : n3;
    min = min < n4 ? min : n4;
    min = min < n5 ? min : n5;
    printf("min = %d\n", min);
    printf("min + max = %d", min + max);
}

//проверить попадают ли заданные точки в эллипс
void task7() {
    int x0 = 4, y0 = 3, a = 2, b = 1, x = 3, y = 3, N;
    // printf("Enter x0, y0, a, b, x, y = ");
    // scanf("%d%d%d%d%d%d", &x0, &y0, &a, &b, &x, &y);
    N = (float)((x - x0) * (x - x0) / (a * a) + (y - y0) * (y - y0) / (b * b));
    N < 1 ? printf("YES N=%.f", N) : printf("NO N=%.f", N);

    // int x0 = 4, y0 = 3, a = 2, b = 1, x = 3, y = 3;
    // float n = (float)((x-x0)*(x-x0))/(a*a)+((y-y0)*(y-y0))/(b*b);
}

void task8() {
    int a, b;
    scanf("%d%d", &a, &b);
    a > b ? printf("Above") : a < b ? printf("Less") : printf("Equal");
}

int main(int args, int **argv) {
    // task1();
    // task2();
    // task3();
    // task4();
    // task5();
    // task6();
    task7();
    // task8();
}