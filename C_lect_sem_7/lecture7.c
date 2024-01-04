
// Online C Compiler - Build, Compile and Run your C programs online in your favorite browser

#include<stdio.h>

void exmpl001(void) {
    int x = 10;
    int *p_x; //определяем указатель
    p_x = &x;
    printf("%p \n", p_x);
}

//так делать не надо (выход за границы памяти)
void exmpl002(void) {
    char c = 'N';
    char *pc = &c;
    int *pd = (int *)pc;
    printf("%d", (int*)pd); //печатаем то, что находится в указателе
}

void dereference_operator(void) {
    int x = 10;
    int *p = &x;
    int y = *p; //разыменование
    printf("Address x = %p\n Value x = %d\n", (void*) p, x);
    printf("Address y = %p\n Value y = %d", &y, y);
}

void exmpl003(void) {
    int x = 10;
    int *p = &x;
    *p = 45; //положили в указатель число
    printf("x = %d\n", x);
}

//можно объявлять указатель на указатель
void exmpl004(void) {
    int a = 77;
    int *ptrA = &a;
    int **ppA = &ptrA;
    *ptrA = 88;
    printf("a = %d\n", a);
    **ppA = 99;
    printf("a = %d\n", a);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
}

int main()
{
    // exmpl001();
    // exmpl002();
    // dereference_operator();
    // exmpl003();
    // exmpl004();
    int n = 7, m = 5;
    swap(&n, &m);
    printf("n = %d, m = %d\n", n, m);
}
