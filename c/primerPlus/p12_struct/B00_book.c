#include <stdio.h>
#include <string.h>
#define MAXTITLE 41
#define MAXAUTL 31

char* s_gets(char*, int);

struct book {
	char title[MAXTITLE];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library;
	
	printf("���� ������ �Է� �Ͻÿ�.\n");
	s_gets(library.title, MAXTITLE);
	puts("���ڸ��� �Է��Ͻÿ�");
	s_gets(library.author, MAXAUTL);
	puts("������ �Է��Ͻÿ�.");
	scanf("%f", &library.value);
	
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
	
	printf("����\n");
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