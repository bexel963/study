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
	
	printf("소문자 개수: %d\n대문자 개수: %d\n", smallCnt, capitalCnt);

	return 0;
}