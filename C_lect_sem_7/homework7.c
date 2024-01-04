#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

/**
 * @brief 
 * Возводит n в степень p
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
    if (p == 0) {
        int res = result;
        result = 1;
        return res;
    }
    result *= n;
    recurs_power(n, --p);
}

void read_array(int* array, uint16_t size) {
    for (uint16_t i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

float average(int* array, uint16_t size) {
    float avg = 0;
    for (uint16_t i = 0; i < size; i++)
        avg += array[i];
    return avg /= size;
}
//возвращает минимальный элемент
int find_min(int* arr, uint16_t size) {
    int min = 0;
    for (uint16_t i = 0; i < size; i++) 
        if (arr[i] < arr[min]) min = i;
    return arr[min];
}

//возвращает индекс максимального элемента
int find_max(int* arr, uint16_t size) {
    int max = 0;
    for (uint16_t i = 0; i < size; i++) 
        if (arr[i] > arr[max]) max = i;
    return max;
}

void print_array(int* arr, uint16_t size) {
    printf("\n");
    for (uint16_t i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void non_save_swap(int* a, int* b) {
    *a = *b;
}

void save_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void one_pos_shift_right(int* arr, uint16_t size) {
    int temp = arr[size - 1];
    for (uint16_t i = size; i > 0; i--)
        non_save_swap(&arr[i], &arr[i - 1]);
    non_save_swap(&arr[0], &temp);
}

void shift_array(int* arr, uint16_t size, int shift) {
    for (uint16_t i = 0; i < shift; i++)
        one_pos_shift_right(arr, size);        
}

void sort_by_last_digit(int* arr, uint16_t size, int base) {
    for (uint16_t i = 0; i < size - 1; i++)
        for (uint16_t j = 0; j < size - 1; j++)
            if (arr[j] % base > arr[j + 1] % base) save_swap(&arr[j], &arr[j + 1]);
}

void sort(int* arr, uint16_t size) {
    for (uint16_t i = 0; i < size - 1; i++)
        for (uint16_t j = 0; j < size - 1; j++)
            if (arr[j] < arr[j + 1]) save_swap(&arr[j], &arr[j + 1]);
}

int count_zero(int* arr, uint16_t size) {
    uint16_t zero_count = 0;
    for (uint16_t i = 0; i < size; i++)
        if (arr[i] / 10 % 10 == 0) zero_count++;
    return zero_count;
}

void fill_array(int* arr, uint16_t size, int* zero_arr) {
    uint16_t zero_count = 0;
    for (uint16_t i = 0; i < size; i++)
        if (arr[i] / 10 % 10 == 0) {
            zero_arr[zero_count] = arr[i];
            zero_count++;
        }
}

void fill_array_by_zeros(int* arr, uint16_t size) {
    for (uint16_t i = 0; i < size; i++)
        arr[i] = 0;
}

void fill_array_by_digits(int* array, uint16_t number) {
    int i = 0;
    while (number > 0)
    {
        array[i] = number % 10;
        number /= 10;
        i++;
    }
}

uint16_t count_digits(int number) {
    uint16_t count = 0; 
    while (number > 0)
    {
        count++;
        number /= 10;
    }
    return count;
}

int array_to_digit(int* arr, uint16_t size) {
    int number = 0;
    for (uint16_t i = 0; i < size; i++)
        number += arr[i] * recurs_power(10, size-1 - i);
    return number;
}

//не будет работать с отрицательными числами в массиве
int* count_elements(int* arr, uint16_t size) {
    uint16_t count_array_size = arr[find_max(arr, size)] + 1;
    int* count_array = malloc(sizeof(int) * count_array_size);
    fill_array_by_zeros(count_array, count_array_size);
    for (uint16_t i = 0; i < size; i++) 
        count_array[arr[i]]++;
    return count_array;
}




/**
 * @brief 
 * Задача 1. Среднее арифметическое чисел.
 */
void task01(void) {
    enum {size = 5};
    int arr[size];

    read_array(arr, size);
    printf("Average = %.3f\n", average(arr, size));
}

/**
 * @brief 
 * Задача 2. Найти минимум
 */
void task02(void) {
    enum {size = 5};
    int arr[size];

    read_array(arr, size);
    printf("Min = %d\n", find_min(arr, size));
}

/**
 * @brief 
 * Задача 3. Циклический сдвиг массива вправо на 4.
 */
void task03(void) {
    enum {size = 12};
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    uint8_t shift = 4;
    
    // read_array(arr, size);
    shift_array(arr, size, shift);
    print_array(arr, size);
}

/**
 * @brief 
 * Задача 4. Отсортировать по последней цифре.
 */
void task04(void) {
    enum {size = 10};
    int arr[size] = {14, 25, 13, 30, 76, 58, 32, 11, 41, 97};

    // read_array(arr, size);
    print_array(arr, size);
    sort_by_last_digit(arr, size, 10);
    print_array(arr, size);
}

/**
 * @brief 
 * Задача 5. Вторая с конца ноль
 */
void task05(void) {
    enum {size = 10};
    int arr[size] = {40, 105, 203, 1, 14, 1000, 22, 33, 44, 55}; 

    // read_array(arr, size);
    print_array(arr, size);
    int zero_arr_size = count_zero(arr, size);
    int zero_arr[zero_arr_size];
    fill_array(arr, size, zero_arr);
    print_array(zero_arr, zero_arr_size);
}

/**
 * @brief 
 * Задача 6. Чаще других.
 */
void task06(void) {
    enum {size = 10};
    int arr[size] = {4, 1, 2, 1, 11, 2, 34, 11, 0, 11}; 

    // read_array(arr, size);
    print_array(arr, size);
    int* count_array = count_elements(arr, size);
    uint16_t count_array_size = arr[find_max(arr, size)] + 1;
    int max_count = find_max(count_array, count_array_size);
    printf("\n%d", max_count);
}

/**
 * @brief 
 * Дополнительное задание с семинара.
 * Переставить цифры в числе так, чтобы получилось максимальное число.
 */
void task07(void) {
    uint32_t number = 3251;
    uint16_t digits_count = count_digits(number);
    int number_arr[digits_count]; //но лучше тип данных uint8_t или char
    printf("%d\n", number);
    fill_array_by_digits(number_arr, number);
    sort(number_arr, digits_count);
    printf("%d\n", array_to_digit(number_arr, digits_count));
}

int main() {
    // task01();
    // task02();
    // task03();
    // task04();
    // task05();
    // task06();
    task07();
}