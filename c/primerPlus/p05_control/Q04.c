#include <stdio.h>

int main(void)
{
	int reCnt = 0;
	char ch;

	puts("���ڿ� �Է�:");
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

	printf("��ü�� Ƚ��: %d\n", reCnt);
}