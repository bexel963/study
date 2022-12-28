#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

// 2. �����͸� ������� �ʰ� ����ü�� �ٷ�� ���� -> �������ڿ� ���ϰ����� ����ü�� ���.
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
	puts("�̸��� �Է��Ͻÿ�.");
	s_gets(temp.lname, NLEN);
	puts("���� �Է��Ͻÿ�.");
	s_gets(temp.fname, NLEN);

	return temp;
}
struct namect makeinfo(struct namect info)	// ���ο� ����ü info(���纻) ���� �� ���ڷ� �Ѿ���� ����ü person�� ������ info�� ���� �ȴ�.
{
	info.letters = strlen(info.fname) + strlen(info.lname);

	return info;
}

void showinfo(struct namect info)
{
	printf("%s %s, ����� ������ %d���� ���ڸ� ������ �ֽ��ϴ�.\n", info.fname, info.lname, info.letters);
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