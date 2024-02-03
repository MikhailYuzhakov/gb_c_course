#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

typedef struct qlist
{
    datatype value;
    struct qlist *next;
} queue;

_Bool empty_queue(queue*);
datatype dequeue(queue**);
void enqueue(struct qlist**, datatype);
void enqueue_recurs(struct qlist**, datatype);
void print_list(struct qlist*);