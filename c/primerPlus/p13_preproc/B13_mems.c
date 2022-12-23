#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10

void show_array(const int[], int);

int main(void)
{
	int values[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int target[SIZE];
	double curious[SIZE / 2] = { 2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30 };

	puts("memcpy() ���:");
	puts("values �迭�� ��(���� ������):");
	show_array(values, SIZE);
	memcpy(target, values, SIZE * sizeof(int));
	puts("target �迭�� ��(�纻 ������):");
	show_array(target, SIZE);

	puts("\n��ġ�� ������ ���� �� memmove() ���:");
	memmove(values + 2, values, 5 * sizeof(int));
	puts("target �迭�� ��(���� 0~5�� ���� 2~7�� ����):");
	show_array(values, SIZE);

	puts("\ndouble���� int������ ������ �� memcpy() ���:");
	memcpy(target, curious, (SIZE / 2) * sizeof(double));
	puts("target �迭�� ��(5���� double�� ���� 10���� int�� ��ġ�� ����):");
	show_array(target, SIZE);
	show_array(target + 5, SIZE / 2);

	return 0;
	
}

void show_array(const int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", ar[i]);
	putchar('\n');
}