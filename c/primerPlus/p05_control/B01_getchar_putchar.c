#include <stdio.h>
#define SPACE ' '

int main(void)
{
	char ch;

	ch = getchar();
	while (ch != '\n')
	{
		if (ch == SPACE)	// �̷� ��츦 ���� ctype.h�� �ִ�. p.295
			putchar(ch);
		else
			putchar(ch + 1);
		ch = getchar();
	}

	return 0;
}