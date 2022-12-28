#include <stdio.h>
#include <string.h>

#define NLEN 30
/*
	- 구조체 안에 문자열을 저장해야 한다면, 포인터가 아닌 문자 배열 멤버를 사용해야한다.
	- 문자열을 다루기 위해 구조체 안에 포인터를 사용하는 것이 바람직한 한가지 경우가 있다. 
		: malloc()을 사용하여 메모리를 할당하고, 그 주소를 포인터에 보관하는 것이다.
		: 이 방법의 장점은, 그 문자열을 저장하는 데 꼭 필요한 만큼의 메모리를 malloc()에게 요청할 수 있다는 것이다.
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
	- 입력 받은 두 문자열은 구조체 안에 저장되지 않고, malloc()이 관리하는 메모리 덩어리에 저장된다.
	  그러나 두 문자열의 주소는 구조체 안에 저장된다. 
	  일반적으로 문자열 처리 함수들은 그 주소들을 가지고 작업한다. 
	  그러므로 프로그램에 있는 나머지 함수들은 전혀 변경할 필요가 없다.
*/
void getinfo(struct namect* pst)
{
	char temp[NLEN];
	puts("이름을 입력하시오.");
	s_gets(temp, NLEN);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy(pst->lname, temp);

	puts("성씨를 입력하시오.");
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
	printf("%s %s, 당신의 성명은 %d개의 글자를 가지고 있습니다.\n", pst->fname, pst->lname, pst->letters);
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