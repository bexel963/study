#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ���� �Լ� ������Ÿ��
static void CopyToNode(Item item, Node* pnode);

// �������̽� �Լ�

// ����Ʈ�� �� ���·� �ʱ�ȭ�Ѵ�.
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

unsigned int ListItemCount(const List* plist) // List�� �̹� �������̱� ������, plist�� �����͸� ����Ű�� �������̴�.
{
	unsigned int count = 0;	// plist�� �����͸� ����Ű�� �������̴�.
	��
	Node* pnode = *plist;	// *plist�� Node�� ����Ű�� �������̴�.

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

// ��� ���� �� ����Ʈ�� ���� �߰�
bool AddItem(Item item, List* plist)
{
	Node* pnew;
	Node* scan = *plist;	// ����Ʈ�� �������� ����

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

// �� ��忡 �����Ͽ� pfun�� ����Ű�� �Լ��� �����Ѵ�.
void Traverse(const List* plist, void (*pfun)(Item item))
{
	Node* pnode = *plist;	// ����Ʈ�� �������� ����

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
	pnode->item = item;	// ����ü ����
}