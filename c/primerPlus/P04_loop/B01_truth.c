#include <stdio.h>

int main(void)
{
	int n = 3;

	while(n)
		printf("%2d: ��\n", n--);
	printf("%2d: ����\n", n);

	n = -3;

	while (n)
		printf("%2d: ��\n", n++);
	printf("%2d: ����\n", n);

	return 0;
}