#include <stdio.h>

void report_count();
void accumulate(int);

int count = 0;

int main(void)
{
	int value;
	register int i;

	printf("양의 정수룰 하나 입력하시오(끝태려면 0): ");
	while (scanf("%d", &value) == 1 && value > 0)
	{
		++count;
		for (i = value; i >= 0; i--)
		{
			accumulate(i);
		}
	}
	report_count();

	return 0;
}
void report_count()
{
	printf("루프가 실행된 횟수: %d\n", count);
}