#include <stdio.h>
#define SIZE 5

void getPlusArr(int*, int*, int*, int);
void print(int*, int);

int main(void)
{
	int arr1[SIZE] = { 1, 2, 3, 4, 5 };
	int arr2[SIZE] = { 1, 2, 3, 4, 5 };
	int plus[SIZE] = { 0 };

	getPlusArr(arr1, arr2, plus, SIZE);

	printf("arr1: ");
	print(arr1, SIZE);
	printf("arr2: ");
	print(arr2, SIZE);
	printf("plus: ");
	print(plus, SIZE);
}

void getPlusArr(int* arr1, int* arr2, int* copy, int size)
{
	for (int i = 0; i < size; i++)
		copy[i] = arr1[i] + arr2[i];
}
void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%2d ", arr[i]);
	putchar('\n');
}