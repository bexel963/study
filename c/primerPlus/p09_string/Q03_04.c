#include <stdio.h>
#define SIZE 20
#define READ 10

void getWord(char*);
void getWord2(char*, int);

int main(void)
{

	
	char input[SIZE];
	
	getWord2(input, READ);
	
	printf("�Է��� �ܾ� �� ù ��° �ܾ�: ");
	puts(input);

	return 0;
}

void getWord(char* input)
{
	char ch;
	int cnt = 0;
	
	printf("�ܾ� ������ �Է�: ");
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

	printf("�ܾ� ������ �Է�: ");
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