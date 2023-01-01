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

	printf("Deirdre�� ������� Daphne�� ������� �ʰ��ϴµ� �ɸ� �ð�: %d�� %d����\n", year, month);
	printf("Deirdre�� �����: %.2f�޷�\n", Deirdre_saving);
	printf("Daphne�� �����: %.2f�޷�\n", Daphne_saving);

	return 0;
}