#include <iostream>

void swapr(int&, int&);
void swapp(int*, int*);
void swapv(int, int);

int main()
{
	using namespace std;
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "지갑1 = " << wallet1 << "원";
	cout << ", 지값2 = " << wallet2 << "원\n\n";

	cout << "참조를 이용하여 내용들을 교환:\n";
	swapr(wallet1, wallet2);						// 변수를 전달.
	cout << "지갑1 = " << wallet1 << "원";
	cout << ", 지값2 = " << wallet2 << "원\n\n";

	cout << "포인터를 이용하여 내용들을 다시 교환:\n";
	swapp(&wallet1, &wallet2);						// 변수의 주소를 전달.
	cout << "지갑1 = " << wallet1 << "원";
	cout << ", 지값2 = " << wallet2 << "원\n\n";

	cout << "값으로 전달하여 내용 교환 시도:\n";
	swapv(wallet1, wallet2);						// 변수의 값을 전달
	cout << "지갑1 = " << wallet1 << "원";
	cout << ", 지값2 = " << wallet2 << "원\n\n";

	return 0;
}

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void swapp(int* p, int* q)	// 참조와 달리 포인터를 이용하는 경우, 함수가 p와 q를 사용할 때마다 내용 참조 연산자인 *를 사용해야 한다.
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
/*
	- 참조로 전달하면 피호출 함수가 호출 함수의 변수를 사용할 수 있다.
	  C++에 새로 추가된 이 기능은 오로지 값으로만 전달하는 C로부터 탈피하는 것이다.
*/