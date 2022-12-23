#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGSIZE 7 
#define LIM 5
char* s_gets(char*, int);

/*
	- strcpy()는 gets()와 같은 문제점을 안고 있다.
	  이들은 둘 다 소스 문자열이 타깃 문자열에 맞는지 검사하지 않는다.
	  더 안전하게 문자열을 복사하는 방법은, strncpy()를 사용하는 것이다.
	  복사할 최대 문자 개수를 지정하는 세 번째 전달인자를 사용한다.
*/
int main(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;

	printf("q로 시작하는 단어를 %d개 입력하시오:\n", LIM);
	while (i < LIM && gets(temp))
	{
		if (temp[0] != 'q')
			printf("%s: q로 시작하는 단어가 아닙니다.\n", temp);
		else
		{
			/*
				- temp에 있는 문자들의 개수가 세 번째 인자의 수 보다 작으면, 널 문자를 포함하여 전체 문자열이 복사된다.
				  이 함수는 세 번째 인자의 수 보다 결코 더 많이 복사하지 않는다.
				  그래서 소스 문자열의 끝에 도달하기도 전에 복사 한계에 도달하면, 널 문자가 추가되지 않는다.
				  결과적으로, 최종 결과물은 널 문자를 포함하는 경우도 있고, 포함하지 않는 경우도 있다.
				  이 이유 때문에, 프로그램은 세 번째 인자의 수를, 타깃 배열의 크기보다 하나 작은 값으로 설정한다.
				  그러고 나서 배열의 최종 원소를 널 문자로 설정한다.
				  이것은 문자열이 저장되도록 보증한다. 소스 문자열이 타깃에 실제로 맞는다면, 소스 문자열과 함께 복사된 널 문자가
				  문자열의 실제 끝을 표시한다.
				  소스 문자열이 타깃에 맞지 않는다면, 이 최종 널 문자가 문자열의 끝을 표시한다.
			*/
			strncpy(qwords[i], temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("받아들인 단어들은 다음과 같습니다.");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);

	return 0;
}