#include <stdio.h>

int main(void)
{
	char ch;
	int cnt = 0;

	puts("���� �Է�: ");
	while ((ch = getchar()) != '#')
	{
		if (cnt % 8 == 0)
		{
			putchar('\n');
			cnt = 0;
		}		
		if (ch == '\n')
			ch = '\\';
		printf("[%c-%d] ", ch, ch);
		cnt++;
	}

	return 0;
}