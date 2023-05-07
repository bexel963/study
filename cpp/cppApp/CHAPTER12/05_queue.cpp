#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs) : qsize(qs)	// qsize를 qs로 초기화 한다.
{
	front = rear = NULL;
	items = 0;
	//qsize = qs;	// compile error
	//sqsize가 const이기 때문에 어떤 값으로 초기화될 수는 있지만, 거기에 어떤 값이 대입될 수는 없기 때문이다.
}
/*
	- const와 참조(&)는 생성될 때에만 초기화될 수 있다!!!
	- 생성자를 호출하면 중괄호 안의 코드가 실행되기 전에 객체가 먼저 생성된다.
	  그래서 Queue(int qs) 생성자를 호출하면, 프로그램은 먼저 4개의 멤버 변수를 위한 기억 공간을 대입한다.
	  그 다음에 프로그램은 중괄호 안으로 들어가 일반적인 대입을 통해서 대입된 그 기억 공간에 값들을 대입한다.
	  따라서 const 데이터 멤버를 초기화하려면, 프로그램 제어가 생성자 몸체에 도달하기 전인, 객체가 생성될 때 초기화해야 한다.
	  C++는 이 일을 처리하기 위해 '멤버 초기자 리스트'라는 특별한 문법을 제공한다.
	- 이 테크닉은 상수들을 초기화시키는 것에만 제한되지 않는다.
			Queue::Queue(int qs) : qsize(qs), front(NULL), rear(NULL), items(0)
			{

			}
	  이러한 멤버 초기자 리스트 문법은 생성자만이 사용할 수 있다.
	  const 클래스 멤버들과 참조로 선언된 클래스 멤버들에 대해서는 필히 이 문법을 사용해야한다.
	  (const와 참조(&)는 생성될 때에만 초기화될 수 있다!!!)
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

// 추가
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

// 삭제 (머리 항목을 item 변수에 넣고 큐에서 삭제한다.)
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