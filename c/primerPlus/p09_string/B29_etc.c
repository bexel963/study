#include <stdio.h>

/*
	- char* strchr(const char* s, int n);
		: 문자열 s에서 문자 c가 처음으로 나타나는 위치를 가리키는 포인터를 리턴한다.
		  종결 널 문자는 문자열의 일부이다. 그래서 널 문자도 찾는 대상이 될 수 있다.)
		  이 함수는 문자 c를 찾지 못했을 때 널 포인터를 리턴한다.

	- char* strstr(const char* s1, const char* s2);
		: 문자열 s1에서 문자열 s2가 처음으로 나타나는 위치를 가리키는 포인터를 리턴한다.

	- size_t strlen(const char* s);
		: 문자열 s에서 찾은 문자들의 개수를 리턴한다.
		  이 때 종결 널 문자는 포함하지 않는다.

	- 이 프로토타입들은, 함수가 문자열을 변경하지 않는다는 것을 나타내기 위해, const 키워드를 사용한다.
*/
int main(void)
{
	char line[80];
	char* find;

	fgets(line, 80, stdin);
	find = strchr(line, '\n');

	if (find)
		*find = '\0';
}