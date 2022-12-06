#include <stdio.h>
#include <string.h>
#define LIM 20
#define SIZE 81
#define HALT ""

void stsrt(char* [], int);
char* s_gets(char*, int);

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