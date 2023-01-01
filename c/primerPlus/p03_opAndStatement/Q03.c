#include <stdio.h>

int main(void)
{
	int day;
	int week;

	puts("날 수 입력(끝내려면 0 또는 음수 또는 문자 입력)");
	while (scanf("%d", &day))
	{
		if (day <= 0)
			break;
		
		week = day / 7;
		printf("%d일은 %d주, ", day, week);
		day %= 7;
		printf("%d일 입니다.\n", day);

		puts("날 수 입력(끝내려면 0 또는 음수 또는 문자 입력)");
	}

	puts("종료~~");

	return 0;
}