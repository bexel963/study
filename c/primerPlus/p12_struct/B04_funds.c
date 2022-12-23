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
		"국민은행",
		304.72,
		"동아상호신용금고",
		9237.11
	};
	
	printf("Stan 씨의 총 잔고는 $%.2f입니다.\n", sum(stan.bankfund, stan.savefund));	// 구조체의 멤버 전달
	printf("Stan 씨의 총 잔고는 $%.2f입니다.\n", sum2(&stan));						// 구조체의 주소 전달
	printf("Stan 씨의 총 잔고는 $%.2f입니다.\n", sum3(stan));							// 구조체 전달

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