#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
typedef int(*comparator_type) (const void*, const void*);

void declarationStringExample(void) {
    enum {N = 10};
    char s[10]; //9 значимых символов
    char s1[N]; //сторока из N-1 значимых символов
    char st[] = "hello"; //st[5] = '\0'
    printf("%u\n", sizeof(st));
    char st1[10] = "hello";
    printf("%u\n", sizeof(st1)); //определяет размер выделенной под переменную в байтах
}

void inOutString(void) {
    char st[10]; //9 символов в строке
    scanf("%s", st); //считывает из потока ввода символы и добавляет в конец '\0'
    printf("%s", st);

    scanf("%9s", st); //ограничит ввод 9 символами и предотварит ошибку
    printf("%s\n", st); 
}

void notBufferInOutString(void) {
    char s[10], c;
    int i = 0;
    //ввод не буфер.
    while ((c = getchar()) != '\n' && i < 9)
        s[i++] = c;
    s[i] = '\0';

    //вывод не буфер.
    i = 0;
    while (s[i])
        putchar(s[i++]);
    
}

void scanfTemplate1(void) {
    char s[100];
    scanf("%[a-z]", s);
    printf("%s\n", s);

    // scanf("%[0-9]", s);
    // printf("%s\n", s);
}

void scanfTemplate2(void) {
    char c[100];
    scanf("%[^\n]", c); //считает всё, кроме символа переноса строки
    printf("%s\n", c);
}

void scanfTemplate3(void) {
    char s1[100], s2[100];
    int r = 0; //вернет количество считанных строк
    r = scanf("%[0-9]=%[a-z]", s1, s2); //считает только строку формата 123=hello
    printf("%d\n", r);
    if (r == 2) 
        printf("s1 = %s s2 = %s\n", s1, s2);
}

void scanfTemplate4(void) {
    
}

void stringLength(void) {
    char st[10] = "Hello";
    printf("Sizeof = %u\n", sizeof(st));
    printf("Strlen = %u\n", strlen(st)); //считает кол-во символов до знака \0
}

void stringComparator(void) {
    char st1[10] = "hello";
    char st2[10] = "hello123";
    int res = strcmp(st1, st2);
    printf("%d\n", res);
    res ? printf("NO") : printf("YES");
}

void myStrlen(void) {
    char* src = {"Hello"};
    int len = 0;
    while (*src++) len++; //по адресу *src != 0
    printf("len = %d\n", len);
}

char* my_copy(char *dst, char *src) {
    char *ptr = dst;
    while (*dst++ = *src++);
    return ptr;
}

void copyStringExample(void)
{
    char str1[] = {"Hello"};
    char str2[] = {"World!"};
    printf("%s\n", my_copy(str2, str1));
} 

int myStrComp(char* a, char* b) {
    while (*a && *b && *a == *b)
        a++, b++;
    return *a - *b;
    
}

void Print(char *str, int res) {
    printf(str, res == 0 ? "equal to" : res < 0 ? "less" : "greater then");
}

void stringCompareExmaple(void) {
    char *a = "abcde";
    char *b = "xyz";
    char *c = "abcd";
    char *d = "xyz";
    Print("A is %s B\n", myStrComp(a, b));
    Print("A is %s C\n", myStrComp(a, c));
    Print("A is %s D\n", myStrComp(a, d));
    Print("B is %s C\n", myStrComp(b, c));
    Print("B is %s D\n", myStrComp(b, d));
}

void countWords(void) {
    char s[100];
    int count = 0;
    while (scanf("%s", s) == 1) {
        count++;
        printf("In this text %d words\n", count);
    }
}

/**
 * @brief 
 * Count digits sum of input string
 * @param str 
 * @return int 
 */
int str_sum_digits(const char* str) {
    int i = 0;
    int sum = 0;
    while (str[i++] != '\0')
        if (str[i] > '0' && str[i] <='9')
            sum += str[i] - '0';
    return sum;
}

void sumDigitsInStringExample(void) {
    char s[100];
    scanf("%s", s);
    printf("Sum digits in word %s is %d\n", s, str_sum_digits(s));
}

/**
 * @brief 
 * Convert HEX number string format to DEC number
 * @param c 
 * @return int 
 */
int CharToHex(char c) {
    int result = -1;
    if (c >= '0' && c <= '9') result = c - '0';
    else if (c >= 'A' && c <= 'F') result = c - 'A' + 10;
    else if (c >= 'a' && c <= 'f') result = c - 'a' + 10;
    return result;
}

/**
 * @brief 
 * Convert string to hex array
 * @param str 
 * @param hex 
 * @return int 
 */
int StrToHexMas(char* str, uint8_t* hex) {
    int i          = 0;
    int result     = 0;
    int data       = 0;
    int index      = 0;
    int str_length = strlen(str);

    while (i < str_length) {
        result = 0;
        data = CharToHex(str[i++]);
        if (data >= 0) {
            result = data;
            if (i < str_length) {
                data = CharToHex(str[i++]);
                if (data >= 0) {
                    result *= 16;
                    result += data;
                }
            }
            hex[index++] = result;
        }
    }
    return index;
}

void string_hex_to_dec(void) {
    uint8_t arr[10];
    char* str = {"AAa 1 15"};
    int len = StrToHexMas(str, arr);
    printf("%s\n", str);
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        printf("0x%02X ", arr[i]);
}

void libraryString(void) {
    char dst[30] = "Hello ";
    char src[30] = "GB!!!";

    strcat(dst, src); //конкатенация строк
    printf("%s\n", dst);

    strcpy(src, dst); //копирует строку из dst в src
    printf("%s\n", src);

    int n = strlen(src);
    strncpy(dst, src, n - 1); //копирует указанное количество байт - не заканчивает строку символом '\0'
    dst[n - 1] = 0;
    printf("%s\n", dst);

    char substr[14] = "GB!";
    char* substr_ptr = strstr(dst, substr); //ищет подстроку в строке и возвращает её
    if (substr_ptr) {
        long pos = substr_ptr - dst; //выведет адрес подстроки
        printf("Substring index = %ld\n", pos);
    } else {
        printf("Substring not found!");
    }
}

void conversion(void) {
    char *str = "652.2345brrt    7";
    char *ptr = str;
    int num = atoi(str);
    printf("%d\n", num);

    float numf = atof(str);
    printf("%f\n", numf);

    ptr += 15;
    int num2 = atoi(ptr);
    printf("%d\n", num2);
}

//указатель на объекты одного типа данных
void stringPointers(void) {
    char *ps[] = {"one", "two", "three", NULL};
    for (int i = 0; ps[i]; i++)
        printf("%s\n", ps[i]);
}

//Variable-lenght array
void VLA_example(void) {
    uint32_t n;
    scanf("%u", &n);
    int32_t ar[n];
}

void twoDimensionalArray(void) {
    int arr[3][2] = {
        {1, 2},
        {10, -5},
        {0, -17}
    };

    //int *pm = arr;
    // *(pm + 3) = 123; //или pm[3] = 123
    int (*pm)[2] = arr; //указатель на объект из двух строк
    pm[1][1] = 123;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void twoDimensionExmpl(void) {
    int m[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int *p1;
    int (*p2)[3];
    p1 = m[1];
    p2 = m + 1;
    p1++;
    p2++;
    printf("%d %d\n", *p1, **p2);
}

//компаратор для qsort
int comparator(const int *a, const int *b) {
    return *a - *b;
}

void quick_sort(void) {
    int a[3] = {3, 1, 2};
    printf("%d, %d, %d\n", a[0], a[1], a[2]);
    qsort(a, 3, sizeof(int), (comparator_type)comparator);
    printf("%d, %d, %d\n", a[0], a[1], a[2]);
}

//приоритет разыименования и инкеремента
void priority(void) {
    int a = 10;
    int* pa = &a;
    printf("pa: address = %p \t value %d\n", (void*)pa, *pa);
    int b = *pa++; //сперва инкремент, а потом разыименование
    printf("b: value %d\n", b);
    printf("pa: address = %p \t value %d\n", (void*)pa, *pa);
}

/*
Деклараторы:
int a[3][4] - массив и 3 элементов типа массива из 4 элементов int
char **b - указатель на указатель типа char
int (*a)[10] - указатель на массив из 10 элементов типа int
int *f() - функция, возвращающая указатель на тип int
int (*f)() - f это указатель на функцию, возвращающую значение int
*/

int main() {
    // declarationStringExample();
    // inOutString();
    // notBufferInOutString();
    // scanfTemplate1();
    // scanfTemplate2();
    // scanfTemplate3();
    // stringLength();
    // stringComparator();
    // myStrlen();
    // copyStringExample();
    // stringCompareExmaple();
    // countWords();
    // sumDigitsInStringExample();
    // string_hex_to_dec();
    // libraryString();
    // conversion();
    // stringPointers();
    // VLA_example();
    // twoDimensionalArray();
    // twoDimensionExmpl();
    // quick_sort();
    priority();
}