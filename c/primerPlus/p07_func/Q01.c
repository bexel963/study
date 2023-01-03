#include <stdio.h>

double min(double, double);

int main(void)
{
	double num1, num2;

	printf("두 소수점 수 입력: ");
	scanf("%lf %lf", &num1, &num2);

	printf("두 수 중 더 작은 값은 %.2f입니다.\n", min(num1, num2));

	return 0;
}

double min(double a, double b)
{
	return a < b ? a : b;
}