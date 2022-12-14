#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollem(int sides)	// 이 파일에서만 사용할 수 있다.
{
	int roll;

	roll = rand() % 6 + 1;	// rand()는 0부터 RAND_MAX 까지 범위의 정수를 만든다. (RAND_MAX는 stdlib.h에 정의되어있고, 일반적으로 INT_MAX와 같다.)
	++roll_count;

	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if (sides < 2)
	{
		printf("면의 개수는 최소한 2가 되어야 한다.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("주사위의 개수는 최소한 1이 되어야 한다.\n");
		return -1;
	}
	for (d = 0; d < dice; d++)
		total += rollem(sides);

	return total;
}