/*
	typedef unsigned long Item;

	class Stack
	{
	private:
		enum { MAX = 10; }
		Item items[MAX];
		int top;
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const Item& item);
		bool pop(Item& item);
	};

	- �� Ŭ������ ���������� ������ ������ ��� ���Ϸ� ���� unsigned long �κ��� �����ؾ� �Ѵ�.
	  �׸��� ���α׷��� �� ������ ���ø� ������ �� �� ��ũ���� ����� �� �ִ�. ��, typedef�δ� ���ÿ� �� ���� ���������� ��Ÿ�� �� ����.
	  �׷��� int������ ���ð� string ��ü���� ������ ���� ���α׷����� ���ÿ� ������ �� ����.
	  C++�� Ŭ���� ���ø��� �������� Ŭ���� ������ �����ϴ� �� �� ���� ����� �����Ѵ�.
*/



/*
	- ���ø����� �Լ��� �ƴϱ� ������ ���������� �������� �� ����. ���ø����� Ư���� ��ü�� �䱸��� �Բ� �����Ͽ� ����ؾ� �Ѵ�.
*/



#ifndef STACKTP_H_
#define STACKTP_H_


template <class Type>	// class ��ſ� typename�� ����ص� �ȴ�.
class Stack
{
private:
	enum { MAX = 10 };
	Type items[MAX];
	int top;
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);
	
};

template <class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template <class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}

template <class Type>
bool Stack<Type>::isfull()
{
	return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
bool Stack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

#endif

