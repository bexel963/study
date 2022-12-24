#include <stdio.h>
#define LEN 100

void deleteSpace(char*);

int main(void)
{
	char sentence[LEN];

	fputs("문장 입력(끝내려면 [enter]입력): ", stdout);
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
		
		fputs("입력한 문장: ", stdout);
		puts(sentence);
				
		fputs("스페이스 제거: ", stdout);
		deleteSpace(sentence);

		fputs("문장 입력(끝내려면 [enter]입력): ", stdout);
	}
	puts("\n 종료!!");
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