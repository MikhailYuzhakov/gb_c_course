#include <stdio.h>
#include <conio.h>

void visible(); //прототип функции
void toUpperCase();
void sumDigitsInString();
void example001();
void example002();

int main () {
    // visible();
    // visible();
    // visible();
    // toUpperCase();
    // sumDigitsInString();
    // example001();
    example002();
}

/**
 * @brief 
 * модификатор static выделяет память под переменную 1 раз и создает глобальную переменную с локальной областью видимости.
 */
void visible() {
    static int a = 5;
    a++;
    printf("%d\n", a);
}

/**
 * @brief 
 * пользуемся свойствами таблицы ASCII и переводим все малые буквы в заглавные прибавляя 0x20
 */
void toUpperCase() {
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c >= 'a' && c <= 'z') {
            putchar(c - 0x20);
        } else {
            putchar(c);
        }
    }
}

/**
 * @brief 
 * пользуемся свойствами ASCII таблицы и считаем сумму все цифр в строке
 */
void sumDigitsInString() {
    char c;
    int sum  = 0;
    while ((c = getchar()) != '\n')
    {
        if (c >= '0' && c <= '9') {
            sum += c - 0x30;
        }
        
    }
    printf("%d\n", sum);
}

/**
 * @brief 
 * Для управление потоками ввода (stdin), вывода (stdout) и ошибок (stderr) используются функции:
 * getchar() — ввод с клавиатуры одного символа
● putchar() — вывод на консоль одного символа
● fgets() — ввод одной строки
● puts() / fputs() — вывод одной строки на консоль
● scanf() — ввод с консоли с форматированием данных
● sscanf() — ввод с из строки с форматированием данных
● printf() — вывод с форматированием данных
 */

void example001() {
    char c;
    while ((c = getchar()) != '.')
    {
        putchar(c);
    }
}

/**
 * @brief 
 * Функция getch() ожидает нажатия клавиши, после которого она сразу же возвращает значение
 */
void example002() {
    char character;
    puts("Exit('.'):");
    do
    {
        character = getch(); // считать введённый со стандартного потока ввода символ
        if (character >= 'a' && character <= 'z') //все символы лежат подряд ‘a’=97, ‘b’=98, ‘c’=99, ...
            putchar('A' + (character-'a'));
        else
            putchar(character);
    } while (character != '.'); // пока введенный символ не точка 
}