#ifndef STCKTP1_H_
#define STCKTP1_H_

template <class Type>
class Stack
{
private:
	enum { SIZE = 10 };
	int stackSize;
	Tpye* items;		// 스택 항목들을 저장한다.
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
	- 대입 연산자 함수의 리턴형
		: 원형에서는 Stack에 대한 참조로 선언하고, 실제 템플릿 함수 정의에서는 Stack<Type>에 대한 참조로 선언했다.
		: Stack은 Stack<Type>의 약식 표기이고, 그 클래스 사용 범위 안에서만 사용할 수 있다.
		  즉, 템플릿 선언의 내부와 템플릿 함수 정의의 내부에서 Stack을 사용할 수 있다.
		  그러나 리턴형을 인식할 때와 사용 범위 결정 연산자를 사용할 때와 같이, 그 클래스 바깥에서는 완전한 형식인
		  Stack<Tpye>을 사용해야 한다.
*/
#endif