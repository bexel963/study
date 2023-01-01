#include <stdio.h>

int main(void)
{
	int num;

	printf("숫자 하나 입력: ");
	scanf("%d", &num);

	for (int i = 0; i <= 10; i++)
		printf("%d ", num + i);
	putchar('\n');
	putchar('\n');

	return 0;
}