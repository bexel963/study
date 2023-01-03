#include <stdio.h>

double power(double a, int b);
double rec_power(double a, int b);

int main(void)
{
	double x, xpow;
	int exp;

	printf("� ����, ���ϴ� ���� ���� �ŵ��������� �Է��Ͻÿ�.\n�������� q�� �Է��Ͻÿ�.\n");
	while (scanf("%lf %d", &x, &exp) == 2)
	{
		xpow = rec_power(x, exp);
		printf("%.3g�� %d���� %.5g�Դϴ�.\n", x, exp, xpow);
		printf("�� ���� �Է��Ͻÿ�.\n�������� q�� �Է��Ͻÿ�.\n");
	}
	printf("��~!\n");

	return 0;
}

double power(double a, int b)
{
	double pow = 1;

	if (b == 0)
	{
		if (a == 0)
			printf("0�� 0���� ���ǵ��� �ʾҰ� 1�� ���� ����Ѵ�.\n");
		pow = 1.0;
	}
	else if (a == 0)
		pow = 0.0;
	else if (b > 0)
		for (int i = 1; i <= b; i++)
			pow *= a;
	else
		pow = 1.0 / power(a, -b);

	return pow;
}
double rec_power(double a, int b)
{
	if (b == 0)
	{
		if (a == 0)
			printf("0�� 0���� ���ǵ��� �ʾҰ� 1�� ���� ����Ѵ�.\n");
		return 1.0;
	}
	else if (a == 0)
		return 0.0;
	
	if (b < 0)
	{
		if (b >= 0)
			return 1 / a;
		return 1/a * rec_power(a, ++b);
	}
	else if (b > 0)
	{
		if (b <= 1)
			return a;
		return a * rec_power(a, --b);
	}

	
}