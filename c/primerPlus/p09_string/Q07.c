#include <stdio.h>
#define SIZE 20

char* mystrncpy(char*, char*, int);

int main(void)
{
	char target[SIZE];
	char source[SIZE];
	int cnt;

	fputs("�ҽ� ���ڿ� �Է�(�������� [Enter]�Է�): ", stdout);
	while (fgets(source, 10, stdin) != NULL && source[0] != '\n')
	{
		cnt = 0;
		while (source[cnt] != '\n' && source[cnt] != '\0')
			cnt++;
		if (source[cnt] == '\n')
			source[cnt] == '\0';
		else
			while (getchar() != '\n')
				continue;

		fputs("\nsource�迭�� ����� ���ڿ�: ", stdout);
		puts(source);
			
		fputs("target�迭�� ����� ���ڿ�: ", stdout);
		if (mystrncpy(target, source, 5) != NULL)
		{			
			puts(target);
		}
		
		fputs("\n�ҽ� ���ڿ� �Է�(�������� [Enter]�Է�): ", stdout);
	}
	
	return 0;
}

char* mystrncpy(char* target, char* source, int length)
{
	for (int i = 0; i < length; i++)
		target[i] = source[i];
	target[length] = '\0';
	
	return target;
}