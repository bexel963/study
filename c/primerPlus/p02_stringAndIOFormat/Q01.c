#include <stdio.h>
#define MIN 60

int main(void)
{
	int minute;
	int hour;

	puts("�� �Է�(�������� ���� �ϳ� �Է�)");
	while (scanf("%d", &minute))
	{
		hour = minute / MIN;
		printf("%d���� %d�ð� %��~~\n\n", minute, hour, minute % MIN);

		puts("�� �Է�(�������� ���� �ϳ� �Է�)");
	}

	puts("����~~");

	return 0;
}