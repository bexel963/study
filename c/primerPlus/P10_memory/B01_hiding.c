#include <stdio.h>

int main(void)
{
	int n = 8;

	printf("         ������ n = %d, %p\n", n, &n);
	for (int n = 1; n < 3; n++)
		printf("        loop 1: n = %d, %p\n", n, &n);
	printf("loop 1 ���� ��, n = %d, %p\n", n, &n);

	for (int n = 1; n < 3; n++)
	{
		printf("  loop 2 �ε��� n = %d, %p\n", n, &n);
		int n = 6;
		printf("        loop 2: n = %d, %p\n", n, &n);
		n++;
	}
	printf("loop 2 ���� ��, n = %d, %p\n", n, &n);

	return 0;
}