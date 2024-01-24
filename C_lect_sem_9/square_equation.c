#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

typedef struct Equation {
    enum {COEF_N = 3, ROOT_N = 2} SIZE;
    enum {NO_ROOTS = -1, COMPLEX_ROOTS = 0, C = 2, B = 1, A = 0} ROOTS;
        float coef[COEF_N];
        float roots[ROOT_N];
        int   rootsNumber;
        float sqrD;
        float B;
} Equation;

float inputFloat(const char* message) {
    float number;
    printf("%s", message);
    scanf("%f", &number);
    return number;
}

void input(Equation* equation) {
    const char* str[] = {"Enter a:\n", "Enter b:\n", "Enter c:\n", NULL};
    printf("Square equation roots calculation: ");
    for (int i = 0; i < COEF_N; i++)
        equation -> coef[i] = inputFloat(str[i]);
}

void print(Equation *equation) {
    switch (equation -> rootsNumber)
    {
    case 2:
        printf("Square equation roots \n");
        printf("x1 = %f \n", equation -> roots[0]);
        printf("x2 = %f \n", equation -> roots[1]);
        break;
    case 1: 
        printf("Linear equation root %f\n", equation -> roots[0]);
        break;
    case COMPLEX_ROOTS:
        printf("Square equation roots are complex\n");
        break;
    case NO_ROOTS:
        printf("No roots\n");
    default:
        printf("Roots number error!\n", equation -> rootsNumber);
        break;
    }
}

float sqr(float x) {
    return x * x;
}

void calcRealRoots(Equation *e) {
    float d = sqrtf(e -> sqrD);
    e -> roots[0] = (-e -> B + d) / e -> coef[A];
    e -> roots[1] = (-e -> B - d) / e -> coef[A];
}

void calcRoots(Equation *e) {
    e -> rootsNumber = 0;
    e -> B = e -> coef[B] / 2;
    if (e -> coef[A] != 0) {
        e -> sqrD = sqr(e -> B) - e->coef[A] * e->coef[C];
    if (e->sqrD < 0)
        e->rootsNumber = COMPLEX_ROOTS;
        else {
            e->rootsNumber = 2;
            calcRealRoots(e);
        }
    } else {
        if (e->coef[B] != 0) {
            e->roots[0] = -e->coef[C] / e->coef[B];
            e->rootsNumber = 1;
        } else 
            e->rootsNumber = NO_ROOTS;
    }
}

void calcRootTest(Equation *equation) {
    equation->roots[0] = 1;
    equation->roots[1] = 2;
    equation->rootsNumber = 2;
}

void squareEquation(void) {
    Equation* equation = malloc(sizeof(Equation)); //new в C++ выделяет в куче память под уравнение
    input(equation);
    calcRoots(equation);
    print(equation);
    free(equation);
}

int main(int argc, char const *argv[])
{
    char Choice;
    while (1) {
        printf("1. Square equations root calcultaion\n");
        printf("0. Exit\n");
        printf("Press Q to exit\n");
        Choice = getch();

        switch(Choice) {
            case '1': 
                squareEquation();
                break;
            case '0':
            case 'q':
            case 'Q':
                return 0;
            break;
            default:
                printf("Not valide input!\n");
                break;
        }
    }
    return 0;
}
