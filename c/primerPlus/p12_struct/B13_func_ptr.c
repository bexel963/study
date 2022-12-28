#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81

/*
	- int형을 가리키는 포인터는 하나의 int형이 저장된 메모리 공간의 주소를 가진다.
	  어떤 함수의 기계어 버전은 메모리에 적재된 코드들로 이루어지기 때문에, 함수들도 마찬가지로 주소를 가진다.
	  함수를 가리키는 포인터는 함수 코드가 시작되는 위치의 주소를 가질 수 있다.
	- 데이터 포인터를 선언할 때, 그 포인터가 가리키는 데이터의 데이터형을 선언해야 한다.
	  함수 포인터를 선언할 때에도 그것이 가리키는 함수형을 선언해야 한다.
	  함수형을 지정하려면, 함수 시그너처를 지정한다. 
	  즉, 함수의 리턴형과 함수 매개변수의 데이터형들을 제공하면 된다.
*/

/*
	- 특정 함수형을 가리키는 포인터를 선언하려면, 먼저 원하는 유형의 함수를 선언한다.
	  그리고 나서 함수 이름을 (*pf) 형식으로 대체한다. 그러면 pf는 그 유형의 함수를 가리키는 포인터가 된다.
				void ToUpper(char*);
				void (*pf)(char*);		// pf는 함수를 가리키는 포인터
				void* af(char*);		// af는 포인터를 리턴하는 함수이다.
	  함수 포인터를 만들었다면, 그 유형을 가진 함수들의 주소를 함수 포인터에 대입할 수 있다.
	  이와 같은 상황에서, 함수의 이름을 함수의 주소를 나타내는 데 사용할 수 있다.
				pf = ToUpper;
*/
char* s_gets(char*, int);

char showmenu(void);
void eatline(void);

void show(void *(char*), char*);

void ToUpper(char*);
void ToLower(char*);
void Transpose(char*);
void Dummy(char*);

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char*);	// char* 전달인자를 사용하고 리턴값이 없는 함수를 가리키는 함수형 포인터 선언

	puts("문자열을 입력하시오(끝내려면 빈 라인):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
			case 'u': 
				pfun = ToUpper;
				break;
			case 'l':
				pfun = ToLower;
				break;
			case 't':
				pfun = Transpose;
				break;
			case 'o':
				pfun = Dummy;
				break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("문자열을 입력하시오(끝내려면 빈 라인):");
	}
	puts("안녕!");

	return 0;
}

char showmenu(void)
{
	char ans;
	puts("메뉴에서 원하는 작업을 선택하시오:");
	puts("u) 대문자로 변환		l) 소문자로 변환");
	puts("t) 대소문자 교차 변환	o) 원본을 그대로");
	puts("n) 다음 문자열");
	
	ans = getchar();
	ans = tolower(ans);	// 소문자로 변환한다.
	eatline();			// 라인의 나머지를 읽어서 폐기한다.
	while (strchr("ulton", ans) == NULL)
	{
		puts("u, l, t, o, n 중에서 어느 하나를 선택하시오:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char* str)
{
	// 문자열을 변경하지 않고 그대로 둔다.
}

void show(void (*fp)(char*), char* str)
{
	(*fp)(str);
	puts(str);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');	// 개행을 찾는다.
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}