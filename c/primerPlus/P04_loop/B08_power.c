#include <stdio.h>
double power(double n, int p);

int main(void)
{
	double x, xpow;
	int exp;

	printf("� ����, ���ϴ� ���� ���� �ŵ��������� �Է��Ͻÿ�.\n�������� q�� �Է��Ͻÿ�.\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g�� %d���� %.5g�Դϴ�.\n", x, exp, xpow);
		printf("�� ���� �Է��Ͻÿ�.\n�������� q�� �Է��Ͻÿ�.\n");
	}
	printf("��~!\n");

	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	int i;

	for (i = 1; i <= p; i++)
		pow *= n;

	return pow;
}

