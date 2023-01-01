#include <stdio.h>

int main(void)
{
	int start, end;

	printf("정수 두 개 입력: ");
	scanf("%d %d", &start, &end);

	for (start; start <= end; start++)
	{
		printf("[%5d]\t[%5d]\t[%5d]\n", start, start * start, start * start * start);
	}

	puts("\n");

	return 0;

	
}