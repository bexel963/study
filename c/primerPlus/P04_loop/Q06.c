#include <stdio.h>

int main(void)
{
	int start, end;

	printf("���� �� �� �Է�: ");
	scanf("%d %d", &start, &end);

	for (start; start <= end; start++)
	{
		printf("[%5d]\t[%5d]\t[%5d]\n", start, start * start, start * start * start);
	}

	puts("\n");

	return 0;

	
}