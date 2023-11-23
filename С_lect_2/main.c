#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <locale.h>

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Rus");
	//print_data_types_size();
	//arithmetic_progression_sum();
	//average();
	multiply_numbers();
	return 0;
}

void print_data_types_size() {
	printf("+---------------------------------------------------------------------+\n");
    printf("|Type|Byte(s) of memory|          Min           |          Max          |\n");
    printf("+----------------------+------------------------+-----------------------+\n");
    printf("|%20s|%d|%24d|%23d|\n","char",sizeof(char),CHAR_MIN,CHAR_MAX);
    printf("|%20s|%d|%24d|%23d|\n","unsigned char",sizeof(unsigned char),0,UCHAR_MAX);
    printf("|%20s|%d|%24d|%23d|\n","short",sizeof(short),SHRT_MIN,SHRT_MAX);
    printf("|%20s|%d|%24d|%23d|\n","unsigned short",sizeof(unsigned short),0,USHRT_MAX);
    printf("|%20s|%d|%24ld|%23ld|\n","long",sizeof(long),LONG_MIN,LONG_MAX);
    printf("|%20s|%d|%24u|%23lu|\n","unsigned long",sizeof(unsigned long),0,ULONG_MAX);
    printf("|%20s|%d|%24lld|%23lld|\n","long long",sizeof(long long),LLONG_MIN,LLONG_MAX);
    printf("|%20s|%d|%24d|%23llu|\n","unsigned long long",sizeof(unsigned long long),0,ULLONG_MAX);
    printf("|%20s|%d|%24e|%23e|\n","float",sizeof(float),-FLT_MAX,FLT_MAX);
    printf("|%20s|%d|%24.16E|%23.16E|\n","double",sizeof(double),DBL_MIN,DBL_MAX);
}

void arithmetic_progression_sum() {
	int a1, d, n, sum;
	printf("Введите перывй член АП, шаг и количество членов: ");
	scanf("%d %d %d", &a1, &d, &n);
	sum = (2*a1 + (n-1)*d)*n / 2;
    printf("%d\n", sum);
}

void average() {
	int a, b, c;
	float avg;
	printf("Enter three numbers:\n");
	scanf("%d %d %d", &a, &b, &c);
	avg = (a + b + c) / 3.; //обязательно указываем точку - литерал на вещественное число
	printf("Среднее арифметическое трех чисел %d, %d, %d равно %.2f", a, b, c, avg);
}

void multiply_numbers() {
	int x = 1234;
	printf("Digits multiply: %d", (x / 1000) * ((x % 1000) / 100) * ((x % 100) / 10) * (x % 10));
}

