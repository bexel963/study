#include <stdio.h>

void mikado(int);

int main(void)
{
	int pooh = 2, bah = 5;

	printf("main()�� �ִ� pooh = %d, &pooh = %p\n", pooh, &pooh);
	printf("main()�� �ִ� bah = %d, &bah = %p\n", bah, &bah);
	
	mikado(pooh);

	return 0;
}

void mikado(int bah)
{
	int pooh = 10;

	printf("mikado()�� �ִ� pooh = %d, &pooh = %p\n", pooh, &pooh);
	printf("mikado()�� �ִ� bah = %d, &bah = %p\n", bah, &bah);
}