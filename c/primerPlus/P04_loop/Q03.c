#include <stdio.h>

int main(void)
{
	char ch;
	
	for (int i = 1; i <= 6; i++)
	{
		int j;
		int ch;
		for (j=0, ch='F'; j < i; j++, ch--)
		{
			putchar(ch);
		}
		putchar('\n');
	}

	return 0;
}