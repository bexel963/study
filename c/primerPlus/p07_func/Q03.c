#include <stdio.h>

void print(char, int, int);

int main(void)
{
	char ch;
	int col, row;

	printf("출력할 문자 입력: ");
	ch = getchar();
	printf("열과 행을 차례로 입력: ");
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