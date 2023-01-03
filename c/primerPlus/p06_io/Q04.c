#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int letterCnt = 0;
	int wordCnt = 0;
	bool isWord = false;
	char input;
	float avg;
	
	printf("문장 입력: ");
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

	printf("총 글자 수: %d\n", letterCnt);
	printf("단어 수: %d\n", wordCnt);
	printf("단어당 사용된 평균 글자 수: %.2f\n", avg);

	return 0;
	
}