#include <stdio.h>

int main(void)
{
	int x = 30;

	printf("�ܺ� ��Ͽ� �ִ� x: %d at %p\n", x, &x);

	{
		int x = 77;
		printf("���� ��Ͽ� �ִ� x: %d at %p\n", x, &x);
	}

	printf("�ܺ� ��Ͽ� �ִ� x: %d at %p\n", x, &x);
	
	while (x++ < 33)
	{
		int x = 100;
		x++;
		printf("while ������ �ִ� x: %d at %p\n", x, &x);
	}

	printf("�ܺ� ��Ͽ� �ִ� x: %d at %p\n", x, &x);

	return 0;
}