#include <stdio.h>

double getMaxMinDif(double*);

int main(void)
{
	double arr[5] = { 3.3, 5.5, 1.1, 8.8, 2.2 };

	printf("가장 큰 값과 가장 작은 값의 차: %.1f\n", getMaxMinDif(arr));

	return 0;
}

double getMaxMinDif(double* arr)
{
	double max = *arr;
	double min = *arr;

	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	return max - min;
}