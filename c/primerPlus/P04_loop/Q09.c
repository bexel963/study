#include <stdio.h>

float getCal(float, float);

int main(void)
{
	float f1, f2;
	
	printf("�Ҽ��� �� �� �� �Է�(�������� ���� �Է�): \n");
	while (scanf("%f %f", &f1, &f2))
	{
		printf("%.2f\n", getCal(f1, f2));
		printf("�Ҽ��� �� �� �� �Է�(�������� ���� �Է�): \n");
	}
	puts("����!");

	return 0;

}

float getCal(float f1, float f2)
{
	float mul, sub;

	sub = f1 - f2;
	mul = f1 * f2;

	return sub / mul;
}