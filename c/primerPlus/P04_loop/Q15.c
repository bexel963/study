#include <stdio.h>
#include <string.h>
#define SIZE 255	

int main(void)
{
	char sentence[SIZE];
	int idx = 0;

	printf("���� �ϳ� �Է�: \n");
	while (scanf("%c", &sentence[idx]))
	{
		if (sentence[idx] == '\n')
		{
			sentence[idx] = '\0';
			break;
		}
		idx++;
	}
	printf("�Է��� ����: ");
	for (int i = 0; i < strlen(sentence); i++)
	{
		putchar(sentence[i]);
	}
	putchar('\n');
	
	printf("�Ųٷ� ���: ");
	for (int i = strlen(sentence); i >= 0; i--)
		putchar(sentence[i]);
	putchar('\n\n');

	return 0;
}