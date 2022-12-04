#include <stdio.h>

int main(void)
{
	char name1[11], name2[11];
	int count;

	printf("2개의 이름을 입력하시오.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("%d개의 이름을 읽었습니다. %s 그리고 %s. \n", count, name1, name2);

	return 0;

}