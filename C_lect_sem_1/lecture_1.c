#include <stdio.h> //������� �����/������
#include <locale.h> //���������� ��� ����������� �������� �����

int c; //���������� ����������

int main(int argc, char **argv)
{
	int a, b; //��������� ����������
	a = 10;
	b = 10;
	c = a + b;
	printf("c = %d\n", c);
	
	setlocale(LC_ALL,"Rus"); //������ ������ �������
	printf("������� ������� � ������ ������\r");
	printf("\n");
	printf("�������������� ���������\t�����������\n");
	printf("������� ������� \"�������\"\n");
	printf("������� �������� ���� \\ \n");
	//printf("������� �� ����� ������ � ����� ���� \0 ����� ������"); //�� ������� ASCII
	printf("\n������� �� ����� ������ ������� \x3F\n");
	printf("�������� ��������� \a\n");
	return 0;
}
