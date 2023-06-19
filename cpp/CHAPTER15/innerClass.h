/*
	- 클래스 선언을 내포하고 있는 클래스의 멤버 함수들은, 내포 클래스의 객체들을 생성하여 사용할 수 있다.
	  클래스 외부에서는 내포 클래스 선언이 public부분에 들어 있고, 사용 범위 결정 연산자를 사용해야만
	  내포 클래스를 사용할 수 있다.

	- 컨테인먼트는 어떤 클래스 객체를 다른 클래스의 멤버로 가지는 것이다. 
	  반면에 클래스를 내포시키는 것은 클래스 멤버를 생성하지 않는다.
	  그 대신에 내포 클래스 선언을 내포하고 있는 클래스에만 지역적으로 알려지는 하나의 데이터형을 정의한다.
	  
	- 클래스를 내포시키는 일반적인 이유는, 다른 클래스의 구현을 지원하고, 이름 충돌을 막는 것이다.

				class Queue
				{
					struct Node {
						Item item;
						struct Node* next;
					};
				}
	- 구조체는 멤버들이 디폴트로 public인 클래스이기 때문에 위 코드는 사실상 내포 클래스 선언이다.
*/

#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class QueueTP
{
private:
	enum { Q_SIZE = 10 };

	class Node
	{
	public:
		Item item;
		Node* next;
		Node(const Item& i) : item(i), next(0) { }
		/*
			- 생성자를 메서드 저으이 파일에 정의하고 싶다면 Node 클래스가 Queue 클래스 내부에 저으이된다는 사실을 반영해야 한다.
					QueueTP<Item>::Node::Node(const Item& i) : item(i), next(0) {  }
		*/
	};

	Node* front;
	Node* rear;
	int items;
	const int qsize;

	QueueTP(const QueueTP& q) : qsize(0) { }
	QueueTP& operator=(const QueueTP& q) { return *this; }

public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	int queuecount() const { return items; }
	bool enqueue(const Item& item);
	bool dequeue(Item& item);

	
};

template <class Item>
QueueTP<Item>::QueueTP(int qs) : qsize(qs)
{
	front = rear = 0;		// 포인터를 0으로 설정하는 것은, C++에서 널 포인터를 사용하는 한 가지 방법이다.
	items = 0;
}

template <class Item>
QueueTP<Item>::~QueueTP()
{
	Node* temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class Item>
bool QueueTP<Item>::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node(item);
	items++;
	if (front == 0)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template <class Item>
bool QueueTP<Item>::dequeue(Item& item)
{
	if (front == 0)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}

#endif
