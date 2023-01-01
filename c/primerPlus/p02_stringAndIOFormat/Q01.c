#include <stdio.h>
#define MIN 60

int main(void)
{
	int minute;
	int hour;

	puts("분 입력(나가려면 문자 하나 입력)");
	while (scanf("%d", &minute))
	{
		hour = minute / MIN;
		printf("%d분은 %d시간 %분~~\n\n", minute, hour, minute % MIN);

		puts("분 입력(나가려면 문자 하나 입력)");
	}

	puts("종료~~");

	return 0;
}