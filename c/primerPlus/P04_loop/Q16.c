#include <stdio.h>
#define SIMPLE_INTEREST 0.1
#define COMPOUND_INTEREST 0.05

int main(void)
{
	float Daphne_saving, Deirdre_saving;
	float principal = 100;
	int month = 0, year = 0;

	Daphne_saving = principal;
	Deirdre_saving = principal;

	while (Deirdre_saving <= Daphne_saving)
	{
		Daphne_saving += principal * SIMPLE_INTEREST;
		Deirdre_saving += Deirdre_saving * COMPOUND_INTEREST;

		month++;
	}
	year = month / 12;
	month %= 12;

	printf("Deirdre의 저축액이 Daphne의 저축액을 초과하는데 걸린 시간: %d년 %d개월\n", year, month);
	printf("Deirdre의 저축액: %.2f달러\n", Deirdre_saving);
	printf("Daphne의 저축액: %.2f달러\n", Daphne_saving);

	return 0;
}