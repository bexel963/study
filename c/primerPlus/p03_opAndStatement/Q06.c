#include <stdio.h>

int main(void)
{
	int day;
	int pay = 0;

	printf("일수: ");
	scanf("%d", &day);

	for (int i = 1; i <= day; i++)
	{
		pay += i*i;
	}

	printf("총 급여: $%d", pay);

	return 0;
}