#include <stdio.h>
#define PRAISE "You are an extraordinary being."

int main(void)
{
	char name[40];

	printf("������ ��� �ǽó���?\n");
	scanf("%s", name);
	printf("�ݰ����ϴ�. %s��. %s\n", name, PRAISE);

	scanf("%s", name);
	printf("%s\n\n", name);

	return 0;
}