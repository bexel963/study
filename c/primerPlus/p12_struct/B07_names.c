#include <stdio.h>
#include <string.h>

#define NLEN 30
/*
	- ����ü �ȿ� ���ڿ��� �����ؾ� �Ѵٸ�, �����Ͱ� �ƴ� ���� �迭 ����� ����ؾ��Ѵ�.
	- ���ڿ��� �ٷ�� ���� ����ü �ȿ� �����͸� ����ϴ� ���� �ٶ����� �Ѱ��� ��찡 �ִ�. 
		: malloc()�� ����Ͽ� �޸𸮸� �Ҵ��ϰ�, �� �ּҸ� �����Ϳ� �����ϴ� ���̴�.
		: �� ����� ������, �� ���ڿ��� �����ϴ� �� �� �ʿ��� ��ŭ�� �޸𸮸� malloc()���� ��û�� �� �ִٴ� ���̴�.
*/
struct namect {
	char* fname;
	char* lname;
	int letters;
};


void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
char* s_gets(char* st, int n);

int main(void)
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);

	return 0;
}

/*
	- �Է� ���� �� ���ڿ��� ����ü �ȿ� ������� �ʰ�, malloc()�� �����ϴ� �޸� ����� ����ȴ�.
	  �׷��� �� ���ڿ��� �ּҴ� ����ü �ȿ� ����ȴ�. 
	  �Ϲ������� ���ڿ� ó�� �Լ����� �� �ּҵ��� ������ �۾��Ѵ�. 
	  �׷��Ƿ� ���α׷��� �ִ� ������ �Լ����� ���� ������ �ʿ䰡 ����.
*/
void getinfo(struct namect* pst)
{
	char temp[NLEN];
	puts("�̸��� �Է��Ͻÿ�.");
	s_gets(temp, NLEN);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);

	puts("������ �Է��Ͻÿ�.");
	s_gets(temp, NLEN);
	pst->fname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->fname, temp);
}
void makeinfo(struct namect* pst)
{
	pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect* pst)
{
	printf("%s %s, ����� ������ %d���� ���ڸ� ������ �ֽ��ϴ�.\n", pst->fname, pst->lname, pst->letters);
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