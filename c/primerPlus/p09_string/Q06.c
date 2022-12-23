#include <stdio.h>
#include <stdbool.h>

_Bool is_within(char, char*);

int main(void)
{
	char input;
	char words[20] = "abcdefghijklmn";

	fputs("���� �ϳ� �Է�(�������� [enter]): ", stdout);
	while ((input = getchar()) != '\n')
	{
		if (is_within(input, words))
			puts("words���� �Է��� ���� ã��!!!");
		else
			puts("�Է��� ���ڰ� words�� ����...");

		while (getchar() != '\n')
			continue;
		fputs("���� �ϳ� �Է�(�������� [enter]): ", stdout);
	}
}

_Bool is_within(char ch, char* str)
{
	int idx = 0;
	while (str[idx] != ch && str[idx] != '\0')
		idx++;
	if (str[idx] == ch)
		return true;
	else
		return false;
}