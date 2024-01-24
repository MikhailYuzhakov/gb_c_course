#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

void countSymbols(FILE *file, uint8_t *countArray, char endsWith) {
    char ch;
    while ( (ch = fgetc(file)) != endsWith)
            countArray[ch - 'a']++;
}

void countAllSymbols(FILE *file, uint8_t *countArray) {
    char ch;
    while ( (ch = fgetc(file)) != EOF )
        if ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
            countArray[ch - 'A']++;
}

int find_max(int* arr, uint16_t size) {
    int max = 0;
    for (uint16_t i = 0; i < size; i++) 
        if (arr[i] > arr[max]) max = i;
    return max;
}

void printAllCountAlphabet(uint8_t *countArray, int SIZE) {
    printf("===============================================\n");
    for (int i = 0; i < SIZE; i++)
        printf("%c ", i + 'A');
    printf("\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", countArray[i]);
    printf("\n");
}

void fillArrayByZeroes(int* arr, uint16_t size) {
    for (uint16_t i = 0; i < size; i++)
        arr[i] = 0;
}

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

void printCountAlphabet(uint8_t *countArray, int isUpperCase) {
    char up_case_char = 'a';
    if (isUpperCase) up_case_char = 'A';
    printf("===============================================\n");
    for (int i = 0; i < 24; i++)
        printf("%c ", i + up_case_char);
    printf("\n");
    for (int i = 0; i < 24; i++)
        printf("%d ", countArray[i]);
    printf("\n");
}

void readStringFromFile(FILE *file, char *string) {
    fseek(file, 0, SEEK_SET);
    char ch;
    uint16_t i = 0;
    while ( (ch = fgetc(file)) != EOF )
        string[i++] = ch;
    string[i] = '\0';
}

uint16_t countDigitsInString(char *string) {
    int i = 0;
    int k = 0;
    int flag = 0;
    uint16_t number_counter;
    while ( string[i++] != '\0') {
        if (string[i] >= '0' && string[i] <= '9') {
            flag = 1;
        } else if (flag) {
            number_counter++;
            flag = 0;
            k = 0;
        }
    }
    return number_counter;
}

void readOnlyDigits(char *string, int *digitsArr) {
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;
    while ( string[i++] != '\0') {
        if (string[i] >= '0' && string[i] <= '9') {
            flag = 1;
            digitsArr[j] = digitsArr[j] * recurs_power(10, k++) + string[i] - '0';
        } else if (flag) {
            j++;
            flag = 0;
            k = 0;
        }
    }
}

int comparator(const void * x1, const void * x2) {
    return *(int *)x1 - *(int *)x2;
}

//Задание 1. По одному разу.
void task01(void) {
    FILE *in = fopen("task01_in.txt", "r");
    enum size {ALPHABET_SIZE = 25};
    char founded_symbols[100];
    uint8_t count_first_word[ALPHABET_SIZE] = {0};
    uint8_t count_second_word[ALPHABET_SIZE] = {0};

    countSymbols(in, count_first_word, ' ');
    countSymbols(in, count_second_word, EOF);
    fclose(in);
    // printCountAlphabet(count_first_word, 0);
    // printCountAlphabet(count_second_word, 0);
    
    uint8_t j = 0;
    FILE *out = fopen("task01_out.txt", "w");
    for (uint8_t i = 0; i < ALPHABET_SIZE - 1; i++) 
        if (count_first_word[i] == 1 && count_second_word[i] == 1) {
            fputc(i + 'a', out);
        }
    fclose(out);
}

//Задание 2. Заменить a на b.
void task02(void) {
    FILE *in = fopen("task02_in.txt", "r");
    FILE *out = fopen("task02_out.txt", "w");
    char ch;
    while ( (ch = fgetc(in)) != EOF ) {
        switch (ch)
        {
        case 'b':
            fputc('a', out);
            break;
        case 'a':
            fputc('b', out);
            break;
        case 'A':
            fputc('B', out);
            break;
        case 'B':
            fputc('A', out);
            break;
        default:
            fputc(ch, out);
            break;
        }
    }
    fclose(in);
    fclose(out);
}

//Задание 3. Числа в массив.
void task03(void) {
    FILE *in = fopen("task03_in.txt", "r");
    FILE *out = fopen("task03_out.txt", "w");
    char string[1000];
    readStringFromFile(in, string);
    fclose(in);
    const uint16_t SIZE = countDigitsInString(string); //подсчет числе в строке
    int digits[SIZE]; //создаем VLA
    fillArrayByZeroes(digits, SIZE); //заполняем нулями
    readOnlyDigits(string, digits); //считываем только числа из строки в массив digits
    qsort(digits, SIZE, sizeof(int), comparator); //сортируем массив по возрастанию
    for (int i = 0; i < SIZE; i++)
        fprintf(out, "%d ", digits[i]);
    fclose(out);
}

//Задание 4. Удалить повторяющиеся символы.
void task04(void) {
    FILE *in = fopen("task04_in.txt", "r");
    FILE *out = fopen("task04_out.txt", "w");
    enum size {ALPHABET_SIZE = 58};
    uint8_t count_array[ALPHABET_SIZE] = {0};
    countAllSymbols(in, count_array);
    // printAllCountAlphabet(count_array, ALPHABET_SIZE);
    char ch;
    fseek(in, 0, SEEK_SET);
    while ( (ch = fgetc(in)) != EOF ) {
        if (ch != ' ') {
            if ( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ) {
                
                if (count_array[ch - 'A'] != 0) {
                    fputc(ch, out);
                    count_array[ch - 'A'] = 0;
                }
            }
        }
    }
    // printAllCountAlphabet(count_array, ALPHABET_SIZE);
    fclose(in);
    fclose(out);
}

//Задание 5. Самое длинное слово.
void task05(void) {
    FILE *in = fopen("task05_in.txt", "r");
    FILE *out = fopen("task05_out.txt", "w");

    char words[10][100]; //ориентируемся на 10 слов по 100 символов масксимум
    int sizes[10] = {0};
    char ch;
    int counter = 0;
    int j = 0;
    
    while ( (ch = fgetc(in)) != EOF) {
        words[counter][j++] = ch;
        if (ch == ' ') {
            words[counter][j] = '\0';
            counter++;
            j = 0;
        }
    }

    for (int i = 0; i < counter; i++)
        sizes[i] = strlen(words[i]);
    
    fprintf(out, "%s\n", words[find_max(sizes, 10)]);
    
    fclose(in);
    fclose(out);
}

//Задание 6. Заканчивается на а.
void task06(void) {
    FILE *in = fopen("task06_in.txt", "r");
    FILE *out = fopen("task06_out.txt", "w");

    int counter = 0, counter_a = 0;
    int j = 0;
    char ch;
    char words[20][100]; //ориентируемся на 10 слов по 100 символов масксимум

    while ( (ch = fgetc(in)) != EOF) {
        words[counter][j++] = ch;
        if (ch == ' ') {
            words[counter][j] = '\0';
            counter++;
            j = 0;
        }
    }

    for (int i = 0; i < counter; i++)
    {   
        if (words[i][strlen(words[i])-2] == 'a')
            counter_a++;
    }
    
    fprintf(out, "%d ", counter_a);

    fclose(in);
    fclose(out);
}

int main(int argc, char const *argv[])
{
    // task01();
    // task02();
    // task03();
    // task04();
    // task05();
    task06();

    return 0;
}
