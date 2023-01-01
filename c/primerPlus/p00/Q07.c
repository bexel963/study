#include <stdio.h>

void smile();

int main(void)
{
	smile();
	smile();
	smile();
	putchar('\n');
	smile();
	smile();
	putchar('\n');
	smile();
	puts("\n\n");

	return 0;
}

void smile()
{
	printf("Smile!");
}