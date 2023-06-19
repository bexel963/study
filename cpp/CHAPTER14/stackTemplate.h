#ifndef STCKTP1_H_
#define STCKTP1_H_

template <class Type>
class Stack
{
private:
	enum { SIZE = 10 };
	int stackSize;
	Tpye* items;		// ���� �׸���� �����Ѵ�.
	int top;
public:
	
	explicit Stack(int sS = SIZE);
	bool isEmpty() { return top == 0; }
	bool isFull() { return top == stackSize; }
	bool push(const Type& item);
	bool pop(Type& item);

	Stack(const Stack& st);
	Stack& operator=(const Stack& st);
	~Stack() { delete[] items; }
};

template <class Type>
Stack<Type>::Stack(int sS) : stackSize(sS), top(0)
{
	items = new Type[stackSize];
}

template <class Type>
Stack<Type>::Stack(const Stack& st)
{
	stackSize = st.stackSize;
	top = st.top;
	items = new Type[stackSize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template <class Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < stackSize)
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

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
{
	if (this == &st)
		return *this;
	delete[] items;
	stackSize = st.stackSize;
	top = st.top;
	items = new Type[stackSize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];

	return *this;
}
/*
	- ���� ������ �Լ��� ������
		: ���������� Stack�� ���� ������ �����ϰ�, ���� ���ø� �Լ� ���ǿ����� Stack<Type>�� ���� ������ �����ߴ�.
		: Stack�� Stack<Type>�� ��� ǥ���̰�, �� Ŭ���� ��� ���� �ȿ����� ����� �� �ִ�.
		  ��, ���ø� ������ ���ο� ���ø� �Լ� ������ ���ο��� Stack�� ����� �� �ִ�.
		  �׷��� �������� �ν��� ���� ��� ���� ���� �����ڸ� ����� ���� ����, �� Ŭ���� �ٱ������� ������ ������
		  Stack<Tpye>�� ����ؾ� �Ѵ�.
*/
#endif