#include <stdio.h>
#define FIRST 0.15
#define NEXT 0.2
#define REMAIN 0.25

#define GRADE1 8.75
#define GRADE2 9.33
#define GRADE3 10.0
#define GRADE4 11.2

char menu();

int main(void)
{
	const int overtime = 40;

	float normal_pay = 0;
	float gross_pay, taxes, net_pay;
	int working_hour;
	char select;

	while ((select = menu()) != 'q')
	{

		if (!('a'<=select && select <='d') && select != 'q')
		{
			puts("다시 선택해 주세요(a~d or q)~~");
			continue;
		}

		switch (select)
		{
		case 'a':
			normal_pay = GRADE1;
			break;
		case 'b':
			normal_pay = GRADE2;
			break;
		case 'c':
			normal_pay = GRADE3;
			break;
		case 'q':
			normal_pay = GRADE4;
			break;
		}

		printf("일주일 간 노동한 시간 입력: ");
		scanf("%d", &working_hour);
		while (getchar() != '\n')
			continue;

		if (working_hour < overtime)
			gross_pay = working_hour * normal_pay;
		else
		{
			gross_pay = overtime * normal_pay + ((working_hour - overtime) * normal_pay * 1.5);
		}

		if (gross_pay <= 300)
			taxes = gross_pay * FIRST;
		else if (gross_pay <= 450)
			taxes = gross_pay * NEXT;
		else
			taxes = gross_pay * REMAIN;

		net_pay = gross_pay - taxes;

		printf("총소득: %.2f\t세금: %.2f\t순소득: %.2f\n\n", gross_pay, taxes, net_pay);
	}

	puts("종료~~~");

	return 0;
}

char menu()
{
	char input;

	puts("*******************************************************************");
	printf("a) 시간당 $8.75\t\t\tb) 시간당 $9.33\nc) 시간당 $10.00\t\td) 시간당 $11.20\nq) 종료\n");
	printf("자신의 기본급에 해당하는 번호를 선택하시고(끝내려면 q를 선택하시오) :");	
	input = getchar();
	while (getchar() != '\n')
		continue;
	puts("*******************************************************************");

	return input;
}

