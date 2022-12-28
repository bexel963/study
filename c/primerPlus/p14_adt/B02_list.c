#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 지역 함수 프로토타입
static void CopyToNode(Item item, Node* pnode);

// 인터페이스 함수

// 리스트를 빈 상태로 초기화한다.
void InitializeList(List* plist)
{
	*plist = NULL;
}

bool ListIsEmpty(const List* plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List* plist)
{
	Node* pt;
	bool full;

	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;

	free(pt);

	return full;
}

unsigned int ListItemCount(const List* plist) // List가 이미 포인터이기 때문에, plist는 포인터를 가리키는 포인터이다.
{
	unsigned int count = 0;	// plist는 포인터를 가리키는 포인터이다.
	ㅣ
	Node* pnode = *plist;	// *plist는 Node를 가리키는 포인터이다.

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

// 노드 생성 후 리스트의 끝에 추가
bool AddItem(Item item, List* plist)
{
	Node* pnew;
	Node* scan = *plist;	// 리스트의 시작으로 설정

	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;

	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		*plist = pnew;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}

	return true;
}

// 각 노드에 접근하여 pfun이 가리키는 함수를 적용한다.
void Traverse(const List* plist, void (*pfun)(Item item))
{
	Node* pnode = *plist;	// 리스트의 시작으로 설정

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List* plist)
{
	Node* psave;

	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;	// 구조체 복사
}