#include <stdio.h>

void max_min() {
    int arr[10];
    scanf("%d", &arr[0]);
    int max = 0;
    int min = 0;

    for (int i = 1; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > arr[max]) max = i;
        if (arr[i] <= arr[min]) min = i;
    }
    printf("max index = %d\nmin_index = %d\n", max, min);
}

void reverse_array(int* ptr, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--)
           swap(&ptr[i], &ptr[j]);

}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void inverse_half() {
    enum {size = 10};
    const int coefficient = 2;
    int arr[size];

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < coefficient; i++)
        reverse_array(arr + i * size/coefficient, size/coefficient);
    
    print_array(arr, size);
}

void positive_negative() {
    #define size 10
    int all[size] = {5, -4, 0, 1, 4, -3, -3, 3, 0, 2};
    int positive[size];
    int pos_iter = 0;
    int negative[size];
    int neg_iter = 0;

    for (int i = 0; i < size; i++) {
        if (all[i] < 0)
            negative[neg_iter++] = all[i];
        if (all[i] > 0) 
            positive[pos_iter++] = all[i];
    }
    print_array(positive, pos_iter);
    print_array(negative, neg_iter);
}

int main() {
    // max_min();
    // inverse_half();
    positive_negative();
}