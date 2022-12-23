#include <stdio.h>
#include <string.h>
#define SIZE 80
char* s_gets(char* st, int n);

int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";

	puts("네가 가장 좋아하는 꽃이 뭐냐?");
	if (s_gets(flower, SIZE))
	{
		strcat(flower, addon);	// 두 번째 문자열이 덧붙은 첫 번째 문자열의 첫 번째 문자의 주소를 리턴한다.
		puts(flower);			// addon이 변경되지 않는 동안 flower는 변경된다.
		puts(addon);
	}
	else
		puts("End of file encountered!");
	puts("안녕");

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