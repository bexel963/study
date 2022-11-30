#include <stdio.h>

int main(void)
{
	int n = 3;

	while(n)
		printf("%2d: Âü\n", n--);
	printf("%2d: °ÅÁş\n", n);

	n = -3;

	while (n)
		printf("%2d: Âü\n", n++);
	printf("%2d: °ÅÁş\n", n);

	return 0;
}