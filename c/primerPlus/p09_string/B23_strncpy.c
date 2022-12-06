#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGSIZE 7 
#define LIM 5
char* s_gets(char*, int);

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