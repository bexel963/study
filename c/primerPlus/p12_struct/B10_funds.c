#include <stdio.h>
#define FUNDLEN 50
#define N 2

// ����ü �迭�� ����ϴ� �Լ�

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds*, int);

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
	
	/*
		- �迭 �̸��� ����Ͽ� �� �迭�� �ִ� ù ��° ����ü�� �ּҸ� �Լ��� ���� �� �� �ִ�.
		  ����ȣ �迭 ǥ�⸦ ����Ͽ� �� �迭�� �ִ� �������� ����ü�鿡 ������ �� �ִ�.
				sum(&jones[0], n);
		  ���� ���� ȣ���� jones�� &jones[0]�� ���� �ּ��̱� ������, �迭 �̸��� ����ϴ� �Ͱ� ������ ȿ���� ����.
		  ��, �迭 �̸��� ����ϴ� ����, ����ü �ּҸ� ���������� �����ϴ� ����� �Ұ��ϴ�.
	*/
	printf("Jones ���� �� ������ �� �ܰ�� $%.2f�Դϴ�.\n", sum(jones, N));

	return 0;
}

double sum(const struct funds* money, int n)
{
	double total;
	int i;

	for (i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;

	return total;
}