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
		printf("%d���� ģ�� ��: %d��\n", week, member);
		
		week++;
	}

	return 0;
}