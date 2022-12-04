#include <stdio.h>

void to_binary(unsigned long n);

void main(void)
{
	unsigned long number;
	printf("정수 하나를 입력하시오(끝내려면 q):\n");
	while (scanf("%ul", &number) == 1)
	{
		printf("2진수 표기: ");
		to_binary(number);
		putchar('\n');
		printf("정수 사나를 입력하시오(끝내려면 q): \n");
	}
	printf("종료\n");

	return 0;
}

void to_binary(unsigned long n)
{
	int r;

	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');

	return;
}