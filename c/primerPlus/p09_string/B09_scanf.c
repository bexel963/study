#include <stdio.h>

int main(void)
{
	char name1[11], name2[11];
	int count;

	printf("2���� �̸��� �Է��Ͻÿ�.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("%d���� �̸��� �о����ϴ�. %s �׸��� %s. \n", count, name1, name2);

	return 0;

}