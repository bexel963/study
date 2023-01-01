#include <stdio.h>

int main(void)
{
	int min, max, sum = 0;
	int result;

	printf("정수로 하한과 상한을 입력하시오: ");
	result = scanf("%d %d", &min, &max);

	while (result)
	{
		if (min >= max)
			break;
		int tmp = min;
		for (min; min <= max; min++)
		{
			sum += min * min;
		}
		printf("%d부터 %d까지, 제곱들의 합은 %d\n", tmp*tmp, max*max, sum);
		printf("다음 하한과 상한을 입력하시오: ");
		result = scanf("%d %d", &min, &max);
	}
	puts("종료~");

	return 0;
}