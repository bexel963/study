#include <stdio.h>

int main(void)
{
	int day;
	int week;

	puts("�� �� �Է�(�������� 0 �Ǵ� ���� �Ǵ� ���� �Է�)");
	while (scanf("%d", &day))
	{
		if (day <= 0)
			break;
		
		week = day / 7;
		printf("%d���� %d��, ", day, week);
		day %= 7;
		printf("%d�� �Դϴ�.\n", day);

		puts("�� �� �Է�(�������� 0 �Ǵ� ���� �Ǵ� ���� �Է�)");
	}

	puts("����~~");

	return 0;
}