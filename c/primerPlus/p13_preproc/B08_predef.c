#include <stdio.h>
void why_me(void);

int main(void)
{
	printf("���� �̸�: %s.\n", __FILE__);
	printf("ó�� ��¥: %s.\n", __DATE__);
	printf("ó�� �ð�: %s.\n", __TIME__);
	printf("����: %ld.\n", __SAL_H_VERSION);
	printf("���� ���� ��ȣ�� %d.\n", __LINE__);
	printf("���� �Լ��� �̸��� %s\n", __func__);
	why_me();

	return 0;
}

void why_me(void)
{
	printf("���� �Լ��� �̸��� %s\n", __func__);
	printf("���� ���� ��ȣ�� %d.\n", __LINE__);
}