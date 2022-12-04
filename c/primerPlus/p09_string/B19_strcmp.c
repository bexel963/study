#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char* s_get(char* st, int n);

// 프로그램이 입력 읽기를 언제 멈추어야 하는지를 검사하기 위해 strcmp()를 사용한다.
int main(void)
{
	char input[LIM][SIZE];
	int ct = 0;

	printf("%d라인까지 입력하십시오.(끝내려면 quit):\n", LIM);
	while (ct < LIM && (gets(input[ct]) != NULL) && (strcmp(input[ct], STOP) != 0))
	{
		ct++;
	}
	printf("%d개의 문자열이 입력되었습니다.\n", ct);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}