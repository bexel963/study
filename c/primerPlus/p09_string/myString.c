#include <stdio.h>
#include "myString.h"

char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')	// 개행문자 지우기
			st[i] = '\0';
		else
			while (getchar() != '\n')	// 버퍼에 남아있는 문자 없애기
				continue;
	}
	return ret_val;
}