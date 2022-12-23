#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);
double sum2(const struct finds*);
double sum3(struct funds moolah);

int main(void)
{
	struct funds stan = {
		"��������",
		304.72,
		"���ƻ�ȣ�ſ�ݰ�",
		9237.11
	};
	
	printf("Stan ���� �� �ܰ�� $%.2f�Դϴ�.\n", sum(stan.bankfund, stan.savefund));	// ����ü�� ��� ����
	printf("Stan ���� �� �ܰ�� $%.2f�Դϴ�.\n", sum2(&stan));						// ����ü�� �ּ� ����
	printf("Stan ���� �� �ܰ�� $%.2f�Դϴ�.\n", sum3(stan));							// ����ü ����

	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}
double sum2(const struct funds* money)
{
	return (money->bankfund + money->savefund);
}
double sum3(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}