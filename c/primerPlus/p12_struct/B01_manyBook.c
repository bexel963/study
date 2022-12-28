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
	/*
		- library라는 이름 자체는 구조체 이름이 아니다.
		  library는 struct book형 구조체들을 원소로 가지는 배열의 이름이다.
				library[0].value	-> 첫 번째 배열 원소(구조체)와 관련된 value 멤버
				library[4].title	-> 다섯 번째 배열 원소(구조체)와 관련된 title 멤버
		  library[0], library[4]가 구조체 변수의 이름이다.
				library[4].title[4]	-> 다섯 번째 구조체가 나타내는 책의 타이틀에 있는 다섯 뻔째 문자
	*/
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