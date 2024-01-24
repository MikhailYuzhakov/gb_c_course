#include <stdio.h>
#include <stdint.h>
#include <string.h>
# define SIZE 30

typedef struct sensor
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t temp;
} sensor;

void addRecord(sensor *info, int number, uint8_t day, uint8_t month, uint16_t year, int8_t temp) {
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].temp = temp;
}

int addInfo(sensor *info) {
    int counter = 0;
    addRecord(info, counter++, 22, 01, 2024, 19);
    addRecord(info, counter++, 19, 01, 2024, 13);
    addRecord(info, counter++, 20, 01, 2024, 11);
    addRecord(info, counter++, 18, 01, 2024, 17);
    addRecord(info, counter++, 21, 01, 2024, 10);
    addRecord(info, counter++, 17, 01, 2024, 7);
    return counter;
}

void print(sensor *info, int number) {
    printf("=======================\n");
    for (uint8_t i = 0; i < number; i++)
        printf("%02d-%02d-%04d temp = %d\n", 
                info[i].day, info[i].month, info[i].year, info[i].temp);
}

void changeIJ(sensor *info, int i, int j) {
    sensor temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

void sortByTemp(sensor *info, int number) {
    for (int i = 0; i < number; i++)
        for (int j = i; j < number; j++)
            if (info[i].temp >= info[j].temp)
                changeIJ(info, i, j);
}

uint32_t dateToInt(sensor *info) {
    return info -> year << 16 | info -> month << 8 | info -> day;
}

void sortByDate(sensor *info, int number) {
    for (int i = 0; i < number; i++)
        for (int j = i; j < number; j++)
            if (dateToInt(info + i) >= dateToInt(info + j))
                changeIJ(info, i, j);
}

int main(int argc, char const *argv[])
{
    sensor info[SIZE];
    int number = addInfo(info);
    print(info, number);
    sortByTemp(info, number);
    print(info, number);
    sortByDate(info, number);
    print(info, number);
    return 0;
}
