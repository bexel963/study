#include <stdio.h>
#define SPACE ' '

int main(void)
{
	char ch;

	ch = getchar();
	while (ch != '\n')
	{
		if (ch == SPACE)	// 이런 경우를 위한 ctype.h가 있다. p.295
			putchar(ch);
		else
			putchar(ch + 1);
		ch = getchar();
	}

	return 0;
}