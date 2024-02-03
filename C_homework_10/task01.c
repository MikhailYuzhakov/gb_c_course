#include "task01.h"

//читает файл и попарно меняет местами буквы, без учета знаков препинания и пробелов
void readStringFromFile(FILE *file, char *outString, char *inString) {
    fseek(file, 0, SEEK_SET);
    char ch, tmp = 0;
    uint16_t i = 0, j = 0, k = 0;
    stack *chars = NULL;
    while ( (ch = fgetc(file)) != EOF ) {
        inString[k++] = ch;
        if (isChar(ch)) {
            push(&chars, ch);
            i++;
        }
        if (i > 1) {
            outString[j++] = pop(&chars);
            outString[j++] = pop(&chars);
            i = 0;
        }
        
    }
    outString[j] = '\0';
    inString[k] = '\0';
}

//проверяет является ли символ буквой
int isChar(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//пишет в файл с учетом знаков препинаний
void writeToFile(char* inString, char* outString) {
    uint16_t i, j = 0;
    if (access("out_task01.txt", F_OK) == 0)
    {
        FILE *path = fopen("out_task01.txt", "w");
        while (inString[i] != '\0') {
            if (isChar(inString[i])) {
                fputc(outString[j++], path);
            } else {
                fputc(inString[i], path);
            }
            i++;
        }
        fclose(path);
    } else {
        printf("File %s is not exist!", "out_task01.txt");
    }

}

//читает файл, меняет буквы, пишет в файл
FILE* fileOpen(char* path, char *mode)
{
    FILE *file;
    if (access(path, F_OK) == 0) {
        file = fopen(path, mode);
        return file;
    } else {
        printf("File %s is not exist!", path);
        return NULL;
    }
}