#include <iostream>

template <class Any>
void Swap(Any& a, Any& b);


int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�\n";
	Swap(i, j);
	cout << "���� i, j = " << i << ", " << j << ".\n\n";
	
	double x = 24.5;
	double y = 81.5;
	cout << "x, y = " << x << ", " << y << ".\n";
	cout << "�����Ϸ��� ������ double�� ��ȯ�⸦ ����ϸ�\n";
	Swap(x, y);
	cout << "���� x, y = " << x << ", " << y << ".\n";

	return 0;
}

template <class Any>
void Swap(Any& a, Any& b)
{
	Any temp;
	temp = a;
	a = b;
	b = temp;
}