#include <stdio.h>

extern int rand(void);

int main(void)
{
	int count;

	for (count = 0; count < 5; count++)
		printf("%hd\n", rand());

	return 0;
}