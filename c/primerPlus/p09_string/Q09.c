#include <stdio.h>
#include <string.h>
#define LEN 100

void reverse(char*, int);

int main(void)
{
	char words[LEN];
	char revers[LEN];
	int n = 0;

	fputs("���ڿ� �Է�(�������� [enter]�Է�): ", stdout);
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

		fputs("�Է��� ���ڿ�: ", stdout);
		puts(words);

		

		fputs("������ ���ڿ�: ", stdout);
		
		reverse(words, n);

		fputs("\n���ڿ� �Է�(�������� [enter]�Է�): ", stdout);
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