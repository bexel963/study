#include <stdio.h>

int main(void)
{
	int constant;
	float sum1 = 0, sum2 = 0;
	int result;
	int negative = 1;

	printf("�� �� �Է�(�������� 0 �Ǵ� ���� �Է�): ");
	result = scanf("%d", &constant);

	while (result)
	{
		if (constant <= 0)
			break;
		int i;
		float denominator;
		for (i = 0, denominator=1.0; i < constant; i++, denominator++)
		{
			sum1 += 1.0 / denominator;
		}
		for (i = 0, denominator = 1.0; i < constant; i++, denominator++)
		{
			sum2 += 1.0 / denominator * negative;
			negative *= -1;
		}
		
		printf("%d�� ������ ��(sum1): %10.4f\n", constant, sum1);
		printf("%d�� ������ ��(sum2): %10.4f\n", constant, sum2);

		printf("�� �� �Է�(�������� 0 �Ǵ� ���� �Է�): ");
		result = scanf("%d", &constant);
	}
	puts("����~");
	return 0;
}