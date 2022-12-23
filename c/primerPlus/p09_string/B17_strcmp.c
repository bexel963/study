#include <stdio.h>
#include "myString.h"
#define ANSWER "Grant"
#define SIZE 40
char* s_gets(char* st, int n);

/*
	- ANSWER와 try는 실제로는 포인터이다.
	  서로 다른 위치에 저장되어 있기 때문에, 두 주소는 같지않다.
	- strcmp()는 관계 연산자들이 수를 대상으로 수행하는 일을 문자열을 대상으로 수행한다.

	- strcmp()는 문자들이 아니라 문자열들을 비교하는 함수이다.
	  그래서 'a' 같은 문자 전달 인자는 사용할 수 없다.
	  그러나 char형은 정수형이기 때문에, 문자들을 비교하는 데에는 관계 연산자를 사용할 수 있다.

	- strcmp()는 배열들이 아니라 문자열들을 비교한다.
	  따라서, 서로 다른 크기의 배열에 저장되어 있는 문자열들을 비교하는 데에도 사용할 수 있다.
*/
int main(void)
{
	char try[SIZE];

	puts("Grant의 무덤에 누가 잠들어 있습니까?");
	s_gets(try, SIZE);
	while (strcmp(try, ANSWER) != 0)	// try가 40개의 메모리 셀을 가지고 있지만, 첫 번째 널 문자까지의 try부분을 기준으로 비교가 이루어진다.
	{
		puts("틀렸습니다. 다시 말해 보십시오.");
		s_gets(try, SIZE);
	}

	return 0;
}