#include <stdio.h>

void Temperatures(double);

int main(void)
{
	int result;
	double fah;

	printf("�µ� �Է�(ȭ��): ");
	result = scanf("%lf", &fah);

	while (result)
	{
		Temperatures(fah);

		printf("�µ� �Է�(ȭ��): ");
		result = scanf("%lf", &fah);
	}
	
	return 0;
}

void Temperatures(double fah)
{
	double cel;	// �����µ�
	double abs;	// ����µ�

	const double absolute = 273.16;
	const double celsius1 = 5.0 / 9.0;
	const double celsius2 = -32.0;

	cel = celsius1 * (fah - celsius2);
	abs = cel + absolute;

	printf("ȭ���µ�: %.2f(F), �����µ�: %.2f(C), ����µ�: %.2f(K)\n", fah, cel, abs);

}