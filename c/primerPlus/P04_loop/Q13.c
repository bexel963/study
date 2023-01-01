#include <stdio.h>
#define SIZE 8

int main(void)
{
	int arr[SIZE] = { 1 };
	int cnt = 0;

	for (int i = 1; i < SIZE; i++)
	{
		arr[i] = arr[i-1] * 2;
	}

	do {
		printf("%d ", arr[cnt++]);
	} while (cnt < SIZE);

	return 0;
}