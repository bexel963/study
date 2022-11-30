#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	unsigned long num;
	unsigned long div;  // ���
	bool isPrime;		// �Ҽ� �÷���

	printf("�˻��� ������ �ϳ� �Է��Ͻÿ�.");
	printf("(�������� q)\n");
	while (scanf("%lu", &num) == 1)
	{
		for (div = 2, isPrime = true; (div * div) <= num; div++) {
			if (num % div == 0)
			{
				if ((div * div != num))
				{
					printf("%lu, %lu: �� �� %lu�� ����̴�.\n", div, num / div, num);
				}
				else {
					printf("%lu: %lu�� �����.\n", div, num);
				}
				isPrime = false;
			}
		}
		if (isPrime)
			printf("%lu: �Ҽ���.\n", num);
		printf("�˻��� �� �ٸ� ������ �ϳ� �Է��Ͻÿ�(�������� q)\n");
	}
	printf("�ȳ�!\n");

	return 0;
}