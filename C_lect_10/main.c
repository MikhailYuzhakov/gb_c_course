#include "stack.h"
#include "queue.h"
#include "filesystem.h"

void stack_exp(void)
{
    stack *p = NULL; // Важно для корректной работы присвоить NULL
    for (int i = 1; i <= 5; i++)
        push(&p, i);
    for (int i = 1; i <= 5; i++)
        printf("%d\n", pop(&p)); // 5 4 3 2 1
}

void queue_exp(void)
{
    queue *pq = NULL;
    for (int i = 1; i <= 5; i++)
        enqueue(&pq, i);
    for (int i = 1; i <= 5; i++)
        printf("%d\n", dequeue(&pq));
}

void test_filesystem(void)
{
    char dir[PATH_LENGTH], buf[PATH_LENGTH];
    printf("Input dir: ");
    scanf(STR255, dir);
    convert_path_to_full(buf, dir);
    printf("ls for folder %s\n", buf);
    ls(dir);
}

int main(int argc, char const *argv[])
{
    // stack_exp();
    // queue_exp();
    test_filesystem();
    return 0;
}
