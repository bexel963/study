#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))
			putchar(ch + 1);
		else
			putchar(ch);
	}
	putchar(ch);	// 버퍼에 남아있는 '\n'을 비운다. => 개행('\n')을 출력한다.

	return 0;
}