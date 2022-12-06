#include <stdio.h>

extern void srand(unsigned int);
extern int rand(void);

int main(void)
{
	int count;
	unsigned seed;

	printf("종자값으로 사용할 값을 입력하시오.\n");
	while (scanf("%u", &seed) == 1)
	{
		srand(seed);
		for (count = 0; count < 5; count++)
			printf("%hd\n", rand());
		printf("다음 종자값을 입력하시오(끝내려면 q):\n");
	}
	printf("종료!\n");

	return 0;
}