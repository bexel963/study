#include <stdio.h>
#include <string.h>
#define LEN 100

void reverse(char*, int);

int main(void)
{
	char words[LEN];
	char revers[LEN];
	int n = 0;

	fputs("문자열 입력(끝내려면 [enter]입력): ", stdout);
	while (fgets(words, 10, stdin) != NULL && words[0] != '\n')
	{
		int i = 0;
		while (words[i] != '\n' && words[i] != '\0')
		{
			i++;
		}
		if (words[i] == '\n')
			words[i] = '\0';
		else
			while (getchar() != '\n')
				continue;

		fputs("입력한 문자열: ", stdout);
		puts(words);

		

		fputs("뒤집은 문자열: ", stdout);
		
		reverse(words, n);

		fputs("\n문자열 입력(끝내려면 [enter]입력): ", stdout);
	}
}

void reverse(char* words, int n)
{
	int length = strlen(words);
	if (n >= length)
	{
		return;
	}
	
	reverse(words, n + 1);

	putchar(words[n]);
}