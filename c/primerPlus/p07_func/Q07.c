#include <stdio.h>
#include <ctype.h>
#define SIZE 50
#define STLEN 10

int get_charOder(char);

int main(void)
{
	char ch;
	int order;

	printf("문자열 입력: ");
	while ((ch = getchar()) != '\n')
	{
		if ((order = get_charOder(ch)) != -1)
		{
			printf("%c는 %d번째 알파벳 입니다.\n", ch, order);
		}
		else
		{
			printf("%c는 알파벳이 아닙니다.\n", ch);
		}
	}

	return 0;
}

int get_charOder(char ch)
{
	if (!isalpha(ch))
		return -1;
	else
	{
		ch = tolower(ch);
		return ch - 96;
	}
}