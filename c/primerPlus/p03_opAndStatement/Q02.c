#include <stdio.h>

int main(void)
{
	int num;

	printf("���� �ϳ� �Է�: ");
	scanf("%d", &num);

	for (int i = 0; i <= 10; i++)
		printf("%d ", num + i);
	putchar('\n');
	putchar('\n');

	return 0;
}