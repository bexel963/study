#include <stdio.h>
#include <ctype.h>
#define SIZE 50
#define STLEN 10

int get_charOder(char);

int main(void)
{
	char ch;
	int order;

	printf("���ڿ� �Է�: ");
	while ((ch = getchar()) != '\n')
	{
		if ((order = get_charOder(ch)) != -1)
		{
			printf("%c�� %d��° ���ĺ� �Դϴ�.\n", ch, order);
		}
		else
		{
			printf("%c�� ���ĺ��� �ƴմϴ�.\n", ch);
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