#include <stdio.h>

void chline(char, int, int);

int main(void)
{
	char ch;
	int i, j;

	printf("출력할 문자 입력: ");
	ch = getchar();
	
	printf("시작열과 끝열 입력: ");
	scanf("%d %d", &i, &j);

	chline(ch, i, j);

	return 0;
}

void chline(char ch, int i, int j)
{
	for (int k = 0; k < i; k++)
		putchar(' ');
	for (int k = 0; k <= j - i; k++)
		putchar(ch);
	putchar('\n');
}