#include <iostream>
using std::cout;
using std::endl;

template <class T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i) : item(i) { }
	template <class C, class D> friend void show2(C&, D&);
};

template <class C, class D> void show2(C& c, D& d)
{
	cout << c.item << ", " << d.item << endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);

	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	// Ư��ȭ => void show2<ManyFriend<int>&, ManyFriend<int>&>(ManyFriend<int>& c, ManyFriend<int>& d);
	/*
		- �̰��� ManyFriend�� ��� Ư��ȭ�� ���� �������̱� ������, �� �Լ��� ��� Ư��ȭ���� item ����� ������ �� �ִ�.
		  �׷��� ManyFriend<int> ��ü�鿡 ���� ���ٸ��� ����Ѵ�.
	*/

	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);
	// => void show2<ManyFriend<double>&, ManyFriend<int>&>(ManyFriend<double>& c, ManyFriend<int>& d);
	/*
		- �̰��� ManyFriend�� ��� Ư��ȭ�� ���� �������̱� ������, �� �Լ��� ��� Ư��ȭ���� item ����� ������ �� �ִ�.
		  �� �Լ��� ManyFriend<int> ��ü�� item �����, ManyFriend<double> ��ü�� item ����� ���� ������ ����Ѵ�.
	*/

	return 0;
}

/*
	- �ٿ�� ���ø� ������ �Լ����� Ŭ������ �ٱ����� ����� ���ø��� ���ø� Ư��ȭ���̴�.
	  �������, int Ŭ���� Ư��ȭ�� int �Լ� Ư��ȭ�� ��� �����̴�.
	- ���ø��� Ŭ���� �ȿ� ���������ν�, ��ٿ�� ������ �Լ��� ������ �� �ִ�.
	  �� �� ��� �Լ� Ư��ȭ�� ��� Ŭ���� Ư��ȭ�� ���� �������̴�.
	  ��ٿ�� ��������� ��쿡, ������ ���ø� �������� �Ű��������� ���ø� Ŭ���� �������� �Ű�������� �ٸ���.
	  
*/