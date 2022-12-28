/*
	- C���α׷��ֿ��� �߻� ���������� ����ϴ� ���� �� �ܰ�
		1. ���������� �װ��� ������ �߻����̰� �������� ������� �����Ѵ�.
		2. ���ο� ���������� ��Ÿ���� �Լ� �������̽��� ����Ѵ�.
		3. �� �������̽��� �����ϴ� �������� �ڵ带 �ۼ��Ѵ�.

	- ť ADT �����ϱ�
		�������� �̸�: ť
		�������� �Ӽ�: �׸���� ���ĵ� �������� ������ �� �ִ�.
		�������� ����: ť�� ��� �ִ� ���·� �ʱ�ȭ�Ѵ�.
					  ť�� ����ִ��� Ȯ���Ѵ�.
					  ť�� ���� �� �ִ��� Ȯ���Ѵ�.
					  ť�� �󸶳� ���� �׸���� �ִ��� Ȯ���Ѵ�.
					  �׸��� ť�� �Ĺ̿� �߰��Ѵ�.
					  ť�� ���ο��� �׺��� �����ϰ� �����Ѵ�.
					  ť�� ����.
*/
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef int Item;
#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct queue
{
	Node* front;
	Node* rear;
	int items;
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* pq);
void EmptyTheQueue(Queue* pq);



#endif
