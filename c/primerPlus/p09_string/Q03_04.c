#include <stdio.h>
#define SIZE 20
#define READ 10

void getWord(char*);
void getWord2(char*, int);

int main(void)
{

	
	char input[SIZE];
	
	getWord2(input, READ);
	
	printf("입력한 단어 중 첫 번째 단어: ");
	puts(input);

	return 0;
}

void getWord(char* input)
{
	char ch;
	int cnt = 0;
	
	printf("단어 여러개 입력: ");
	while ((ch = getchar()) != EOF)
	{
		if (cnt == 0 && ch == ' ')
			continue;
		
		if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			input[cnt] = '\0';

			while (getchar() != '\n')
				continue;

			break;
		}
			
		input[cnt] = ch;
		cnt++;		
	}
}

void getWord2(char* input, int length)
{
	char ch;
	int cnt = 0;

	printf("단어 여러개 입력: ");
	while ((ch = getchar()) != EOF)
	{
		if (cnt == 0 && ch == ' ')
			continue;

		if (ch == ' ' || ch == '\t' || ch == '\n' || cnt >= length)
		{
			input[cnt] = '\0';

			while (getchar() != '\n')
				continue;

			break;
		}

		input[cnt] = ch;
		cnt++;
	}
}