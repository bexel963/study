#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
	double x, y, z;

	puts("�� ���� �Է��Ͻÿ�(�������� 0 0): ");
	while (scanf("%lf %lf", &x, &y) == 2 && (x != 0 || y != 0))
	{
		z = x * x - y * y;
		assert(z >= 0);
		printf("������: %f\n", sqrt(z));
		puts("���� �� ���� �Է��Ͻÿ�:");
	}

	puts("����");


	return 0;
}