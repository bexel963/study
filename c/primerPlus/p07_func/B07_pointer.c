/*
	- ������ ������ �ּҸ� ������ ������.

	- ptr�̶�� �̸��� ������ ������ ������ �ִٸ� ������ ���� ������ ����� �� �ִ�.
			ptr = &pooh;
	  ptr�� ���� ������ �º���(Lvalue)�̸� &pooh�� �캯��(Rvalue)�̴�. => ptr�� �ٸ� ���� ����Ű���� ������ �� �ִ�.

	- ������ ���� �� �� �����Ͱ� ����Ű�� ������ ���������� �Բ� �˷��־�� �Ѵ�. �� ������, ���� �ٸ� ���������� ��������
	  �޸𸮸� �����ϴ� ũ�Ⱑ �ٸ���, �Ϻ� ������ ������ �׿� ���� �޸� ũ�⸦ �䱸�ϱ� �����̴�.

			int *pi;			-> pi�� int�� ���� ������ ����Ű�� �������̴�.
			char *pc;			-> pc�� char�� ���� ������ ����Ű�� �������̴�.
			float *pf, *pg;		-> pf, pg�� float�� ������ ����Ű�� �������̴�.

	- �����͸���ũ(*)�� �� ������ �����Ͷ�� ���� ��Ÿ����. 
	  int *pi;��� ������, pi�� �������̰� *pi�� int������ ��Ÿ����.

	- pc�� ����Ű�� �ּҿ� ����Ǿ� �ִ� ��(*pc)�� char���̴�.
	  pc ��ü�� 'char���� ����Ű�� �������� �̴�'.
	  pc�� ���� �ּ��̸�, �װ��� ��κ��� �ý��ۿ��� ���������� ��ȣ ���� ������ ǥ���Ѵ�. �׷��� �����ʹ� �������� �ƴϴ�.
	  �����δ� �� �� ������ �����ͷδ� �� �� ���� �۾����� �ְ�, �� �ݴ��� �۾��鵵 �ִ�.
	  ���� ���, � ������ �ٸ� ������ ���� �� �ִ�. �׷��� � �����Ϳ� �ٸ� �����͸� ���� �� ����.
	  �׷��Ƿ� ������ �����ʹ� �������� �ƴ϶� "���ο� ��������" �̴�.
*/
#include <stdio.h>

void interchange(int*, int*);

int main(void)
{
	int x = 5, y = 10;

	printf("��ȯ �� x = %d, y = %d\n", x, y);
	interchange(&x, &y);
	printf("��ȯ �� x = %d, y = %d\n", x, y);
	
	return 0;
}

// 1. �Ϲ����� �Լ������� �Լ� ���ǿ��� ���ڿ� ������ ���������� ���� �Ű������� ����� ���� �䱸�Ѵ�.

void interchange(int* x, int* y) // �ùٸ� ���������� ����Ű�� �����͸� ���ĸŰ������� ����� ���� �䱸�Ѵ�.
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}