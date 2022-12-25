
/*
	- 하나의 구조체에 저장되는 정보의 총 합을 레코드라고 하고, 각각의 개별 항목을 필드라고 부른다.
	- 레코드를 가장 확실하게 저장하는 방법은, 효율이 가장 떨어지지만 fprintf()를 사용하는 것이다.
			fprintf(pbooks, "%s %s %.2f\n", primer.title, primer.author, primer.value);
	  이것은 가령 30개의 멤버를 가지고 있는 구조체라면 다루기가 어려워진다.
	  또한, 한 필드가 어디에서 끝나고 다른 필드가 시작되는지를 프로그램에 알려 주어야 하므로, 정보 검색에 어려움을 가져온다.
	  이 문제는 고정된 크기의 필드(예를 들어, "%39 %39 %8.2f")를 사용하면 해결할 수 있지만 그렇게 해도 여전히 다루기가 어렵다.
	  더 좋은 해결책은 fread(), fwrite()를 사용하여 구조체 크기 단위로 읽고 쓰는 것이다.
*/
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
		fputs("book.dat 파일을 열 수 없습니다.\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("book.dat에 현재 들어 있는 내용:");
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("book.dat 파일이 가득 찼다.", stderr);
		exit(2);
	}
	
	puts("새 도서 제목들을 입력하시오.");
	puts("끝내려면 라인의 시작 위치에서 [enter] 키를 누르시오.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
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
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("책이 한 권도 없어요? 야, 장하다 장해.\n");

	puts("끝.\n");
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