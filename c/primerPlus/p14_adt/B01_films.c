#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film* next;
};

char* s_gets(char* st, int n);

int main(void)
{
	struct film* head = NULL;
	struct film* prev = NULL, * current = NULL, * rear = NULL;
	char input[TSIZE];

	puts("첫 번째 영화 타이틀을 입력하시오:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film*)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
		{
			prev->next = current;
		}			
		current->next = NULL;
		strcpy(current->title, input);
		puts("평가를 입력하시오(0점에서 10점까지) :");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("다음 영화 타이틀을 입력하시오(끝내려면 빈 라인):");
		prev = current;
	}
	if (head == NULL)
		puts("입력된 데이터가 없습니다.");
	else
		puts("영화들의 목록은 다음과 같습니다.");

	current = head;
	while (current != NULL)
	{		
		printf("제목: %s   평가: %d\n", current->title, current->rating);
		current = current->next;
	}

	current = head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	puts("끝!");

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