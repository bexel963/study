#include <stdio.h>

void large_of(double*, double*);

int main(void)
{
	double num1, num2;

	printf("두 소수점 수 입력: ");
	scanf("%lf %lf", &num1, &num2);

	large_of(&num1, &num2);

	printf("num1: %.2f, num2: %.2f\n", num1, num2);

	return 0;
}

void large_of(double* num1, double* num2)
{
	if (*num1 > *num2)
		*num2 = *num1;
	else
		*num1 = *num2;
}