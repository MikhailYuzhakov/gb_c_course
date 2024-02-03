#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char datatype;

typedef struct list
{
    datatype value;
    struct list *next;
} stack;

void push(stack**, datatype);
_Bool empty_stack(stack*);
datatype pop(stack**);