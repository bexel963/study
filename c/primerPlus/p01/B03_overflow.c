#include <stdio.h>

int main(void)
{
	int i = 2147483647;
	unsigned int j = 4294967295;

	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);

	printf("\n------------------\n");

	float toobig = 3.4E38 * 100.0f;
	printf("%e\n", toobig);	// �����÷ο� -> inf ���

	printf("\n------------------\n");

	float a, b;
	
	b = 2.0e20 + 1.0;
	a = b - 2.0e20;
	printf("%f\n", a);	// float�� ���� 6~7�ڸ����� ����ϸ鼭, ������ ���� �� ũ�⸦ �����Ѵ�.

	return 0;
}