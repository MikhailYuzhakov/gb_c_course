#include "task01.h"

int isCorrectString(char *fileContent) {
    uint16_t i = 0;
    int isCorrectString = 1;
    while (fileContent[i] != '\0') {
        isCorrectString &= (fileContent[i] >= 'a' && fileContent[i] <= 'z') || 
                            (fileContent[i] >= 'A' && fileContent[i] <= 'Z') ||
                            (fileContent[i] >= '0' && fileContent[i] <= '9') ||
                            fileContent[i] == '/' || fileContent[i] == '.';
        i++;
    }
    return isCorrectString;
}

void rewriteToHtml(char *ptr) {
    ptr[0] = '.';
    ptr[1] = 'h';
    ptr[2] = 't';
    ptr[3] = 'm';
    ptr[4] = 'l';
    ptr[5] = '\0';
}

void changeExtension(char *string) {
    uint16_t length = strlen(string);
    for (int i = length - 1; i >= 0; i--) {
        if (string[i] == '/') {
            rewriteToHtml(&string[length]);
            return;
        }
        if (string[i] == '.') {
            rewriteToHtml(&string[i]);
            return;
        }
    }
}

