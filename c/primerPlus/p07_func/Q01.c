#include <stdio.h>

double min(double, double);

int main(void)
{
	double num1, num2;

	printf("�� �Ҽ��� �� �Է�: ");
	scanf("%lf %lf", &num1, &num2);

	printf("�� �� �� �� ���� ���� %.2f�Դϴ�.\n", min(num1, num2));

	return 0;
}

double min(double a, double b)
{
	return a < b ? a : b;
}