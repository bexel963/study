#include <stdio.h>
#define LEN 100

void deleteSpace(char*);

int main(void)
{
	char sentence[LEN];

	fputs("���� �Է�(�������� [enter]�Է�): ", stdout);
	while (fgets(sentence, 10, stdin) != NULL && sentence[0] != '\n')
	{
		int i = 0;
		while (sentence[i] != '\n' && sentence[i] != '\0')
			i++;
		if (sentence[i] == '\n')
			sentence[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		
		fputs("�Է��� ����: ", stdout);
		puts(sentence);
				
		fputs("�����̽� ����: ", stdout);
		deleteSpace(sentence);

		fputs("���� �Է�(�������� [enter]�Է�): ", stdout);
	}
	puts("\n ����!!");
}

void deleteSpace(char* str)
{
	while (*str != '\0')
	{
		if (*str == ' ')
		{
			str++;
			continue;
		}			
		putchar(*str);
		str++;
	}
	puts("\n");
}