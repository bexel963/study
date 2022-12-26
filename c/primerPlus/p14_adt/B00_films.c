#include <stdio.h>
#include <string.h>
#define TSIZE 45
#define FMAX 5

struct film {
	char title[TSIZE];
	int rating;
};

char* s_gets(char* st, int n);

int main(void)
{

	struct film movies[FMAX];
	int i = 0;
	int j;

	puts("첫 번째 영화 타이틀을 입력하시오:");
	while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0')
	{
		puts("평가를 입력하시오(0점에서 10점까지):");
		scanf("%d", &movies[i++].rating);
		while (getchar() != '\n')
			continue;
		puts("다음 영화 타이틀을 입력하시오(끝내려면 빈 라인):");
	}

	if (i == 0)
		puts("입력된 데이터가 없습니다.");
	else
		puts("영화들의 목록은 다음과 같습니다.");

	for(j=0 ; j<i ; j++)
		printf("제목: %s  평가: %d\n", movies[j].title, movies[j].rating);

	puts("끝!!");

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