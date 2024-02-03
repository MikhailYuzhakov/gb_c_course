#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include "stack.h"
#include "task02.h"
#include "task03.h"

void readStringFromFile(FILE*, char*, char*);
FILE* fileOpen(char* path, char *mode);
int isChar(char);
void writeToFile(char*, char*);