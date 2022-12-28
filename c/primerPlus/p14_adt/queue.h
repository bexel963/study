/*
	- C프로그래밍에서 추상 데이터형을 사용하는 과정 세 단계
		1. 데이터형과 그것의 연산을 추상적이고 포괄적인 방식으로 서술한다.
		2. 새로운 데이터형을 나타내는 함수 인터페이스를 고안한다.
		3. 그 인터페이스를 구현하는 세부적인 코드를 작성한다.

	- 큐 ADT 정의하기
		데이터형 이름: 큐
		데이터형 속성: 항목들의 정렬된 시퀀스를 저장할 수 있다.
		데이터형 연산: 큐를 비어 있는 상태로 초기화한다.
					  큐가 비어있는지 확인한다.
					  큐가 가득 차 있는지 확인한다.
					  큐에 얼마나 많은 항목들이 있는지 확인한다.
					  항목을 큐의 후미에 추가한다.
					  큐의 선두에서 항복을 제거하고 복원한다.
					  큐를 비운다.
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
