#include <stdio.h>

void Temperatures(double);

int main(void)
{
	int result;
	double fah;

	printf("¿Âµµ ÀÔ·Â(È­¾¾): ");
	result = scanf("%lf", &fah);

	while (result)
	{
		Temperatures(fah);

		printf("¿Âµµ ÀÔ·Â(È­¾¾): ");
		result = scanf("%lf", &fah);
	}
	
	return 0;
}

void Temperatures(double fah)
{
	double cel;	// ¼·¾¾¿Âµµ
	double abs;	// Àý´ë¿Âµµ

	const double absolute = 273.16;
	const double celsius1 = 5.0 / 9.0;
	const double celsius2 = -32.0;

	cel = celsius1 * (fah - celsius2);
	abs = cel + absolute;

	printf("È­¾¾¿Âµµ: %.2f(F), ¼·¾¾¿Âµµ: %.2f(C), Àý´ë¿Âµµ: %.2f(K)\n", fah, cel, abs);

}