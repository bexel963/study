#include <stdio.h>
#define LEN 100

char* search(char*, char);

int main(void)
{

	char sentence[LEN] = "abcdefghiz klm";
	char input;
	char* result;

	fputs("���� �ϳ� �Է�(�������� [enter]): ", stdout);
	while ((input = getchar()) != '\n')
	{
		result = search(sentence, input);
		if (result != NULL)		
			printf("ã�� ����!! ã�� ���ں��� ��� �մϴ�: %s", result);		
		else
			puts("�Է��� ���ڰ� �����ϴ�.");

		while (getchar() != '\n')
			continue;

		fputs("\n���� �ϳ� �Է�(�������� [enter]): ", stdout);		
	}

}

char* search(char* str, char ch)
{
	int idx = 0;

	while (str[idx] != ch && str[idx] != '\0')
	{
		idx++;
	}

	if (str[idx] == ch)
		return &str[idx];
	else
		return NULL;
}