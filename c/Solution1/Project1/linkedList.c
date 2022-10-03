#include<stdio.h>

/*
	- Single linked list (container)
		- ���� ����Ʈ�� ���� ����ü �ν��Ͻ��� ü��ó�� ������ �����ͷ� ������ �ڷᱸ���̴�.
		- ���ῡ ���� ������ ���ڰ� �� ���̰�, �ڱ� ������ ����Ű�� ���� Ư¡�̴�.
		- �⺻���� ������ �����̴�.

	- �ڵ� ���
		- �ڷᱸ���� DB�̴�.
		- ����ü �迭�� �׽�Ʈ �Ѵ�.
		- ���� ������ ���Ƿ� ���� �غ���.
		- ����Ʈ ����� ������ �Լ��� �и��Ѵ�.
		- ����ŷ� ��� �ϳ��� ���󰡸� �޸� ��ġ�� Ȯ���Ѵ�.
*/
typedef struct NODE {
	int nData;
	struct NODE* next;
} NODE;

int main() {

	NODE list[5] = { 0 };

	// �� ����
	list[0].nData = 100;
	list[1].nData = 200;
	list[2].nData = 300;
	list[3].nData = 400;
	list[4].nData = 500;

	// ���� ����Ʈ ����ȭ
	list[0].next = &list[1];
	list[1].next = &list[2];
	list[2].next = &list[3];
	list[3].next = &list[4];
	list[4].next = 0;	// NULL��� 0 ��� ���� - �ּ� 0�������� ���� ������ �� ����. (���� ��� ���α׷� ���.)

	for (int i = 0; i < 5; i++)
		printf("list[%d].nData = %d\n", i, list[i].nData);
	printf("\n");

	NODE* pTmp = list;

	while (pTmp->next != 0) {
		printf("%p = %d\n", pTmp, pTmp->nData);
		pTmp = pTmp -> next;
	}

	return 0;
}