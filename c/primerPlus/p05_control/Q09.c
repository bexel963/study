#include <stdio.h>

int main(void)
{
	int divisorCnt;
	int num;

	printf("���� �ϳ� �Է�: ");
	scanf("%d", &num);
	
	for (int i = 2; i <= num; i++)
	{
		divisorCnt = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				divisorCnt++;
		}
		if (divisorCnt == 2)
			printf("%d ", i);
	}

	putchar('\n');
}