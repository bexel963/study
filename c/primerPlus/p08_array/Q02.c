#include <stdio.h>

void copy_arr(double[], double[], int);
void copy_ptr(double*, double*, int);
void copy_ptr2(double*, double*, double*);
void print(double*);

int main(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5] = { 0 };
	double target2[5] = { 0 };
	double target3[5] = { 0 };

	fputs("source : ", stdout);
	print(source);

	copy_arr(target1, source, 5);
	fputs("target1: ", stdout);
	print(target1);

	copy_ptr(target2, source, 5);
	fputs("target2: ", stdout);
	print(target2);

	copy_ptr2(target3, source, source + 5);
	fputs("target3: ", stdout);
	print(target3);

	return 0;
}

void copy_arr(double target[], double source[], int n)
{
	for (int i = 0; i < n; i++)
		target[i] = source[i];
}
void copy_ptr(double* target, double* source, int n)
{
	for (int i = 0; i < n; i++)
		*(target + i) = *(source + i);
}
void copy_ptr2(double* target, double* source, double* end)
{
	while (source != end)
		*target++ = *source++;		// 증감 연산자가 참조 연산자 보다 우선순위가 높다.
}
void print(double* arr)
{
	for (int i = 0; i < 5; i++)
		printf("%.1f ", arr[i]);
	putchar('\n');
}

