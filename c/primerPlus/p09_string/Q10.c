#include <stdio.h>
#define STLEN 20

char* removeSpace(char*, char*);

int main(void)
{
	char input[STLEN];
	char result[STLEN];

	int cnt;

	fputs("문자열 입력: ", stdout);
	while (fgets(input, 10, stdin) != NULL && input[0] != '\n')
	{
		cnt = 0;
		while (input[cnt] != '\n' && input[cnt] != '\0')
			cnt++;
		if (input[cnt] == '\n')
			input[cnt] = '\0';
		else
			while (getchar() != '\n')
				continue;
		
		puts(removeSpace(result, input));
		
		fputs("문자열 입력: ", stdout);
	}
	return 0;
}

char* removeSpace(char* result, char* input)
{
	int cnt = 0;
	char* tmp = result;
	while (input[cnt] != '\0')
	{
		if (input[cnt] == ' ')
		{
			cnt++;
			continue;
		}
		*result = input[cnt];
		result++;
		cnt++;
	}
	*result = '\0';

	return tmp;
}