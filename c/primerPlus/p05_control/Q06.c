#include <stdio.h>

int main(void)
{
	char ch, prev = ' ';
	int cnt = 0;
	
	puts("문자열 입력: ");
	while ((ch = getchar()) != '#')
	{		
		if (ch == 'i' && prev == 'e')
			cnt++;

		prev = ch;
	}

	printf("ei가 나타난 횟수: %d\n", cnt);

	return 0;
}