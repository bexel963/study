#include <stdio.h>

int main(void)
{
	int reCnt = 0;
	char ch;

	puts("���ڿ� �Է�:");
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

	printf("\n��ü�� Ƚ��: %d\n", reCnt);
}