#include <stdio.h>

void print_rev() {
    char number;
    scanf("%c", &number);
    if (number != '.') 
        print_rev();
    else 
        return;
    printf("%c", number);
}

void print_rev2(int number) {
    printf("%d", number % 10);
    if (number / 10 > 0) {
        print_rev2(number / 10);
    } else
        return;
}

void print_forward(int number) {
    if (number / 10 > 0) print_forward(number / 10);
    printf("%d ", number % 10);  
}

int is2pow(int n) {
    if (n == 1)
        return 1;
    return (n % 2 == 0) && is2pow(n / 2);
}

void sequence(int k) {
    static int counter = 1;
    for (int i = 1; i <= counter; i++) {
        printf("%d ", counter);
        if (--k == 0) {
            counter = 1;
            return;
        }
    }
    counter++;
    sequence(k);
}

int main()
{
    // print_rev();
    
    // int number;
    // scanf("%d", &number);
    // print_rev2(number);
    // print_forward(number);
    // is2pow(1023) ? printf("YES") : printf("NO");
    sequence(11);
    return 0;
}
