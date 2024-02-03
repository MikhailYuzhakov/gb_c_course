#include "task01.h"

char* deleteSpaces(char* str, uint16_t size) {
    char *dst = malloc(size * sizeof(str));
    uint16_t i = 0, j = 0, spacesNumber = 0;
    while (str[i] != '\0')
    {
        //удаляем все пробелы вначале строки
        if (i == 0) {
            while (str[i] == ' ') i++;
        }

        //удаляем все пробелы, но потом добавляем 1
        while (str[i] == ' ') {
            i++;
            spacesNumber++;
        }
        if (spacesNumber > 0) dst[j++] = ' ';
        spacesNumber = 0;

        dst[j++] = str[i++];
    }
    dst[j] = '\0';
    return dst;
}
