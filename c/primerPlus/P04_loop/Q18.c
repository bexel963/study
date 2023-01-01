#include <stdio.h>
#define DUNBAR 150

int main(void)
{
	int member = 5;
	int week = 1;

	while (1)
	{
		member = (member - week) * 2;
		if (member >= DUNBAR)
			break;
		printf("%d주의 친구 수: %d명\n", week, member);
		
		week++;
	}

	return 0;
}