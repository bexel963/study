#include <stdio.h>

void chline(char, int, int);

int main(void)
{
	char ch;
	int i, j;

	printf("����� ���� �Է�: ");
	ch = getchar();
	
	printf("���ۿ��� ���� �Է�: ");
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