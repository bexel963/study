#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

void ToUpper(char*);
int PunctCount(const char*);

/*
	- ctype.h 계열의 함수들은 문자열에 전체적으로는 적용될 수 없지만, 문자열에 있는 각 문자들에는 적용될 수 있다.
	  ctype.h 함수들은 매크로롤 구현되어 있다.
*/
int main(void)
{
	char line[LIMIT];
	char* find;

	puts("한 라인을 입력하시오:");
	fgets(line, LIMIT, stdin);
	find = strchr(line, '\n');
	if (find)
		*find = '\0';
	ToUpper(line);
	puts(line);
	printf("그 라인에는 구두점 문자가 %d개 들어 있습니다.\n", PunctCount(line));

	return 0;
}

void ToUpper(char* str)
{
	while (*str)	// *str이 널 문자를 만났을 때, *str의 값은 0 또는 거짓이 된다.
	{
		*str = toupper(*str);
		str++;
	}
}
int PunctCount(const char* str)
{
	int ct = 0;
	while (*str)
	{
		if (ispunct(*str))
			ct++;
		str++;
	}

	return ct;
}