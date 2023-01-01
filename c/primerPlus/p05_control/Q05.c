#include <stdio.h>

int main(void)
{
	int reCnt = 0;
	char ch;

	puts("문자열 입력:");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '.':
			putchar('!');
			reCnt++;
			break;
		case '!':
			putchar('!');
			putchar('!');
			reCnt++;
			break;
		default:
			putchar(ch);
			break;
		}
	}

	printf("\n대체된 횟수: %d\n", reCnt);
}