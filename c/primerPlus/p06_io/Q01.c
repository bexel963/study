#include <stdio.h>

int main(void)
{
	int cnt = 0;
	char ch;

	printf("문자열 입력: ");
	while ((ch=getchar()) != EOF)
	{
		putchar(ch);
		cnt++;
	}

	printf("문자의 개수: %d\n", cnt);
}