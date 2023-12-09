#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

/**
 * @brief 
 * логика работы функции построена на значениеях символов открывающей и закрывающей скобок в таблице ASCII
 * result инкрементируем если поймали ( и декрментируем если поймали )
 * @return true 
 * @return false 
 */
bool isCorrectString(void) {
    char c;
    int result = 0;
    while ((c = getchar()) != '.')
    {
        if (c == '(') result += '(' + 1; //ASCII '(' = 40
        if (c == ')') result -= ')';     //ASCII ')' = 41
        if (result < 0) {
            //первой скобкой написали закрывающую, что недопустимо
            //вариант с послежней скобкой открывающий не случится, т.к. отработает общая сумма
            break;
        }
    }
    //если в result число отличное от нуля, то возрващаем false
    if (result == 0) return true;
        else return false;
}

/**
 * @brief 
 * Задача 5*. Скобки
 */
int main(int args, char** argv) {
    isCorrectString() ? printf("YES") : printf("NO");
    return 0;
}