#include <stdio.h>

double power(double a, int b);
double rec_power(double a, int b);

int main(void)
{
	double x, xpow;
	int exp;

	printf("어떤 수와, 원하는 양의 정수 거듭제곱수를 입력하시오.\n끝내려면 q를 입력하시오.\n");
	while (scanf("%lf %d", &x, &exp) == 2)
	{
		xpow = rec_power(x, exp);
		printf("%.3g의 %d승은 %.5g입니다.\n", x, exp, xpow);
		printf("두 수를 입력하시오.\n끝내려면 q를 입력하시오.\n");
	}
	printf("끝~!\n");

	return 0;
}

double power(double a, int b)
{
	double pow = 1;

	if (b == 0)
	{
		if (a == 0)
			printf("0의 0승은 정의되지 않았고 1의 값을 사용한다.\n");
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
			printf("0의 0승은 정의되지 않았고 1의 값을 사용한다.\n");
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