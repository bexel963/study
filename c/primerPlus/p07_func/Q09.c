// 10진수 -> 2진수
// 10진수 -> 두 번째 인자로 넘긴 수의 진수
// 재귀이용
#include <stdio.h>

void get_convert(int);
void get_multi_convert(int, int);

int main(void)
{
	int num, base;
	int input;
	printf("숫자 하나랑 변환하고 싶은 진법 입력: ");
	input = scanf("%d %d", &num, &base);

	while (input)
	{
		printf("%d는 %d진수로 \"", num, base);
		get_multi_convert(num, base);
		puts("\"이다.");

		printf("숫자 하나랑 변환하고 싶은 진법 입력: ");
		input = scanf("%d %d", &num, &base);
	}
	
	
	return 0;
}

void get_convert(int n)
{
	if (n < 1)
		return;
	
	get_convert(n / 2);
	
	printf("%d", n % 2);
}

void get_multi_convert(int n, int base)
{
	if (base == 2)
	{
		if (n < 1)
			return;

		get_multi_convert(n / 2, base);

		printf("%d", n % 2);
	}
	else if (base == 8)
	{
		if (n < 1)
			return;

		get_multi_convert(n / 8, base);

		printf("%d", n % 8);
	}
	else if (base == 16)
	{
		if (n < 1)
			return;

		get_multi_convert(n / 16, base);

		switch (n % 16)
		{
		case 10:
			putchar('A');
			break;
		case 11:
			putchar('B');
			break;
		case 12:
			putchar('C');
			break;
		case 13:
			putchar('D');
			break;
		case 14:
			putchar('E');
			break;
		case 15:
			putchar('F');
			break;
		default:
			printf("%d", n % 16);
			break;
		}
		
	}
}
