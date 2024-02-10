#include "temp_functions.h"

int8_t getMonthMaxTemp(climaticData **data, uint16_t *dataSizes, int month) {
    int8_t maxTemperature = data[month][0].temperature;
    for (uint16_t i = 0; i < dataSizes[month]; i++) {
        if (maxTemperature < data[month][i].temperature) {
            maxTemperature = data[month][i].temperature;
        }
    }
    return maxTemperature;
}

int8_t getMonthMinTemp(climaticData **data, uint16_t *dataSizes, int month) {
    int8_t minTemperature = 127;
    for (uint16_t i = 0; i < dataSizes[month]; i++) {
        if (minTemperature > data[month][i].temperature) {
            minTemperature = data[month][i].temperature;
        }
    }
    return minTemperature;
}

float* getMonthsAvegareTemp(climaticData **data, uint16_t *dataSizes) {
    float *monthsAvgTemp = malloc(MONTHS_NUMBER * sizeof(float));
    int averageTemp = 0;
    for (uint8_t monthNumber = JANUARY; monthNumber <= DECEMBER; monthNumber++) {
        for (uint16_t i = 0; i < dataSizes[monthNumber]; i++) {
            averageTemp += data[monthNumber][i].temperature;
        }
        monthsAvgTemp[monthNumber] = averageTemp / dataSizes[monthNumber];
        averageTemp = 0;
    }
    return monthsAvgTemp;
}

int8_t* getMonthsMaxTemp(climaticData **data, uint16_t *dataSizes) {
    int8_t *monthsMaxTemp = malloc(MONTHS_NUMBER * sizeof(int8_t));
    for (uint8_t monthNumber = JANUARY; monthNumber <= DECEMBER; monthNumber++) {
        monthsMaxTemp[monthNumber] = getMonthMaxTemp(data, dataSizes, monthNumber);
    }
    return monthsMaxTemp;
}

int8_t* getMonthsMinTemp(climaticData **data, uint16_t *dataSizes) {
    int8_t *monthsMinTemp = malloc(MONTHS_NUMBER * sizeof(int8_t));
    for (uint8_t monthNumber = JANUARY; monthNumber <= DECEMBER; monthNumber++) {
        monthsMinTemp[monthNumber] = getMonthMinTemp(data, dataSizes, monthNumber);
    }
    return monthsMinTemp;
}

float getYearAvegareTemp(float* monthsAvgTemp) {
    float averageTemp = 0;
    for (uint8_t i = 0; i < MONTHS_NUMBER; i++) {
        averageTemp += monthsAvgTemp[i];
    }
    averageTemp /= MONTHS_NUMBER;
    return averageTemp;
}

int8_t getYearMaxTemp(climaticData** data, uint16_t *dataSizes) {
    int8_t maxYearTemp = data[0][0].temperature;
    for (uint8_t monthNumber = JANUARY; monthNumber <= DECEMBER; monthNumber++) {
        for (uint16_t i = 0; i < dataSizes[monthNumber]; i++) {
            if (maxYearTemp < data[monthNumber][i].temperature)
                maxYearTemp = data[monthNumber][i].temperature;
        }
    }
    return maxYearTemp;
}

int8_t getYearMinTemp(climaticData** data, uint16_t *dataSizes) {
    int8_t minYearTemp = 100;
    for (uint8_t monthNumber = JANUARY; monthNumber <= DECEMBER; monthNumber++) {
        for (uint16_t i = 0; i < dataSizes[monthNumber]; i++) {
            if (minYearTemp > data[monthNumber][i].temperature)
                minYearTemp = data[monthNumber][i].temperature;
        }
    }
    return minYearTemp;
}