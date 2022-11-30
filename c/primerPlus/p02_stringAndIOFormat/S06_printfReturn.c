#include <stdio.h>

int main(void)
{
	int bph2o = 100;
	int rv;

	rv = printf("%d C is water's boiling point.\n", bph2o);
	printf("The printf() function printed %d characters.\n", rv);

	return 0;
}