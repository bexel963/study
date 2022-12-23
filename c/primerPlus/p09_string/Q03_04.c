#include <stdio.h>
#define LEN 80

char* getword(char*, int);

int main(void)
{
	char input[LEN];

	while (getword(input, 10) != NULL)
		puts(input);
	puts("Done.\n");

	return 0;
}
char* getword(char* str, int n)
{
	int ch;
	char* orig = str;
	int cnt = 0;
	while ((ch = getchar()) != EOF && isspace(ch) && cnt++ < n-1)
		continue;
	if (ch == EOF)
		return NULL;
	else
		*str++ = ch;

	while ((ch = getchar()) != EOF && !isspace(ch) && cnt++ < n-1)
		*str++ = ch;
	*str = '\0';
	if (ch == EOF)
		return NULL;
	else
	{
		while (ch != '\n')
			ch = getchar();
		return orig;
	}
}