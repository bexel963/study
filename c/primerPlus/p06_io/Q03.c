#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int capitalCnt = 0;
	int smallCnt = 0;

	while ((ch = getchar()) != EOF)
	{
		if ('a' <= ch && ch <= 'z')
			smallCnt++;
		if ('A' <= ch && ch <= 'Z')
			capitalCnt++;
	}
	
	printf("�ҹ��� ����: %d\n�빮�� ����: %d\n", smallCnt, capitalCnt);

	return 0;
}