#include <stdio.h>

int main(void)
{
	char line1[10];
	char line2[10];

	puts("gets(), puts()�� ����� echo");
	gets(line1);
	puts(line1);

	puts("fgets(), fputs()�� ����� echo");
	fgets(line2, 81, stdin);
	fputs(line2, stdout);
}