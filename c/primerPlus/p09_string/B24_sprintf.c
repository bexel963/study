#include <stdio.h>
#include "myString.h"
#define MAX 20

char* s_gets(char*, int);

int main(void)
{
	char name[MAX];
	char company[MAX];
	char formal[2 * MAX + 10];
	char first[4];
	char last[10];
	double prize;

	puts("�̸��� �Է��Ͻÿ�:");
	s_gets(last, MAX);
	puts("���� �Է��Ͻÿ�:");
	s_gets(first, MAX);
	puts("����� �Է��Ͻÿ�:");
	scanf("%lf", &prize);
	sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(formal);

	return 0;
}
