#include <stdio.h>

int main(void)
{
	int i = 2147483647;
	unsigned int j = 4294967295;

	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);

	printf("\n------------------\n");

	float toobig = 3.4E38 * 100.0f;
	printf("%e\n", toobig);	// 오버플로우 -> inf 출력

	printf("\n------------------\n");

	float a, b;
	
	b = 2.0e20 + 1.0;
	a = b - 2.0e20;
	printf("%f\n", a);	// float형 수는 6~7자리수만 사용하면서, 지수를 통해 그 크기를 조절한다.

	return 0;
}