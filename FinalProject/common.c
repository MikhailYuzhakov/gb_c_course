#include "common.h"
#include "temp_functions.h"

climaticData *monthDataArray[MONTHS_NUMBER];
uint16_t dataArraySizes[MONTHS_NUMBER] = {0};

float* averageMonthsTemp;
int8_t* maxMonthsTemp;
int8_t* minMonthsTemp;
float yearAverageTemp;
int8_t yearMinTemp;
int8_t yearMaxTemp;

int isFileExist(char *path) {
    if ( access(path, F_OK) == 0 )
        return 1;
    else {
        printf("File %s is not exist!\n", path);
        return 0;
    }
}

int isNewMonth(uint8_t month) {
    static int old_month;
    if (month != old_month) {
        old_month = month;
        return 1;
    } else {
        return 0;
    }
}

void printFirstElem(climaticData **data) {
    printf("printFirstElem\n");
    for (uint8_t i = 0; i < MONTHS_NUMBER; i++) {
        printf("%d;%d;%d;%d;%d;%d\n", data[i][10].year, data[i][10].month, data[i][10].day, data[i][10].hour, data[i][10].min, data[i][10].temperature);
    }
}

char* monthNumberToName(int monthNumber) {
    switch (monthNumber) {
        case JANUARY: return "JAN"; break;
        case FEBRUARY: return "FEB"; break;
        case MARCH: return "MAR"; break;
        case APRIL: return "APR"; break;
        case MAY: return "MAY"; break;
        case JUNE: return "JUN"; break;
        case JULY: return "JUL"; break;
        case AUGUST: return "AUG"; break;
        case SEPTEMBER: return "SEP"; break;
        case OCTOBER: return "OCT"; break;
        case NOVEMBER: return "NOV"; break;
        case DECEMBER: return "DEC"; break;
        default: return "ERROR"; break;
    }
}

void printErrorMessage(uint32_t errorStringNumber, int8_t r, char* errorString) {
    printf("ERROR on string (%d), number of parsing arguments (%d), error string: (%s)\n", errorStringNumber, r, errorString);
}

void printHeader(void) {
    printf("------|---------------------|-----------------|-----------------|\nMonth | Average Temperature | Max Temperature | Min Temperature |\n------|---------------------|-----------------|-----------------|\n");
}

void printMonthStatistic(float* averageMonthsTemp, int8_t* maxMonthTemp, int8_t* minMonthTemp, int8_t monthNumber) {
    printf(" %s  |\t\t%.0f C        |\t%d C\t      |\t%d C        \t|\n", monthNumberToName(monthNumber), averageMonthsTemp[monthNumber], maxMonthTemp[monthNumber], minMonthTemp[monthNumber]);
}

void printAllStatistic(float* averageMonthsTemp, int8_t* maxMonthTemp, int8_t* minMonthTemp, float yearAverageTemp, int8_t yearMinTemp, int8_t yearMaxTemp) {
    printHeader();
    for (uint8_t monthNumber = JANUARY; monthNumber <= DECEMBER; monthNumber++) {
        printMonthStatistic(averageMonthsTemp, maxMonthTemp, minMonthTemp, monthNumber);
    }
    printf("------|---------------------|-----------------|-----------------|\n");
    printf("Average temperature of year:\t%.1f C\n", yearAverageTemp);
    printf("Minimum temperature of year:\t%d C\n", yearMinTemp);
    printf("Maximum temperature of year:\t%d C\n\n", yearMaxTemp);
}

int parseCSV(char *path) {
    FILE *in_file;
    uint16_t year;
    uint8_t day, month, hour, min;
    int8_t temperature, r;
    uint32_t errorStringNumber = 0;
    uint8_t isNewMonthVar = 1;

    if ( isFileExist(path) ) 
        in_file = fopen(path, "r");
    else return 0;

    uint16_t counter = 0;
    while ( (r = fscanf(in_file, "%" SCNu16 ";%" SCNu8 ";%" SCNu8 ";%" SCNu8 ";%" SCNu8 ";%" SCNd8, &year, &month, &day, &hour, &min, &temperature)) > 0) {
        if (r < PARAM_NUMBER) {
            char errorString[50];
            r = fscanf(in_file, "%[^\n]", errorString);
            printErrorMessage(errorStringNumber, r, errorString);
        } else if (isNewMonth(month)) {
                counter = 0;
                monthDataArray[month - 1] = (climaticData*) malloc(BUFFER_SIZE * sizeof(climaticData)); //выделяем буффер для данных на каждый месяц и сохраняем указатель на него
            }
        
        monthDataArray[month - 1][counter].year = year;
        monthDataArray[month - 1][counter].month = month;
        monthDataArray[month - 1][counter].day = day;
        monthDataArray[month - 1][counter].hour = hour;
        monthDataArray[month - 1][counter].min = min;
        monthDataArray[month - 1][counter].temperature = temperature;
        dataArraySizes[month - 1] = ++counter;
        errorStringNumber++;
    }
    fclose(in_file);
    return 1;
}

void calculateAllStatistic() {
    averageMonthsTemp = getMonthsAvegareTemp(monthDataArray, dataArraySizes);
    maxMonthsTemp = getMonthsMaxTemp(monthDataArray, dataArraySizes);
    minMonthsTemp = getMonthsMinTemp(monthDataArray, dataArraySizes);
    yearAverageTemp = getYearAvegareTemp(averageMonthsTemp);
    yearMinTemp = getYearMinTemp(monthDataArray, dataArraySizes);
    yearMaxTemp = getYearMaxTemp(monthDataArray, dataArraySizes);
}

void getYearStatistics(void) {
    printAllStatistic(averageMonthsTemp, maxMonthsTemp, minMonthsTemp, yearAverageTemp, yearMinTemp, yearMaxTemp);
}

void getMonthStatistic(char *month) {
    uint8_t monthNumber = atoi(month) - 1;
    if ( (monthNumber < 0) || (monthNumber > 11) ) return;
    printHeader();
    printMonthStatistic(averageMonthsTemp, maxMonthsTemp, minMonthsTemp, monthNumber);
    printf("------|---------------------|-----------------|-----------------|\n");
}