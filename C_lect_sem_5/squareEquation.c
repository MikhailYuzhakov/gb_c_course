#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

void SquareEquation(void); //функция вычисления корней квадратного уравнения
float InputFloat(char*);
void CalcRealRoots(float, float, float);
void CalcRealRootsLinearEq(float, float);


int main(int argc, char **argv) {
    setlocale(LC_ALL, "Rus");
    char Choice;
    while (1)
    {
        printf("1. Calculation square equation roots\n");
        printf("0. Exit\n");
        printf("Press Q to exit\n");
        Choice = getch(); //не буферезированное считывание команды от пользователя, чтобы отобразить введенный символ getche()
        switch (Choice)
        {
        case '1':
            SquareEquation();
            break;
        case '0':
        case 'Q':
        case 'q':
            return 0;
            break;
        default:
            printf("Not valid answer!\n");
            break;
        }
    }
    
}

void SquareEquation(void) {
    float a, b, c, D;

    printf("Square equation real roots calculation\n");
    a = InputFloat("Enter A coefficient = \n");
    b = InputFloat("Enter B coefficient = \n");
    c = InputFloat("Enter C coefficient = \n");

    if (a != 0) {
        D = b * b - 4 * a * c;
        if (D < 0) printf("Real roots not exist\n");
            else CalcRealRoots(a, b, D);
    } else if (b != 0) CalcRealRootsLinearEq(c, b);
}

float InputFloat(char* message)
{
    static int counter = 0; //можем считать кол-во вызовов функции с помощью статической переменной локальной видимости
    float number;
    printf("%d, %s", counter, message);
    scanf("%f",&number);
    counter++;
    return number;
}

void CalcRealRoots(float a, float b, float D)
{
    float x1,x2;
    printf("Square equation real roots: ");
    D = sqrtf(D);
    x1 = (-b + D) / 2*a;
    printf("x1 = %.2f ", x1);
    x2 = (-b - D) / 2*a;
    printf("x2 = %.2f \n", x2);
}

void CalcRealRootsLinearEq(float c, float b) {
    float x1;
    printf("Linear equation root: ");
    x1 = -c / b;
    printf("%.2f\n", x1);
}