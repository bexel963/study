#include <stdio.h>
void put1(const char*);
int put2(const char*);

int main(void)
{
	put1("마음대로 쓸 수 있을 만큼");
	put2(" 돈이 풍족하면 참 좋으련만,\n");
	printf("나는 %d개의 문자들을 카운트했다.\n", put2("나는 수리할 구식 의자들로 울지는 않을 것이다."));

	return 0;
}
void put1(const char* string)
{
	while (*string)				// *string != '\0' 과 같다.
		putchar(*string++);
}
int put2(const char* string)
{
	int count = 0;
	while (*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');

	return count;
}