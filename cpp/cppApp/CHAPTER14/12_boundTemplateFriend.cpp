/*
	2) ���ø� Ŭ������ ���� �ٿ�� ���ø� ������ �Լ�
		: ������ �Լ����� ���ø� ��ü�� ���� �� �ִ�. => �ٿ�� ���ø� ������� ����
*/

#include <iostream>
using std::cout;
using std::endl;

// ���ø� ����
template <class T> void counts();
template <class T> void report(T&);

// ���ø� Ŭ����
template <class TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT& i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);	// �� ���, �Լ� �Ű������κ��� ���ø� �������� �Ű�����(TT)�� ������ �� �ֱ� ������, <>�� �� ä�� �� �� �ִ�.
};

template <class T>
int HasFriendT<T>::ct = 0;

// ���ø� ������ �Լ����� ����
template<class T>
void counts()
{
	cout << "���ø� ũ��: " << sizeof(HasFriendT<T>) << ": ";
	cout << "���ø� coutns() : " << HasFriendT<T>::ct << endl;
}

template<class T>
void report(T& hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);

	report(hfi1);		// report(HasFriendT<int>&)�� ����
	report(hfi2);		// report(HasFriendT<int>&)�� ����
	report(hfdb);		// report(HasFriendT<double>&)�� ����
	
	cout << "counts<int>() ���: \n";
	counts<int>();

	cout << "counts<double>() ���: \n";
	counts<double>();

	return 0;
}