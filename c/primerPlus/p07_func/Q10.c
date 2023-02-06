// 피보나치 재귀, 루프

#include <stdio.h>

int rec_fibo(int);
int rep_fibo(int);

int main(void)
{
	int order;
	int input;

	printf("피보나치 수열 중 몇 번째 숫자를 알고싶나??: ");
	input = scanf("%d", &order);

	while (input)
	{
		printf("%d 번째 숫자는 %d이다.\n", order, rep_fibo(order));
		printf("피보나치 수열 중 몇 번째 숫자를 알고싶나??: ");
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