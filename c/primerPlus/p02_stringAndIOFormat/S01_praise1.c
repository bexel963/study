#include <stdio.h>
#define PRAISE "You are an extraordinary being.sadasd"

int main(void)
{
	char name[40];

	printf("�Ƿ����� ������ ��� �ǽô���?\n");
	scanf("%s", name);
	printf("�ݰ����ϴ�. %s ��. %s\n", name, PRAISE);
	printf("�̸��� %zd�����ε� �޸� �� %zd���� �����մϴ�.\n", strlen(name), sizeof(name));
	printf("�̸��� %zd�����ε� �޸� �� %zd���� �����մϴ�.\n", strlen(name), sizeof name);
	printf("��ź���� %zd�����ε�\n", strlen(PRAISE));
	printf("�޸� �� %zd���� �����մϴ�.\n", sizeof(PRAISE));
	printf("�޸� �� %zd���� �����մϴ�.\n", sizeof PRAISE);
	
	return 0;
}