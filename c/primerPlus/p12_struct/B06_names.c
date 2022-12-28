#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

// 2. 포인터를 사용하지 않고 구조체를 다루는 형식 -> 전달인자와 리턴값으로 구조체를 사용.
struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char* s_gets(char* st, int n);

int main(void)
{
	struct namect person;

	person = getinfo();
	person = makeinfo(person);
	showinfo(person);

	return 0;
}

struct namect getinfo(void)
{
	struct namect temp;
	puts("이름을 입력하시오.");
	s_gets(temp.lname, NLEN);
	puts("성을 입력하시오.");
	s_gets(temp.fname, NLEN);

	return temp;
}
struct namect makeinfo(struct namect info)	// 새로운 구조체 info(복사본) 생성 후 인자로 넘어오는 구조체 person의 값들이 info에 복사 된다.
{
	info.letters = strlen(info.fname) + strlen(info.lname);

	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, 당신의 성명은 %d개의 글자를 가지고 있습니다.\n", info.fname, info.lname, info.letters);
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