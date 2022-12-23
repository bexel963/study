#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char* s_gets(char*, int);

char showmenu(void);
void eatline(void);

void show(void *(char*), char*);

void ToUpper(char*);
void ToLower(char*);
void Transpose(char*);
void Dummy(char*);

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char*);	// char* �������ڸ� ����ϰ� ���ϰ��� ���� �Լ��� ����Ű�� �Լ��� ������ ����

	puts("���ڿ��� �Է��Ͻÿ�(�������� �� ����):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
			case 'u': 
				pfun = ToUpper;
				break;
			case 'l':
				pfun = ToLower;
				break;
			case 't':
				pfun = Transpose;
				break;
			case 'o':
				pfun = Dummy;
				break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("���ڿ��� �Է��Ͻÿ�(�������� �� ����):");
	}
	puts("�ȳ�!");

	return 0;
}

char showmenu(void)
{
	char ans;
	puts("�޴����� ���ϴ� �۾��� �����Ͻÿ�:");
	puts("u) �빮�ڷ� ��ȯ		l) �ҹ��ڷ� ��ȯ");
	puts("t) ��ҹ��� ���� ��ȯ	o) ������ �״��");
	puts("n) ���� ���ڿ�");
	
	ans = getchar();
	ans = tolower(ans);	// �ҹ��ڷ� ��ȯ�Ѵ�.
	eatline();			// ������ �������� �о ����Ѵ�.
	while (strchr("ulton", ans) == NULL)
	{
		puts("u, l, t, o, n �߿��� ��� �ϳ��� �����Ͻÿ�:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char* str)
{
	// ���ڿ��� �������� �ʰ� �״�� �д�.
}

void show(void (*fp)(char*), char* str)
{
	(*fp)(str);
	puts(str);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');	// ������ ã�´�.
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}