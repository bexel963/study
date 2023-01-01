#include <stdio.h>
#define NORMAL 0.15
#define OVER 0.28
#define CELIBACY_LIMIT 17850;
#define HEAD_LIMIT 23900;
#define DUO_LIMIT 29750;
#define SOLO_LIMIT 14875;

int menu();
float taxCal(int, float);

void main(void)
{
	int select = 0;
	float income = 0;
	int limit = 0;
	float tax = 0;

	while ((select = menu()) != 0)
	{
		if (select > 4)
		{
			puts("�ٽ� �Է��� �ּ���(1~4)");
			continue;
		}
		printf("�ҵ� �Է�: ");
		scanf("%f", &income);
		
		switch (select)
		{
		case 1:
			limit = CELIBACY_LIMIT;
			break;
		case 2:
			limit = HEAD_LIMIT;
			break;
		case 3:
			limit = DUO_LIMIT;
			break;
		case 4:
			limit = SOLO_LIMIT;
			break;
		}
		tax = taxCal(limit, income);

		printf("�ش� �ҵ濡 ���� ����: %.2f\n", tax);
	}
	
	puts("����~~~");

	return 0;
}

int menu()
{
	int input;
	puts("--------------------------------------------------------------");
	printf("���� ����  \t\t\t����\n");
	printf("1) ����       \t\t\t$17,850���� 15%%, �ʰ����� 28%%\n");
	printf("2) ����       \t\t\t$23,900���� 15%%, �ʰ����� 28%%\n");
	printf("3) �¹���, �ջ�\t\t\t$29,750���� 15%%, �ʰ����� 28%%\n");
	printf("4) �¹���, ����\t\t\t$14,875���� 15%%, �ʰ����� 28%%\n");
	puts("--------------------------------------------------------------");
	printf("���� ���� �Է�(�������� 0�Է�): ");
	scanf("%d", &input);

	return input;
}

float taxCal(int limit, float income)
{
	if (income <= limit)
		return income * NORMAL;
	else
		return (limit * NORMAL) + OVER * (income - limit);
}