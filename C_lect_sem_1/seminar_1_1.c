// Alt + Shift - мультикрусор
// все константы в С это int - после идет неявное преобразование
// NULL

#include <stdio.h>
#include <stdint.h>
#include <locale.h>

int c; //глобальная переменная
char* ellipse[] = { ".--.\n",
					"'--'\n", NULL};

int main(int argc, char **argv) //функция main должна возвращать int 
{
	setlocale(LC_ALL,"Rus");
	//task1();
	//task2();
	//simple_output();
	//print_with_usl();
	print_table();

	

	return 0;
}

void task1() {
	printf("hello \3 world");
}

void task2() {
	printf(".--.\n");
	printf("'--'\n");
	printf(" /\\\n");
	printf("/__\\\n");
	printf("(^._.^)~\n");
	printf("  ____\n");
	printf("<(o.o )>\n");
	printf("  |\\_/|\n");
	printf(" / @ @ \\\n");
	printf("( > \176 < )\n");
	printf(" `>>x<<`\n");
	printf(" /  o  \\\n");
}

void simple_output() {
	for (int i = 0; i < sizeof(ellipse) - 1; i++) {
		printf("%s", ellipse[i]);
	}
}

//условие в цикле означает "пока истина", как только будет NULL
//это будет ложь (ложь это NULL, 0, \0)
void print_with_usl() {
	for (int i = 0; ellipse[i]; i++) {
		printf("%s", ellipse[i]);
	}
}

void print_table() {
	printf("Enter choice:\n");
	printf("1.  Start\n");
	printf("2.  Stop\n");
	printf("3.  Exit\n");
	printf("--------------------------------------------------------------------------\n");
	printf("|  Type  |  Byte(s)   |                         |                        |\n");
	printf("|        |  of memory |                      Min|                     Max|\n");
	printf("--------------------------------------------------------------------------\n");
	printf("|  int8_t|           1|                     -128|                     127|\n");
	printf("| uint8_t|           1|                        0|                     255|\n");
	printf("| int16_t|           2|                   -32768|                   32767|\n");
	printf("|uint16_t|           2|                        0|                   65535|\n");
	printf("| int32_t|           4|              -2147483648|              2147483647|\n");
	printf("|uint32_t|           4|                        0|              4294967295|\n");
	printf("| int64_t|           8|     -9223372036854775808|     9223372036854775807|\n");
	printf("|uint64_t|           8|                        0|    18446744073709551615|\n");
	printf("|   float|           4|           -3,4028235E+38|           3,4028235E+38|\n");
	printf("|  double|           8| -1,7976931348623157E+308| 1,7976931348623157E+308|\n");
}






