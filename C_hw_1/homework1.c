#include <stdio.h>

// 1. Вывести на экран “Hello world!”.
void printHW() {
    printf("Hello world!\n");
}

// 2. Вывести текст лесенкой.
void ladder_text() {
    char* text[] = {"Let's", "go", "to walk"};
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= i; j++) {
            printf("\t");
        }
    printf("%s\n", text[i - 1]);
    }
}

// 3. Вывести на экран рисунок из букв.
void print_picture() {
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");
    printf(" HH HH\n");
    printf(" ZZZZZ\n");
}

// 4. Нарисовать соты.
void print_honeycombs() {
    printf(" __    __\n");
    for (int i = 0; i < 10; i++) {
        printf("/  \\__/  \\\n");
        printf("\\__/  \\__/\n");
    }
}

int main() {
    printf("Задание 1\n");
    printHW();
    printf("\nЗадание 2\n");
    ladder_text();
    printf("\nЗадание 3\n");
    print_picture();
    printf("\nЗадание 4\n");
    print_honeycombs();
}

