#include <stdio.h>
#include <math.h>

void print_array(char*, int*, int);
void swap(int*, int*);
void fill_array_by_zero(int, int*);
int find_min_array(int, int*);
int find_min_ptr_array(int, int*);
int find_max_ptr_array(int, int*);
void print_matrix(int, int, int**);
float average(int, int*);
int return_bool(int, int);

void task01(void);
void sort_array(int, int*);
void task02(void);
void sort_even_odd(int, int*);
int odd_counter(int*, int);
void task03(void);
int find_max_array(int, int*);
void task04(void);
int is_two_same(int, int*);
void task05(void);
void change_max_min(int, int*);
void task06(void);
void task07(void);

int main(int argc, char **argv)
{
	//task01();
	//task02();
	//task03();
	//task04();
	//task05();
	//task06();
	task07();
	return 0;
}

//Задание 1. Сортировка массива по возрастанию
void task01(void) {
	enum {SIZE01 = 11, SIZE02 = 20};
	int test_arr01[SIZE01] = {4, 5, 1, -6, 12, 765, -95, 13, 1, 0, -67};
	int test_arr02[SIZE02] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -9 -10};
	print_array("test_arr01 : ", test_arr01, SIZE01);
	print_array("test_arr02 : ", test_arr02, SIZE02);
	
	sort_array(SIZE01, test_arr01);
	sort_array(SIZE02, test_arr02);
	print_array("test_arr01_sorted : ", test_arr01, SIZE01);
	print_array("test_arr02_sorted : ", test_arr02, SIZE02);
}

void sort_array(int size, int array[]) {
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (array[i] > array[j])
				swap(&array[i], &array[j]);
}			

//Задание 2. Сперва четные.
void task02(void) {
	enum {SIZE01 = 11, SIZE02 = 20};
	//int test_arr01[SIZE01] = {4, 5, 1, -6, 12, 765, -95, 13, 1, 0, -67};
	int test_arr02[SIZE02] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//print_array("test_arr01 : ", test_arr01, SIZE01);
	print_array("test_arr02 : ", test_arr02, SIZE02);
	
	//sort_even_odd(SIZE01, test_arr01); не работает с отрицательными элементами??
	sort_even_odd(SIZE02, test_arr02);
	//print_array("test_arr01_sorted : ", test_arr01, SIZE01);
	print_array("test_arr02_sorted : ", test_arr02, SIZE02);
}

void sort_even_odd(int size, int* array) {
	int odd_index = 0;
	int even_index = 0;
	int even_array_size = odd_counter(array, size); //индекс с которого вставляем в исходный массив содержимое even_array
	int even_array[even_array_size];
	
	//собираем все нечетные элементы в отдельный подмассив
	for (int i = 0; i < size; i++)
		if (array[i] % 2 != 0) 
			even_array[even_index++] = array[i];
	
	//сортируем так, чтобы четные оказались в начале исходного массива
	for (int i = 0; i < size; i++) 
		if (array[i] % 2 == 0) 
			swap(&array[odd_index++], &array[i]); //четные ставим в начало исходного массива

	even_index = 0; //для повторного использования
	//дописываем в конец массива нечетные
	for (int i = even_array_size; i < size; i++)
		array[i] = even_array[even_index++];
}

//Задание 3. Найти максимальный элемент в массиве.
void task03(void) {
	enum {SIZE01 = 11, SIZE02 = 20};
	int test_arr01[SIZE01] = {4, 5, 1, -6, 12, 765, -95, 13, 1, 0, -67};
	int test_arr02[SIZE02] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	print_array("test_arr01 : ", test_arr01, SIZE01);
	print_array("test_arr02 : ", test_arr02, SIZE02);
	printf("\nmax_element test_arr01 : %d\n", find_max_array(SIZE01, test_arr01));
	printf("max_element test_arr02 : %d\n", find_max_array(SIZE02, test_arr02));
}

int find_max_array(int size, int* array) {
	int max_ptr = 0;
	for (int i = 0; i < size; i++)
		if (array[i] > array[max_ptr])
			max_ptr = i;
	return array[max_ptr];
}

int find_min_array(int size, int* array) {
	int min_ptr = 0;
	for (int i = 0; i < size; i++)
		if (array[i] < array[min_ptr])
			min_ptr = i;
	return array[min_ptr];
}

int find_max_ptr_array(int size, int* array) {
	int max_ptr = 0;
	for (int i = 0; i < size; i++)
		if (array[i] > array[max_ptr])
			max_ptr = i;
	return max_ptr;
}

int find_min_ptr_array(int size, int* array) {
	int min_ptr = 0;
	for (int i = 0; i < size; i++)
		if (array[i] < array[min_ptr])
			min_ptr = i;
	return min_ptr;
}

//Задание 4. Два одинаковых.
void task04(void) {
	enum {SIZE01 = 10, SIZE02 = 20};
	int test_arr01[SIZE01] = {4, 5, 1, -6, -4, 10, -10, 7, -1, 0};
	int test_arr02[SIZE02] = {20, 19, 19, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	print_array("test_arr01 : ", test_arr01, SIZE01);
	is_two_same(SIZE01, test_arr01) ? printf("YES\n") : printf("NO\n");
	print_array("test_arr02 : ", test_arr02, SIZE02);
	is_two_same(SIZE02, test_arr02) ? printf("YES\n") : printf("NO\n");
}

//реализует подсчет элементов массива с учетом отрицательных элементов
int is_two_same(int size, int* array) {
	int max_size = find_max_array(size, array) + 1;
	int min_size = find_min_array(size, array);
	int count_array_size = abs(max_size) + abs(min_size);
	int count_array[count_array_size];
	fill_array_by_zero(count_array_size, count_array);
	
	for (int i = 0; i < size; i++) {
		if (array[i] < 0) {
			count_array[abs(abs(array[i]) - abs(min_size))]++;
		} else {
			count_array[array[i] + abs(min_size)]++;
		}
	}
	print_array("count_array : ", count_array, count_array_size);
	for (int i = 0; i < count_array_size; i++)
		if (count_array[i] > 1)
			return 1;
	return 0;
}

//Задание 5. Поменять местами.
void task05(void) {
	enum {SIZE01 = 10, SIZE02 = 20};
	int test_arr01[SIZE01] = {4, 5, 1, -6, -4, 10, -10, 7, -1, 0};
	int test_arr02[SIZE02] = {20, 19, 19, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	print_array("test_arr01 : ", test_arr01, SIZE01);
	change_max_min(SIZE01, test_arr01);
	print_array("changed_test_arr01 : ", test_arr01, SIZE01);
	
	print_array("test_arr02 : ", test_arr02, SIZE02);
	change_max_min(SIZE02, test_arr02);
	print_array("changed_test_arr02 : ", test_arr02, SIZE02);
}

//Задание 6. Больше среднего.
void task06(void) {
	enum {SIZE_X = 5, SIZE_Y = 5};
	int matrix[SIZE_X][SIZE_Y] = {{1, 1, 1, 1, 1},
								  {2, 2, 2, 2, 2},
								  {3, 3, 3, 3, 3},
								  {4, 4, 4, 4, 4},
								  {5, 5, 5, 5, 5}};
	int main_diagonal[SIZE_X];
	
	for (int i = 0; i < SIZE_X; i++) {
		for (int j = 0; j < SIZE_Y; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	
	int k = 0;
	for (int i = 0; i < SIZE_X; i++)
		for (int j = 0; j < SIZE_Y; j++)
			if (i == j) main_diagonal[k++] = matrix[i][j];
	print_array("main_diagonal : ", main_diagonal, SIZE_X);
	
	float average_value = average(SIZE_X, main_diagonal);
	printf("\naverage of main diag = %.2f\n", average_value);
	
	int counter = 0;
	for (int i = 0; i < SIZE_X; i++) {
		for (int j = 0; j < SIZE_Y; j++)
			if (matrix[i][j] > average_value)
				counter++;
	}
	printf("elements count greater than main diagonal average value (%.2f) is %d pcs\n", average_value, counter);
}

//Задание 7*. Клетки.
void task07(void) {
	char* input = {"H5"};
	int letter = input[0] - 'A' + 1;
	int digit = input[1] - '0';
	printf("position %s translate to : letter = %d, digit = %d\n", input, letter, digit);
	
	return_bool(letter, digit) ? printf("BLACK\n") : printf("WHITE\n"); 
}

//логика - если и буква, и цифра четные или нечетные - клетка точно черная
//при любых других комбанациях клетка точно белая
int return_bool(int letter, int digit) {
	if (((letter % 2) && (digit % 2)) | (!(letter % 2) && !(digit % 2)))
		return 1; //черная
	return 0; //белая
}

float average(int size, int* array) {
	float average;
	for (int i = 0; i < size; i++)
		average += array[i];
	return average /= size;
}

void change_max_min(int size, int* array) {
	swap(&array[find_max_ptr_array(size, array)], &array[find_min_ptr_array(size, array)]);
}

void fill_array_by_zero(int size, int* array) {
	for (int i = 0; i < size; i++)
		array[i] = 0;
}

int odd_counter(int* array, int size) {
	int counter = 0;
	for (int i = 0; i < size; i++)
		if (array[i] % 2 == 0) counter++;
	return counter;
}

void print_array(char* msg, int *arr, int length) {
	printf("%s", msg);
	int i = 0;
	while (i < length)
		printf("%d ", arr[i++]);
	printf("\n");
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
