#include <stdio.h>
#include <string.h>
#include "myString.h"

#define SIZE 40
#define LIM 5

char* s_gets(char*, int);

int main(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;

	printf("q로 시작하는 단어를 %d개 입력하시오: \n", LIM);
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'q')
			printf("%s: q로 시작하는 단어가 아닙니다.\n", temp);
		else
		{
			/*
				- strcpy()는 두 개의 문자열 포인터를 전달인자로 사용한다.
				  선언된 포인터, 배열 이름, 문자열 상수가 소스 문자열을 가리키는 두 번째 포인터가 될 수 있다.
				  타깃 문자열을 가리키는 첫 번째 포인터는, 그 문자열을 저장할 수 있을 만큼 충분한 기억 공간을 확보하고 있는, 배열과 같은
				  데이터 객체를 가리켜야 한다.

				- 배열을 선언하면 데이터를 위한 기억 공간이 할당되고, 포인터를 선언하면 하나의 주소를 위한 기억 공간이 할당된다.

				- 타깃 배열이 소스 배열을 복사할 수 있을 만큼 충분한 기억 공간을 가지고 있는지 확인하는 것은 프로그래머의 몫이다.

						char* str;
						strcpy(str, "The C of Tranquility");	// 문제 발생

				  위 상황에서 이 함수는 문자열 "The C of Tranquility"을 str가 지정하는 주소에 복사한다.
				  그러나 str가 초기화되지 않았기 때문에, 어디로 복사될지 알 수가 없다.
			*/
			strcpy(qwords[i], temp);
			i++;
		}
	}
	puts("받아들인 단어들은 다음과 같습니다.");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);


	return 0;
}
