#include <stdio.h>
#include <string.h>
#define SIZE 255	

int main(void)
{
	char sentence[SIZE];
	int idx = 0;

	printf("문장 하나 입력: \n");
	while (scanf("%c", &sentence[idx]))
	{
		if (sentence[idx] == '\n')
		{
			sentence[idx] = '\0';
			break;
		}
		idx++;
	}
	printf("입력한 문장: ");
	for (int i = 0; i < strlen(sentence); i++)
	{
		putchar(sentence[i]);
	}
	putchar('\n');
	
	printf("거꾸로 출력: ");
	for (int i = strlen(sentence); i >= 0; i--)
		putchar(sentence[i]);
	putchar('\n\n');

	return 0;
}