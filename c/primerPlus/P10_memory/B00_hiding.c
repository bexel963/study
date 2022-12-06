#include <stdio.h>

int main(void)
{
	int x = 30;

	printf("외부 블록에 있는 x: %d at %p\n", x, &x);

	{
		int x = 77;
		printf("내부 블록에 있는 x: %d at %p\n", x, &x);
	}

	printf("외부 블록에 있는 x: %d at %p\n", x, &x);
	
	while (x++ < 33)
	{
		int x = 100;
		x++;
		printf("while 루프에 있는 x: %d at %p\n", x, &x);
	}

	printf("외부 블록에 있는 x: %d at %p\n", x, &x);

	return 0;
}