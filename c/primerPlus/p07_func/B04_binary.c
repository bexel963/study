#include <stdio.h>

void to_binary(unsigned long n);

void main(void)
{
	unsigned long number;
	printf("���� �ϳ��� �Է��Ͻÿ�(�������� q):\n");
	while (scanf("%ul", &number) == 1)
	{
		printf("2���� ǥ��: ");
		to_binary(number);
		putchar('\n');
		printf("���� �糪�� �Է��Ͻÿ�(�������� q): \n");
	}
	printf("����\n");

	return 0;
}

void to_binary(unsigned long n)
{
	int r;

	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');

	return;
}