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

	printf("������ �ܰ� �������µ� �ɸ��� �ð�: %d��\n\n", year);

	return 0;
	
}