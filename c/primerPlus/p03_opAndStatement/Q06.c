#include <stdio.h>

int main(void)
{
	int day;
	int pay = 0;

	printf("�ϼ�: ");
	scanf("%d", &day);

	for (int i = 1; i <= day; i++)
	{
		pay += i*i;
	}

	printf("�� �޿�: $%d", pay);

	return 0;
}