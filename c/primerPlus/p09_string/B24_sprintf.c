#include <stdio.h>
#define MAX 20

char* s_gets(char*, int);

int main(void)
{
	char name[MAX];
	char company[MAX];
	char formal[2 * MAX + 10];
	char first[4];
	char last[10];
	double prize;

	puts("이름을 입력하시오:");
	s_gets(last, MAX);
	puts("성을 입력하시오:");
	s_gets(first, MAX);
	puts("상금을 입력하시오:");
	scanf("%lf", &prize);
	sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(formal);

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