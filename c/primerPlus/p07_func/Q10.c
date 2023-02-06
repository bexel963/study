// �Ǻ���ġ ���, ����

#include <stdio.h>

int rec_fibo(int);
int rep_fibo(int);

int main(void)
{
	int order;
	int input;

	printf("�Ǻ���ġ ���� �� �� ��° ���ڸ� �˰�ͳ�??: ");
	input = scanf("%d", &order);

	while (input)
	{
		printf("%d ��° ���ڴ� %d�̴�.\n", order, rep_fibo(order));
		printf("�Ǻ���ġ ���� �� �� ��° ���ڸ� �˰�ͳ�??: ");
		input = scanf("%d", &order);
	}
	return 0;
}

int rec_fibo(int n)
{
	if (n <= 2)
		return 1;
	
	return rec_fibo(n - 2) + rec_fibo(n - 1);
}

int rep_fibo(int n)
{
	int a = 1;
	int b = 1;
	int tmp;

	if (n <= 2)
		return 1;
	
	for (int i = 3; i <= n; i++)
	{
		tmp = b;
		b = a + b;
		a = tmp;
	}

	return b;
}