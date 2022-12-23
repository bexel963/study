#include <stdio.h>
#include <string.h>
void fit(char*, unsigned int);

int main(void)
{
	char mesg[] = "Things should be as simple as possible, but not simpler";

	puts(mesg);
	fit(mesg, 38);
	puts(mesg);
	puts("문자열의 나머지 부분을 보자.");
	puts(mesg + 39);

	return 0;
}

// 긴 문자열을 단축시키는 함수
// 이 함수는 문자열을 변경하기 대문에 함수 머리 매개변수 string을 선언할 때 const를 사용하지 않는다.
void fit(char* string, unsigned int size)
{
	if (strlen(string) > size)
		*(string + size) = '\0';
}