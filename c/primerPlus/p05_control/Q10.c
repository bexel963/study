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
			puts("다시 입력해 주세요(1~4)");
			continue;
		}
		printf("소득 입력: ");
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

		printf("해당 소득에 대한 세금: %.2f\n", tax);
	}
	
	puts("종료~~~");

	return 0;
}

int menu()
{
	int input;
	puts("--------------------------------------------------------------");
	printf("과세 구분  \t\t\t세율\n");
	printf("1) 독신       \t\t\t$17,850까지 15%%, 초과분은 28%%\n");
	printf("2) 가장       \t\t\t$23,900까지 15%%, 초과분은 28%%\n");
	printf("3) 맞벌이, 합산\t\t\t$29,750까지 15%%, 초과분은 28%%\n");
	printf("4) 맞벌이, 별산\t\t\t$14,875까지 15%%, 초과분은 28%%\n");
	puts("--------------------------------------------------------------");
	printf("과세 구분 입력(끝내려면 0입력): ");
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