#include <stdio.h>
#define FIRST 0.15
#define NEXT 0.2
#define REMAIN 0.25

#define GRADE1 8.75
#define GRADE2 9.33
#define GRADE3 10.0
#define GRADE4 11.2

int menu();

int main(void)
{	
	const int overtime = 40;

	float normal_pay = 0;
	float gross_pay, taxes, net_pay;
	int working_hour;
	int select;

	while ((select = menu()) != 5)
	{
		if (select > 5)
		{
			puts("�ٽ� ������ �ּ���(1~5)~~");
			continue;
		}
		
		switch (select)
		{
		case 1:
			normal_pay = GRADE1;
			break;
		case 2:
			normal_pay = GRADE2;
			break;
		case 3:
			normal_pay = GRADE3;
			break;
		case 4:
			normal_pay = GRADE4;
			break;
		}

		printf("������ �� �뵿�� �ð� �Է�: ");
		scanf("%d", &working_hour);

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

		printf("�Ѽҵ�: %.2f\t����: %.2f\t���ҵ�: %.2f\n\n", gross_pay, taxes, net_pay);
	}
	
	puts("����~~~");

	return 0;
}

int menu()
{
	int input;

	puts("*******************************************************************");
	printf("�ڽ��� �⺻�޿� �ش��ϴ� ��ȣ�� �����Ͻð�(�������� 5���� �����Ͻÿ�) :");
	scanf("%d", &input);
	printf("1) �ð��� $8.75\t\t\t2) �ð��� $9.33\n3) �ð��� $10.00\t\t4) �ð��� $11.20\n5) ����\n");
	puts("*******************************************************************");

	return input;
}

