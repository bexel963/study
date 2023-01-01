#include <stdio.h>

int main(void)
{
	char input;
	char alpha;
	int line;
	int spc;
	int i;
	int j;

	printf("알파벳 하나 입력(대문자): ");
	scanf("%c", &input);
	
	line = input - 'A' + 1;
	spc = input - 'A';
	
	for (i = 1, spc; i <= line; i++, spc--)
	{
		for (j = 0; j < spc; j++)
		{
			putchar(' ');
		}
		for (j = 0, alpha = 'A'; j < i; j++, alpha++)
		{
			putchar(alpha);
		}
		for (char rev = alpha-1; rev > 'A'; )
		{
			--rev;
			putchar(rev);
		}
		putchar('\n');
	}

	return 0;
}