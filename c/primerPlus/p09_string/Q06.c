#include <stdio.h>
#include <stdbool.h>

_Bool is_within(char, char*);

int main(void)
{
	char input;
	char words[20] = "abcdefghijklmn";

	fputs("문자 하나 입력(끝내려면 [enter]): ", stdout);
	while ((input = getchar()) != '\n')
	{
		if (is_within(input, words))
			puts("words에서 입력한 문자 찾음!!!");
		else
			puts("입력한 문자가 words에 없음...");

		while (getchar() != '\n')
			continue;
		fputs("문자 하나 입력(끝내려면 [enter]): ", stdout);
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