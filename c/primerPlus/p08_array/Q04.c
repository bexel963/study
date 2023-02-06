#include <stdio.h>

int getMaxIdx(double*);

int main(void)
{
	double arr[5] = { 3.3, 5.5, 1.1, 8.8, 2.2 };

	printf("가장 큰 값의 인덱스: %d\n", getMaxIdx(arr));

	return 0;
}

int getMaxIdx(double* arr)
{
	double max = *arr;
	int idx;

	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			idx = i;
		}
	}

	return idx;
}