#include <stdio.h>
#define FUNDLEN 50

// �Լ��� ����ü �����ϱ�
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

/*
	- sum3()�� ȣ��Ǿ��� ��, moolah��� �̸��� �ڵ������� funds ���ø��� ���� ���������.
	  �׷��� �� ����ü�� ������� ����ü stan�� �����ϴ� ������� ������ �ִ� ���� ���纻���� ���� �ʱ�ȭ �ȴ�.
	  ���� ���� ����ü�� ���纻�� ����Ͽ� ����� �̷������.
	
	- �ֽ��� C�� �� ����ü�� �ٸ� ����ü�� �����ϴ� ���� ����Ѵ�. �迭�� ��쿡�� �̰��� �� �� ����.
	  n_data�� o_data�� ���� ���������� ����ü���, ������ ���� �� �� �ִ�.
			o_data = n_data;	
	  �̰��� o_data�� �� ����� n_data�� �����ϴ� �� ����� ���� ���Եǰ� �Ѵ�. ����� �迭�� ��쿡�� �����Ѵ�.
	  ���� ���� ���������� ����ü���, �� ����ü�� �ٸ� ����ü�� �ʱ�ȭ�� �� �ִ�.
			struct name right_field = {"Ruthie", "George"};
			struct name captain = right_field;
*/