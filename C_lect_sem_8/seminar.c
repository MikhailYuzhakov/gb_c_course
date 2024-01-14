#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>

// void sort(int* arr, uint16_t size) {
//     for (uint16_t i = 0; i < size - 1; i++)
//         for (uint16_t j = 0; j < size - 1; j++)
//             if (arr[j] < arr[j + 1]) save_swap(&arr[j], &arr[j + 1]);
// }

//возвращает индекс минимального элемента
void find_two_min_indexes(int* arr, uint16_t size, int* index_of_two_min_elements) {
    uint8_t count = 0;
    int min = arr[0];

    for (uint16_t i = 0; i < size; i++) 
        if (arr[i] < arr[min]) index_of_two_min_elements[0] = i;
    
    min = index_of_two_min_elements[0];
    for (uint16_t i = 0; i < size; i++) 
        if (arr[i] < arr[min]) index_of_two_min_elements[1] = i;
}

void print_array(int* array, int len) {
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void print_digit(char s[]) {
    int arr[strlen(s)];
    for (int i = 0; s[i] != 0; i++)
    {
        // if (arr[i] > '0' && arr[i] < '9')
            arr[s[i] - '0']++;
        // printf("%d %d ", arr[s[i] - '0'], s[i] - '0');
    }
    print_array(arr, 10);
}

void count_array(int* array, int len, int* count) {
    for (int i = 0; i < len; i++)
    {
        count[array[i]]++;
    }
}

int find_zero_element(int* array, int len) {
    for (int i = 0; i < len; i++)
    {
        if (array[i] == 0) return i;
    }
    
}

void task01(void) {
    enum {BUFFER_SIZE = 1000};
    char s[BUFFER_SIZE];
    scanf("%s", s);
    print_digit(s);
}

void task02(void) {
    int arr[] = {2, 3, 1, 4, 7, 6, 9, 8, 10, 0};
    int count[10] = {0};
    count_array(arr, 10, count);
    print_array(count, 10);
    printf("%d", find_zero_element(count, 10));
}

void task03(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int index_of_two_min_elements[2] = {-1, -1};
    find_two_min_indexes(arr, 30, index_of_two_min_elements);
    print_array(index_of_two_min_elements, 2);
}

int main() {
    // task01();
    // task02();
    task03();
}

