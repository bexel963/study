#include <stdio.h>
#define LEN 20

void getWords(char*, int);

int main(void)
{
	char words[LEN];

	fputs("문자들 입력: ", stdout);
	getWords(words, 10);
	
	printf("입력한 문자들: %s\n", words);
}

void getWords(char* str, int n)
{
	char ch = ' ';
	int cnt = 0;
	while (cnt < n &&(ch = getchar()) != '\n' && ch != ' ' && ch != '\t')
	{
		*(str++) = ch;
		cnt++;
	}
	*str = '\0';
}