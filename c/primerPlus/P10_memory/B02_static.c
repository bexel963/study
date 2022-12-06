#include <stdio.h>

void trystat(void);

int main(void)
{
	int count;

	for (count = 1; count <= 3; count++)
	{
		printf("루프 사이클 %d\n", count);
		trystat();
	}

	return 0;
}

void trystat(void)
{ㅣ
	int fade = 1;
	static int stay = 1;

	printf("fade = %d, stay = %d\n", fade++, stay++);
}