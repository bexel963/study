/*
	1���� �� 3.156 x 10^7�ʿ� �ش��Ѵ�.
	���̸� �޼��� �Է� �޾�, �ʴ����� ���
*/
#include <stdio.h>
#define SCND 3.156e7

int main(void)
{
	int age;

	printf("���� �Է�: ");
	scanf("%d", &age);

	printf("����: %d��, �ʴ����� ȯ��: %.4f", age, age * SCND);

	return 0;
}