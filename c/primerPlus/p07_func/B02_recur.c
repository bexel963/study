#include <stdio.h>
void up_and_down(int);

int main(void)
{
	up_and_down(1);

	return 0;
}

void up_and_down(int n)
{
	printf("Level %d: n狼 皋葛府 林家 %p\n", n, &n);
	
	if (n < 4)
	{
		up_and_down(n + 1);
	}
	printf("Level %d: n狼 皋葛府 林家 %p\n", n, &n);
}