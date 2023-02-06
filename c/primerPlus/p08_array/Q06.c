#include <stdio.h>

void reverseArr(double*, double*);
void print(double*);

int main(void)
{
	double arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double reverse[5] = { 0 };

	fputs("원본: ", stdout);
	print(arr);

	reverseArr(arr, reverse);

	fputs("반전: ", stdout);
	print(reverse);

	return 0;
}

void reverseArr(double* arr, double* rev)
{
	for (int i = 0; i < 5; i++)
		rev[i] = arr[4 - i];
}
void print(double* arr)
{
	for (int i = 0; i < 5; i++)
		printf("%.1f ", arr[i]);
	putchar('\n');
}
