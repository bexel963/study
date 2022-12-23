#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n);
#define MAXTITLE 40
#define MAXAUTL	40
#define MAXBKS 100	// å�� �ִ� �� ��

struct book {
	char title[MAXTITLE];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	puts("���� ������ �Է��Ͻÿ�.");
	puts("�������� ������ ���� ��ġ���� [enter]Ű�� �����ÿ�.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITLE) != NULL && library[count].title[0] != '\0')
	{
		puts("���ڸ��� �Է��Ͻÿ�.");
		s_gets(library[count].author, MAXAUTL);
		puts("������ �Է��Ͻÿ�.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("���� Ÿ��Ʋ�� �Է��Ͻÿ�.");
	}

	if (count > 0)
	{
		puts("<������ �����ϰ� �ִ� �������� ����Դϴ�>");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
	else
		puts("å�� �� �ǵ� �����? ��, ���ϴ� ����.");

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}