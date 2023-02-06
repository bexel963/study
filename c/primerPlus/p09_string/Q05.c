#include <stdio.h>
#include <string.h>

char* getCharacter(char*, char);

int main(void)
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char search;
	char* find;

	printf("ã�� ���� �ϳ� �Է�(�������� [Enter]�Է�): ");
	while ((search = getchar()) != '\n')
	{
		find = getCharacter(str, search);

		if (!find)
			puts("ã������ ���ڰ� �����ϴ�.");
		else
			printf("ã������ ���ڴ� %c�� �ֽ��ϴ�.\n", *find);

		while (getchar() != '\n')
			continue;
		printf("ã�� ���� �ϳ� �Է�(�������� [Enter]�Է�): ");
	}
}

char* getCharacter(const char* str, char search)
{
	char* ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr == search)
			return ptr;
		ptr++;
	}
	
	return NULL;
	
}