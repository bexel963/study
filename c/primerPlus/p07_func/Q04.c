#include <stdio.h>

double get_harmonicAvg(double, double);

int main(void)
{
	double num1, num2;
	

	printf("�Ҽ��� �� �� �� �Է�: ");
	scanf("%lf %lf", &num1, &num2);

	printf("�� ���� ��ȭ ���: %.2f\n", get_harmonicAvg(num1, num2));

	return 0;	
}

double get_harmonicAvg(double num1, double num2)
{
	double reverse_num1, reverse_num2;
	double reverse_avg;
	double avg;

	reverse_num1 = 1 / num1;
	reverse_num2 = 1 / num2;
	reverse_avg = (reverse_num1 + reverse_num2) / 2;
	avg = 1 / reverse_avg;

	return avg;
}