#include <stdio.h>

int main(void)
{
	char ch;
	int cnt = 0;

	printf("���ڿ� �Է�: ");
	while ((ch = getchar()) != EOF)
	{		
		if (cnt % 10 == 0)

			putchar('\n');

		if (ch == '\n')
			printf("\\n[%d]\n", ch);
		else if (ch == '\t')
			printf("\\t[%d] ", ch);
		else
			printf("%c[%d] ", ch, ch);

		cnt++;
	}

	return 0;
}