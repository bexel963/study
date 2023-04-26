#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };		// 클래스용 상수
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
};

#endif

/*
	- private 부분은 스택이 배열로 구현되었음을 보여준다. 그러나 public 부분은 그 사실을 드러내지 않는다.
	  그래서 사용자는 클래스 인터페이스를 변경하는 일 없이 그 배열을 동적 배열로 교체할 수 있다.
	  이것은 스택 구현을 변경하더라도 그 스택을 사용하는 프로그램들은 다시 작성할 필요가 없다는 뜻이다.
	  단지 스택 구현 코드만 다시 컴파일하여 기존의 프로그램 코드와 링크하면 된다.
	- 클래스는 스택을 어떤 특정형으로 정의하지 않고, 하나의 일반적은 Item형으로 스택을 서술한다.
	  사용자가 double형의 스택이나 구조체형의 스택을 원한다면, typedef만 변경하고 클래스 선언과 메서드 정의는 변경하지 않아도 된다.
*/