#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

void main(void)
{
	int dice, roll;
	int sides, status;

	srand((unsigned int)time(0));
	printf("�ֻ��� �ϳ��� �� ���� �Է��Ͻÿ�(�������� 0).\n");
	while (scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("���� �ֻ����� �� ���Դϱ�?\n");
		if ((status = scanf("%d", &dice)) != 1)
		{
			if (status == EOF)
				break;
			else
			{
				printf("������ �Է��ؾ� �մϴ�.\n");
				printf("�ٽ� �սô�.\n");
				while (getchar() != '\n')
					continue;
				printf("�ֻ��� �ϳ��� ����� �Է��Ͻÿ�(�������� 0).\n");
				continue;
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("%d�� �ֻ��� %d���� ���� ���� �հ谡 %d�Դϴ�.\n", sides, dice, roll);
		printf("�ֻ��� �ϳ��� �� ���� �Է��Ͻÿ�(�������� 0).\n");
	}
	printf("rollem() �Լ��� %d�� ȣ��Ǿ����ϴ�.\n", roll_count);
	printf("����� ���ϴ�.\n");

	return 0;
}