#include <stdio.h>
#define FIRST 0.15
#define NEXT 0.2
#define REMAIN 0.25

int main(void)
{
	const float normal_pay = 10.0;
	const int overtime = 40;

	float gross_pay, taxes, net_pay;	
	int working_hour;

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

	return 0;
}