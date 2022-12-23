#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n);
#define MAXTITLE 40
#define MAXAUTL	40
#define MAXBKS 100	// 책의 최대 권 수

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

	puts("도서 제목을 입력하시오.");
	puts("끝내려면 라인의 시작 위치에서 [enter]키를 누르시오.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITLE) != NULL && library[count].title[0] != '\0')
	{
		puts("저자명을 입력하시오.");
		s_gets(library[count].author, MAXAUTL);
		puts("정가를 입력하시오.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("다음 타이틀을 입력하시오.");
	}

	if (count > 0)
	{
		puts("<다음은 소장하고 있는 도서들의 목록입니다>");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
	else
		puts("책이 한 권도 없어요? 야, 장하다 장해.");

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