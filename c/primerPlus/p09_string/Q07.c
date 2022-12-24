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
		fputs("source�迭: ", stdout);
		puts(source);
		puts("source�� ������ target���� �����մϴ�.......\n");
		mystrncpy(target, source, 10);
		fputs("target�迭: ", stdout);
		puts(target);
	}

	return 0;
}

int userInput(char* input)
{
	int length = 0;
	fputs("\n\n���ڿ� �Է�(�������� [enter]�Է�): ", stdout);
	fgets(input, LEN, stdin);		

	if (input[0] == '\n')
		return 0;

	length = strlen(input);
	printf("���ڿ� ����: %d\n", length);
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