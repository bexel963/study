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
	/*
		- library��� �̸� ��ü�� ����ü �̸��� �ƴϴ�.
		  library�� struct book�� ����ü���� ���ҷ� ������ �迭�� �̸��̴�.
				library[0].value	-> ù ��° �迭 ����(����ü)�� ���õ� value ���
				library[4].title	-> �ټ� ��° �迭 ����(����ü)�� ���õ� title ���
		  library[0], library[4]�� ����ü ������ �̸��̴�.
				library[4].title[4]	-> �ټ� ��° ����ü�� ��Ÿ���� å�� Ÿ��Ʋ�� �ִ� �ټ� ��° ����
	*/
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