#include <stdio.h>

void print(char, int, int);

int main(void)
{
	char ch;
	int col, row;

	printf("����� ���� �Է�: ");
	ch = getchar();
	printf("���� ���� ���ʷ� �Է�: ");
	scanf("%d %d", &col, &row);

	print(ch, col, row);

	return 0;
}

void print(char ch, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			putchar(ch);
		putchar('\n');
	}
}