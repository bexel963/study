#include <stdio.h>
#define YEAR_RATE 0.08

int main(void)
{
	float saving = 1000000;
	const float withdrawal = 100000;
	int year = 0;

	while (saving > 0)
	{
		saving = saving + saving * YEAR_RATE;

		saving -= withdrawal;
		
		year++;
	}

	printf("계좌의 잔고가 없어지는데 걸리는 시간: %d년\n\n", year);

	return 0;
	
}