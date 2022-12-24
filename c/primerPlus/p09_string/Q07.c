#include <stdio.h>
#include <string.h>
#define LEN 20

int userInput(char*);
void mystrncpy(char*, char*, int);

int main(void)
{
	char target[LEN];
	char source[LEN];

	while (userInput(source))
	{
		fputs("source배열: ", stdout);
		puts(source);
		puts("source의 내용을 target으로 복사합니다.......\n");
		mystrncpy(target, source, 10);
		fputs("target배열: ", stdout);
		puts(target);
	}

	return 0;
}

int userInput(char* input)
{
	int length = 0;
	fputs("\n\n문자열 입력(끝내려면 [enter]입력): ", stdout);
	fgets(input, LEN, stdin);		

	if (input[0] == '\n')
		return 0;

	length = strlen(input);
	printf("문자열 길이: %d\n", length);
	if (length == LEN - 1)
	{
		while (getchar() != '\n')
			continue;
	}
	else


		input[length-1] = '\0';
	
	return 1;
}

void mystrncpy(char* target, char* source, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(target++) = *(source + i);
	}
	*target = '\0';
}