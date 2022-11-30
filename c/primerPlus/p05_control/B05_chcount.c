#include <stdio.h>
#define PERIOD '.'

int main(void)
{
	int ch;
	int charcount = 0;

	while ((ch = getchar()) != PERIOD)
	{
		if (ch != '"' && ch != '\n')
			charcount++;
		printf("%d\n", charcount);
	}
	
	printf("따옴표는 빼고, 문자 %d개가 들어 있습니다.\n", charcount);

	while ((ch = getchar()) != '\n')	// 버퍼에 남아있는 문자 출력하기.
	{
		putchar(ch);
	}

	return 0;
}