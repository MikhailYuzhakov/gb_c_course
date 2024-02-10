#include "common.h"
#include "temp_functions.h"

void printHelp(void) {
    printf("\nThis program reads temperature readings from a csv file and outputs statistics by month or for 1 year.\n");
    printf("\t[-h]                 to show this message\n");
    printf("\t[-f <path to csv>]   path to parsing csv file\n");
    printf("\t[-m <month number>]  to show statistics by this month\n");
    printf("\t[-a]                 to show statistics by year\n\n");
}

int main(int argc, char * const argv[])
{
    int rez = 0;
    while ( (rez = getopt(argc, argv, "hf:m:a")) != -1 )
        switch (rez) {
            case 'h': printHelp(); break;
            case 'f': {
                parseCSV(optarg); 
                calculateAllStatistic();
                break;
            }
            case 'm': getMonthStatistic(optarg); break;
            case 'a': getYearStatistics(); break;
            case '?': printHelp(); break;
            default: printHelp(); break;
        }
    return 0;
}