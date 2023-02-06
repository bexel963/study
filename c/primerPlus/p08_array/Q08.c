#include <stdio.h>

void copy_range(double*, double*, int);
void print(double*, int);

int main(void)
{
	double arr[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	double copy[3] = { 0 };
	
	printf("원 본 ");
	print(arr, 7);
	
	copy_range(copy, arr, 3);

	printf("복사본 ");
	print(copy, 3);
}

void copy_range(double* target, double* source, int from)
{
	for (int i = 0; i < 3; i++)
	{
		target[i] = source[from - 1];
		from++;
	}
}
void print(double* arr, int length)
{
	for (int i = 0; i < length; i++)
		printf("%.1f ", arr[i]);
	putchar('\n');
}