#include <stdio.h>

int main(void)
{
	int evenCnt = 0;
	int oddCnt = 0;
	int evenSum = 0;
	int oddSum = 0;
	int num;

	puts("정수들을 입력하세요(끝내려면 0 입력): ");
	while (scanf("%d", &num))
	{
		if (num == 0)
			break;
		if (num % 2 == 0)
		{
			evenCnt++;
			evenSum += num;
		}			
		else
		{
			oddCnt++;
			oddSum += num;
		}				
	}
	
	printf("짝수의 개수: %d\n짝수의 평균: %.2f\n", evenCnt, (float)evenSum / evenCnt);
	printf("홀수의 개수: %d\n홀수의 평균: %.2f\n", oddCnt, (float)oddSum / oddCnt);

	return 0;
	
}