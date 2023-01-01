#include <stdio.h>

int main(void)
{
	int reCnt = 0;
	char ch;

	puts("문자열 입력:");
	while ((ch = getchar()) != '#')
	{
		if (ch == '.')
		{
			putchar('!');
			reCnt++;
		}
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
			reCnt++;
		}
		else
			putchar(ch);
	}

	printf("대체된 횟수: %d\n", reCnt);
}