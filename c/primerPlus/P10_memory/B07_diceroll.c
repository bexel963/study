#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollem(int sides)	// �� ���Ͽ����� ����� �� �ִ�.
{
	int roll;

	roll = rand() % 6 + 1;
	++roll_count;

	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if (sides < 2)
	{
		printf("���� ������ �ּ��� 2�� �Ǿ�� �Ѵ�.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("�ֻ����� ������ �ּ��� 1�� �Ǿ�� �Ѵ�.\n");
		return -1;
	}
	for (d = 0; d < dice; d++)
		total += rollem(sides);

	return total;
}