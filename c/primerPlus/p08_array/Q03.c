#include <stdio.h>

int getMax(int*);

int main(void)
{
	int arr[5] = { 3, 4, 2, 9, 1 };

	printf("가장 큰 값: %d\n", getMax(arr));
	return 0;
}

int getMax(int* arr)
{
	int max = *arr;
	
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return max;
}