#include <stdio.h>

int main(void)
{
	float f1, f2;
	float mul, sub;

	printf("�Ҽ��� �� �� �� �Է�(�������� ���� �Է�): \n");
	while (scanf("%f %f", &f1, &f2))
	{
		sub = f1 - f2;
		mul = f1 * f2;

		printf("%.2f\n", sub / mul);
		printf("�Ҽ��� �� �� �� �Է�(�������� ���� �Է�): \n");
	}
	puts("����!");

	return 0;

}