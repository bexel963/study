#include <stdio.h>

extern int count;

static int total = 0;
void accumulate(int);

void accumulate(int k)
{
	static int subtotal = 0;

	if (k <= 0)
	{
		printf("루프 사이클: %d\n", count);
		printf("소계: %d; 합계: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}
}