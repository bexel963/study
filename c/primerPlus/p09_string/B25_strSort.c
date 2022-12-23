#include <stdio.h>
#include <string.h>
#include "myString.h"

#define LIM 20
#define SIZE 81
#define HALT ""

void stsrt(char* [], int);

/*
	- 문자열들 자체를 재배치하는 대신에 그 문자열들을 가리키는 포인터들을 재배치한다.
	  정렬 프로시저는, input은 건드리지 않고, ptstr을 재배치한다.
	  strcpy()를 사용하여 input에 있는 두 문자열의 내용을 맞바꾸는 것보다 이 방법이 훨씬 쉽다.
	  이 방법은 input배열에 원래 순서를 보존할 수 있다는 장점도 가지고 있다.
*/
int main(void)
{
	char input[LIM][SIZE];	// 입력을 저장할 배열
	char* ptstr[LIM];		// 포인터 변수들의 배열
	int ct = 0;				// 입력 카운트
	int k = 0;				// 출력 카운트

	printf("최대 %d라인까지 입력하면 그것들을 정렬하겠습니다.\n", LIM);
	printf("입력을 멈추려면 라인 시작에서 Enter 키를 누루시오.\n");
	while (ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];
		ct++;
	}
	stsrt(ptstr, ct);
	puts("\n문자열들이 정렬된 결과:\n");
	for (k = 0; k < ct; k++)
		puts(ptstr[k]);

	return 0;
}

void stsrt(char* strings[], int num)
{
	char* temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
	{
		for (seek = top + 1; seek < num; seek++)
		{
			if (strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}