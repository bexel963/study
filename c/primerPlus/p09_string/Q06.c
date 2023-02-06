#include <stdio.h>

int is_within(char, char*);

int main(void)
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char search;
	int isFind;
	
	puts("���� �ϳ��� �Է��ϸ� �Է��� ���ڰ� �ش� ���ڿ��� �ִ��� �˷��ش�.");
	printf("���� �ϳ� �Է�(�������� [Enter]�Է�): ");
	while ((search = getchar()) != '\n')
	{
		isFind = is_within(search, str);
		
		if (isFind)
			puts("�Է��� ���ڰ� ���ڿ��� �������.");
		else
			puts("�Է��� ���ڰ� ���ڿ��� ����.");
		printf("���� �ϳ� �Է�(�������� [Enter]�Է�): ");

		while (getchar() != '\n')
			continue;
	}

	return 0;
}

int is_within(char search, char* str)
{
	int idx = 0;

	while (str[idx] != '\0')
	{
		if (str[idx] == search)
			return 1;
		idx++;
	}

	return 0;
}