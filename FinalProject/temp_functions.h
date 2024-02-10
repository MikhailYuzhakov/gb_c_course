#include "common.h"

#define MONTHS_NUMBER 12
#define DAYS_NUMBER 31
#define BUFFER_SIZE 50000

typedef struct climaticData {
    uint16_t year;
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t min;
    int8_t temperature;
} climaticData;

enum Months {
    JANUARY = 0,
    FEBRUARY = 1,
    MARCH = 2,
    APRIL = 3,
    MAY = 4,
    JUNE = 5,
    JULY = 6,
    AUGUST = 7,
    SEPTEMBER = 8,
    OCTOBER = 9,
    NOVEMBER = 10,
    DECEMBER = 11
};

float*    getMonthsAvegareTemp(climaticData**, uint16_t*);
int8_t*   getMonthsMaxTemp(climaticData**, uint16_t*);
int8_t*   getMonthsMinTemp(climaticData**, uint16_t*);
float     getYearAvegareTemp(float*);
int8_t    getYearMinTemp(climaticData**, uint16_t*);
int8_t    getYearMaxTemp(climaticData**, uint16_t*);