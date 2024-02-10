#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define PARAM_NUMBER 6

int   parseCSV(char*);
void  getYearStatistics(void);
void  getMonthStatistic(char*);
void  calculateAllStatistic(void);