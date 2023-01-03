#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int letterCnt = 0;
	int wordCnt = 0;
	bool isWord = false;
	char input;
	float avg;
	
	printf("���� �Է�: ");
	while ((input = getchar()) != EOF)
	{

		if (input != ' ' && input != '\n')
		{
			isWord = true;
			letterCnt++;
		}
		if(input == ' ')
		{
			if (isWord)
			{
				wordCnt++;
				isWord = false;
			}
		}		
		if (input == '\n')
		{
			if (letterCnt == 0)
				continue;
			if (isWord)
			{
				wordCnt++;
				isWord = false;
			}
		}
	}
	
	avg = letterCnt / (float)wordCnt;

	printf("�� ���� ��: %d\n", letterCnt);
	printf("�ܾ� ��: %d\n", wordCnt);
	printf("�ܾ�� ���� ��� ���� ��: %.2f\n", avg);

	return 0;
	
}