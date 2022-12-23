#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char* s_gets(char*, int);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("book.dat ������ �� �� �����ϴ�.\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("book.dat�� ���� ��� �ִ� ����:");
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("book.dat ������ ���� á��.", stderr);
		exit(2);
	}
	
	puts("�� ���� ������� �Է��Ͻÿ�.");
	puts("�������� ������ ���� ��ġ���� [enter] Ű�� �����ÿ�.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
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
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("å�� �� �ǵ� �����? ��, ���ϴ� ����.\n");

	puts("��.\n");
	fclose(pbooks);

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
}