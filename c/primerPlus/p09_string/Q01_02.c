#include <stdio.h>
#define LEN 20

void getWords(char*, int);

int main(void)
{
	char words[LEN];

	fputs("���ڵ� �Է�: ", stdout);
	getWords(words, 10);
	
	printf("�Է��� ���ڵ�: %s\n", words);
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