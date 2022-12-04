#include <stdio.h>

int main(void)
{
	char line1[10];
	char line2[10];

	puts("gets(), puts()를 사용한 echo");
	gets(line1);
	puts(line1);

	puts("fgets(), fputs()를 사용한 echo");
	fgets(line2, 81, stdin);
	fputs(line2, stdout);
}