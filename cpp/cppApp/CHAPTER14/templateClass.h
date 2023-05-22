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

	- 이 클래스는 데이터형을 변경할 때마다 헤더 파일로 가서 unsigned long 부분을 수정해야 한다.
	  그리고 프로그램당 한 종류의 스택만 생성할 때 이 테크닉을 사용할 수 있다. 즉, typedef로는 동시에 두 가지 데이터형을 나타낼 수 없다.
	  그래서 int값들의 스택과 string 객체들의 스택을 같은 프로그램에서 동시에 정의할 수 없다.
	  C++의 클래스 템플릿은 포괄적인 클래스 선언을 생성하는 좀 더 나은 방법을 제공한다.
*/



/*
	- 템플릿들은 함수가 아니기 때문에 개별적으로 컴파일할 수 없다. 템플릿들은 특별한 구체와 요구들과 함께 결합하여 사용해야 한다.
*/



#ifndef STACKTP_H_
#define STACKTP_H_


template <class Type>	// class 대신에 typename을 사용해도 된다.
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

