#include <stdio.h>

int main(void)
{
	int cnt = 0;
	char ch;

	printf("���ڿ� �Է�: ");
	while ((ch=getchar()) != EOF)
	{
		putchar(ch);
		cnt++;
	}

	printf("������ ����: %d\n", cnt);
}