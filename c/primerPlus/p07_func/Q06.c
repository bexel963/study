#include <stdio.h>

void three_sort(double*, double*, double*);
void swap(double*, double*);

int main(void)
{
	double num1, num2, num3;

	printf("�� ���� �Ҽ��� �� �Է�: ");
	scanf("%lf %lf %lf", &num1, &num2, &num3);

	three_sort(&num1, &num2, &num3);

	printf("������: %.1f\n�߰���: %.1f\nū��: %.1f\n", num1, num2, num3);
	
	return 0;
}

void three_sort(double* num1, double* num2, double* num3)
{
	if (*num1 > *num2)
		swap(num1, num2);
	if (*num2 > *num3)
		swap(num2, num3);
	if (*num1 > *num2)
		swap(num1, num2);
}
void swap(double* d1, double* d2)
{
	double tmp;
	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}