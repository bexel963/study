#include <stdio.h>
#define FUNDLEN 50
#define N 2

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds[], int);

int main(void)
{
	struct funds jones[N] = {
		{
			"��������",
			4032.27,
			"���ƻ�ȣ�ſ�ݰ�",
			8543.94
		},
		{
			"�츮����",
			3620.88,
			"���ѻ�ȣ�ſ�ݰ�",
			3802.91
		}
	};
	
	printf("Jones ���� �� ������ �� �ܰ�� $%.2f�Դϴ�.\n", sum(jones, N));

	return 0;
}

double sum(const struct funds money[], int n)
{
	double total;
	int i;

	for (i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;

	return total;
}