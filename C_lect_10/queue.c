#include "queue.h"

_Bool empty_queue(queue *p)
{
    return p == NULL;
}

datatype dequeue(queue **p)
{
    queue *ptmp = *p;
    datatype c;
    if (empty_queue(*p))
    { // Попытка взять из пустой очереди
        fprintf(stderr, "Error. Queue is empty\n");
        exit(1);
    }
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp);
    return c;
}

void enqueue(struct qlist **pl, datatype data)
{
    struct qlist *ptmp = *pl, *elem;
    elem = malloc(sizeof(struct qlist));
    elem->value = data;
    elem->next = NULL;
    if (*pl == NULL)
    {
        *pl = elem;
        return;
    }
    while (ptmp->next)
        ptmp = ptmp->next;
    ptmp->next = elem;
}

void enqueue_recurs(struct qlist **pl, datatype data)
{
    if (*pl == NULL)
    {
        (*pl) = malloc(sizeof(struct qlist));
        (*pl)->value = data;
        (*pl)->next = NULL;
        return;
    }
    else
    {
        enqueue_recurs(&((*pl)->next), data);
    }
}

void print_list(struct qlist *pl)
{
    while (pl)
    {
        printf("%d ", pl->value);
        pl = pl->next;
    }
    printf("\n");
}
