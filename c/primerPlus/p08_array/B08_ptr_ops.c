#include <stdio.h>

int main(void)
{
	int urn[5] = { 100,200,300,400,500 };
	int* ptr1, * ptr2, * ptr3;

	ptr1 = urn;
	ptr2 = &urn[2];
	printf("�������� ��, �������� �����Ͱ� ����Ű�� ��, �������� �ּ�: \n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr3 = ptr1 + 4;
	printf("\n�����Ϳ� ������ ���Ѵ�: \n");
	printf("ptr1 + 4 = %p, *(ptr1+3) = %d\n", ptr1 + 4, *(ptr1 + 3));

	ptr1++;
	printf("\nptr1++�� ������ ���� ��:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

	ptr2--;
	printf("\nptr2--�� ������ ���� ��:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

	--ptr1;
	++ptr2;
	printf("\n�� �����͸� ������ ������ �����Ѵ�:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	printf("\n�����Ϳ��� �ٸ� �����͸� ����: \n");
	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);	// %td�� �ּ� ���̸� ��Ÿ���� ����

	printf("\n�����Ϳ��� ������ ����: \n");
	printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
	
	printf("\n\n");

	return 0;
}