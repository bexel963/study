#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)	// qsize�� qs�� �ʱ�ȭ �Ѵ�.
{
	front = rear = NULL;
	items = 0;
	//qsize = qs;	// compile error
	//sqsize�� const�̱� ������ � ������ �ʱ�ȭ�� ���� ������, �ű⿡ � ���� ���Ե� ���� ���� �����̴�.
}
/*
	- const�� ����(&)�� ������ ������ �ʱ�ȭ�� �� �ִ�!!!
	- �����ڸ� ȣ���ϸ� �߰�ȣ ���� �ڵ尡 ����Ǳ� ���� ��ü�� ���� �����ȴ�.
	  �׷��� Queue(int qs) �����ڸ� ȣ���ϸ�, ���α׷��� ���� 4���� ��� ������ ���� ��� ������ �����Ѵ�.
	  �� ������ ���α׷��� �߰�ȣ ������ �� �Ϲ����� ������ ���ؼ� ���Ե� �� ��� ������ ������ �����Ѵ�.
	  ���� const ������ ����� �ʱ�ȭ�Ϸ���, ���α׷� ��� ������ ��ü�� �����ϱ� ����, ��ü�� ������ �� �ʱ�ȭ�ؾ� �Ѵ�.
	  C++�� �� ���� ó���ϱ� ���� '��� �ʱ��� ����Ʈ'��� Ư���� ������ �����Ѵ�.
	- �� ��ũ���� ������� �ʱ�ȭ��Ű�� �Ϳ��� ���ѵ��� �ʴ´�.
			Queue::Queue(int qs) : qsize(qs), front(NULL), rear(NULL), items(0)
			{

			}
	  �̷��� ��� �ʱ��� ����Ʈ ������ �����ڸ��� ����� �� �ִ�.
	  const Ŭ���� ������ ������ ����� Ŭ���� ����鿡 ���ؼ��� ���� �� ������ ����ؾ��Ѵ�.
	  (const�� ����(&)�� ������ ������ �ʱ�ȭ�� �� �ִ�!!!)
*/

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isempty() const
{
	return items == 0;
}
bool Queue::isfull() const
{
	return items == qsize;
}
int Queue::queuecount() const
{
	return items;
}

// �߰�
bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;

	return true;
}

// ���� (�Ӹ� �׸��� item ������ �ְ� ť���� �����Ѵ�.)
bool Queue::dequeue(Item& item)
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;

	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}