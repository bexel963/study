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
	
	printf("����ǥ�� ����, ���� %d���� ��� �ֽ��ϴ�.\n", charcount);

	while ((ch = getchar()) != '\n')	// ���ۿ� �����ִ� ���� ����ϱ�.
	{
		putchar(ch);
	}

	return 0;
}