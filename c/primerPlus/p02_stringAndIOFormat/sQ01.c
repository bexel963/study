/*
	�̸��� ��û -> �� ��û -> ��, �̸� ������ ���
*/
#include <stdio.h>

int main(void)
{
	char lastName[20];
	char firstName[10];

	printf("�̸� �Է�: ");
	scanf("%s", lastName);
	getchar();
	printf("�� �Է�: ");
	scanf("%s", firstName);

	printf("%s%s\n\n", firstName, lastName);

	return 0;
}