#include <stdio.h>
#include <stdlib.h>
#define LIM 30

/*
	- 문자열이 정수로 시작되는 문자열이라면 atoi()는 동작한다. 그런 경우에, atoi()는 정수 부분이 아닌 것을 만날 때 까지
	  그 앞의 문자들만 변환한다.
		ex) atoi("42regular")는 정수 42를 리턴한다.

	- atoi("hello what?")과 같이 타이핑하면 그러한 경우 ANSI표준은 동작이 정의되지 않는다고 말한다.
	  STRTOL()는 좀 더 신뢰할 수 있는 에러 체크 기능을 제공한다.
*/

/*
	long strtol(const char *nptr, char **endptr, int base);

		: strtol()은 문자열을 long형으로 변환한다.
		: strtol()은 문자열에서 수가 아닌 부분의 첫 번째 문자를 인식하고 보고한다.
		: nptr은 변환하기를 원하는 문자열을 가리키는 포인터이다.
		: endptr은 포인터의 주소이다. (그 포인터는 입력한 수를 끝내는 문자, 즉 수가 아닌 부분의 첫 번째 문자의 주소이다.)
		: base는 그 수를 표기할 진수의 기수다.
*/
char* s_gets(char*, int);

int main(void)
{
	char number[30];
	char* end;
	long value;
	
	puts("하나의 수를 입력하시오(끝내려면 빈 라인 입력):");
	while (s_gets(number, LIM) && number[0] != '\0')
	{
		value = strtol(number, &end, 10);	// 10진수
		printf("값: %ld, %s 앞에서 끝났다 (%d)\n", value, end, *end);

		value = strtol(number, &end, 16);	// 16진수
		printf("값: %ld, %s 앞에서 끝났다 (%d)\n", value, end, *end);
		puts("다음 수를 입력하시오:");
	}
	puts("안녕!\n");

	/*
		- 입력 -> 10
			: 널 문자를 만났을 때 종료하므로 end는 널 문자를 가리킨다.
			: end 출력은 빈 문자열을 표시한다.
			: %d 포맷 지정자를 사용한 *end 출력은 널 문자에 해당하는 ASCII 코드값을 표시한다.

		- 입력 -> 10atom
			: end에 'a' 문자의 주소가 주어진다. 그러므로 end 출력은 문자열 "atom"을 표시하고,
			  *end 출력은 'a' 문자에 해당하는 ASCII 코드값을 표시한다.
	*/
	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\n')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}