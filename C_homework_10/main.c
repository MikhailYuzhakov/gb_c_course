#include "task01.h"
#include "task02.h"

// Задание №1.  Пары соседних символов.
void task01(void) {
    enum {SIZE = 1000};
    char *path = "in_task01.txt";
    char inString[SIZE];
    char outString[SIZE];
    FILE *file = fileOpen(path, "r");
    readStringFromFile(file, outString, inString);
    fclose(file);
    writeToFile(inString, outString);
}

// Задача 2. Удалить пробелы из текста.
void task02(void) {
    enum {SIZE = 1000};
    char *path_in = "in_task02.txt";
    char *path_out = "out_task02.txt";

    FILE *file = fileOpen(path_in, "r");
    char in_str[SIZE];
    fgets(in_str, SIZE, file);
    fclose(file);
    char *out_str = deleteSpaces(in_str, SIZE); //удаляет лишние пробелы

    file = fileOpen(path_out, "w");
    fputs(out_str, file);
    fclose(file);
}

// Задача 3. Изменить расширение.
void task03(void) {
    enum {SIZE = 1000};
    char *path_in = "in_task03.txt";
    char *path_out = "out_task03.txt";

    FILE *file = fileOpen(path_in, "r");
    char in_str[SIZE];
    fgets(in_str, SIZE, file);
    fclose(file);

    if (isCorrectString(in_str)) {
        changeExtension(in_str);
        file = fileOpen(path_out, "w");
        fputs(in_str, file);
        fclose(file);
    } else {
        printf("Not correct string in input file!");
    }


}

int main(int argc, char const *argv[])
{
    // task01();
    // task02();
    task03();
    return 0;
}
