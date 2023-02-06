#include <stdio.h>
#include <string.h>
#define SIZE 20
void reverse(char*);

int main(void)
{
	char input[SIZE];
	int idx;

	fputs("문자열 입력: ", stdout);

	while (fgets(input, 10, stdin) != NULL && input[0] != '\n')
	{
		idx = 0;
		while (input[idx] != '\n' && input[idx] != '\0')
		{
			idx++;
		}
		if (input[idx] == '\n')
			input[idx] = '\0';
		else
			while (getchar() != '\n')
				continue;
		
		reverse(input);
		fputs("문자열 입력: ", stdout);
	}

	return 0;
}

void reverse(char* input)
{
	int cnt = 1;
	int length = strlen(input);
	
	while (cnt <= length)
	{
		putchar(input[length - cnt]);
		cnt++;
	}
	putchar('\n');
}