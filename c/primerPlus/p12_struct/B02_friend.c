#include <stdio.h>
#define LEN 20

const char* msgs[5] =
{
	"�Ǹ��� ���� ������ ����帳�ϴ�.",
	"����� ������ ",
	"��� ���� ����� ���� Ư���� ���̶�� ���� �����մϴ�.",
	"�츮�� ���ִ� ",
	"�� �԰� �ణ ���� �� �̻����� �Բ������� Ʋ���� �����ϴ�."
};

struct names {
	char first[LEN];
	char last[LEN];
};
struct guy {
	struct names handle;	// ��ø�� ����ü
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main(void)
{
	struct guy fellow = {
		{"Ewen", "Villard"},
		"���� ����",
		"���� ��ġ",
		68112.00
	};
	printf("ģ���ϴ� %s, \n\n", fellow.handle.first);
	printf("%s%s\n", msgs[0], fellow.handle.first);
	printf("%s%s.\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	
	if (fellow.income > 150000.0)
		puts("!!");
	else if (fellow.income > 75000.0)
		puts("!");
	else
		puts(".");

	printf("\n%40s%s\n", " ", "�� �ƾ��,");
	printf("%40s%s\n", " ", "Shalala");

	return 0;
}