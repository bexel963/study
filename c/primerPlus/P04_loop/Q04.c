#include <stdio.h>

int main(void)
{
	int i;
	char ch = 'A';
	for (i = 1; i <= 6; i++)
	{
		int j;
		for (j = 0; j < i; j++)
			putchar(ch++);
		putchar('\n');
	}

	return 0;
}