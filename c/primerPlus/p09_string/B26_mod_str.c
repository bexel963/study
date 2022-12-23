#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

void ToUpper(char*);
int PunctCount(const char*);

/*
	- ctype.h �迭�� �Լ����� ���ڿ��� ��ü�����δ� ����� �� ������, ���ڿ��� �ִ� �� ���ڵ鿡�� ����� �� �ִ�.
	  ctype.h �Լ����� ��ũ�η� �����Ǿ� �ִ�.
*/
int main(void)
{
	char line[LIMIT];
	char* find;

	puts("�� ������ �Է��Ͻÿ�:");
	fgets(line, LIMIT, stdin);
	find = strchr(line, '\n');
	if (find)
		*find = '\0';
	ToUpper(line);
	puts(line);
	printf("�� ���ο��� ������ ���ڰ� %d�� ��� �ֽ��ϴ�.\n", PunctCount(line));

	return 0;
}

void ToUpper(char* str)
{
	while (*str)	// *str�� �� ���ڸ� ������ ��, *str�� ���� 0 �Ǵ� ������ �ȴ�.
	{
		*str = toupper(*str);
		str++;
	}
}
int PunctCount(const char* str)
{
	int ct = 0;
	while (*str)
	{
		if (ispunct(*str))
			ct++;
		str++;
	}

	return ct;
}