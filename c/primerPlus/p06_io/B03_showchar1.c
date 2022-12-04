#include <stdio.h>

void display(char cr, int lines, int width);

int main(void)
{
	int ch;
	int rows, cols;

	printf("문자 하나와 두 개의 정수를 입력하시오.\n");
	while ((ch = getchar() != '\n'))
	{
		scanf("%d %d", &rows, &cols);
		display(ch, rows, cols);

		while (getchar() != '\n')
			continue;

		printf("또 다른 문자와 두 개의 정수를 입력하시오.\n");
		printf("끝내려면 그냥 '엔터'키를 누르시오.\n");
	}
	printf("안녕~~~\n");

	return 0;
}

void display(char cr, int lines, int width)
{
	int row, col;

	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
		{
			putchar(cr);
		}
		putchar('\n');
	}
}