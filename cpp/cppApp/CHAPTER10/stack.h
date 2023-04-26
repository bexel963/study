#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };		// Ŭ������ ���
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
	- private �κ��� ������ �迭�� �����Ǿ����� �����ش�. �׷��� public �κ��� �� ����� �巯���� �ʴ´�.
	  �׷��� ����ڴ� Ŭ���� �������̽��� �����ϴ� �� ���� �� �迭�� ���� �迭�� ��ü�� �� �ִ�.
	  �̰��� ���� ������ �����ϴ��� �� ������ ����ϴ� ���α׷����� �ٽ� �ۼ��� �ʿ䰡 ���ٴ� ���̴�.
	  ���� ���� ���� �ڵ常 �ٽ� �������Ͽ� ������ ���α׷� �ڵ�� ��ũ�ϸ� �ȴ�.
	- Ŭ������ ������ � Ư�������� �������� �ʰ�, �ϳ��� �Ϲ����� Item������ ������ �����Ѵ�.
	  ����ڰ� double���� �����̳� ����ü���� ������ ���Ѵٸ�, typedef�� �����ϰ� Ŭ���� ����� �޼��� ���Ǵ� �������� �ʾƵ� �ȴ�.
*/