#include <stdio.h>

int main(void)
{
	char ch, prev = ' ';
	int cnt = 0;
	
	puts("���ڿ� �Է�: ");
	while ((ch = getchar()) != '#')
	{		
		if (ch == 'i' && prev == 'e')
			cnt++;

		prev = ch;
	}

	printf("ei�� ��Ÿ�� Ƚ��: %d\n", cnt);

	return 0;
}