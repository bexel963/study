/*
	- ���ø��� ������
		1) ���ø��� �ƴ� ������
		2) �ٿ�� ���ø� ������	-> Ŭ������ ��üȭ�� �� Ŭ������ ���������� ���� �������� ���������� �����ȴ�.
		3) ��ٿ�� ���ø� ������	-> �������� ��� Ư��ȭ�� �� Ŭ������ �� Ư��ȭ�� ���� ��������̴�.
*/

/*
	1) ���ø� Ŭ������ ���� ���ø��� �ƴ� ������ �Լ�
				template <class T>
				class HasFriend
				{
					friend void counts();
					...
				};
	   �� ������ counts() �Լ��� �� ���ø��� ������ ��� ��üȭ�鿡 ���� ������� �����.
	   �������, counts()�� HasFirend<int> Ŭ������ HasFriend<string> Ŭ���� ��ο� ���ؼ� �������̴�.
	   ������� HasFriend ��ü�� ��� ������ �� ������?
		   1) ���� ��ü�� ������ �� �ִ�.
		   2) ���������͸� ����Ͽ� ������ �ƴ� ��ü�� ������ �� �ִ�.
		   3) ���ø� Ŭ������ static ������ ����� ������ �� �ִ�. �׷��� static ������ ������� ��ü�� ���� �и��Ǿ� �����Ѵ�.
	
	   � ������ �Լ��� ���ø� Ŭ���� �Ű������� �����ϱ⸦ ���Ѵٰ� ������ �� friend void report(HasFriend&); �� ���� ������ �Ұ����ϴ�.
	   HasFriend ��ü�� ���� ���� ���� ����...., HasFriend<short>�� ���� Ư���� Ư��ȭ���� �����Ѵ�...
	   ���� ���ø� Ŭ���� �Ű������� �����Ϸ���, �ϳ��� Ư��ȭ�� ��Ÿ���� �Ѵ�.
				template <class T>
				class HasFriend
				{
					friend void report(HasFriend<T>&);	// �ٿ�� ���ø� ������
					...
				};

	   HasFriend<int> hf; �� ���� Ư���� ���������� ��ü�� ������ �� �����Ϸ��� ���ø� �Ű����� T�� int�� ��ü�Ѵ�.
	   �̰��� ������ ���� ������ ������ ������ ������ ���̴�.
				template <class T>
				class HasFriend
				{
					friend void report(HasFriend<int>&);	// �ٿ�� ���ø� ������
					...
				};

	   ��, HasFriend<int>�� ������ ��ü�� report()�� HasFriend<int> Ŭ������ ���� �����尡 �ȴ�.
	       HasFriend<double>�� ������ ��ü�� report()�� HasFriend<double> Ŭ������ ���� ��������, �����ε� ������ report()�� �ȴ�.
	   report()�� ���ø� �Լ��� �ƴϴ�. ���� �װ��� ���ø��� �Ű������� ������.
	   �̰��� ����Ϸ��� ������鿡 ���ؼ� ����� Ư��ȭ�� ������ �־�� �Ѵٴ� ���� �ǹ��Ѵ�.
				void report(HasFriend<short>&) {...};	// short�� ���� ����� Ư��ȭ
				void report(HasFriend<int>&) {...};		// int�� ���� ����� Ư��ȭ
		  
*/

#include <iostream>
using std::cout;
using std::endl;

template <class T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void report(HasFriend<T>&);		// ���ø� �Ű�����
};

// �� Ư��ȭ�� �ڽŸ��� static ������ ����� ������.
template <class T>
int HasFriend<T>::ct = 0;

// ��� HasFriend<T> Ŭ������ ���� ���ø��� �ƴ� ������
void counts()
{
	cout << "int ī��Ʈ: " << HasFriend<int>::ct << "; ";
	cout << "double ī��Ʈ: " << HasFriend<double>::ct << endl;
}

// HasFriend<int> Ŭ������ ���� ���ø��� �ƴ� ������
void report(HasFriend<int>& hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

// HasFriend<double> Ŭ������ ���� ���ø��� �ƴ� ������
void report(HasFriend<double>& hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout << "����� ��ü ����: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "hfi1 ���� ��: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "hfi2 ���� ��: ";
	counts();

	HasFriend<double> hfdb(10.5);
	cout << "hfdb ���� ��: ";
	counts();

	report(hfi1);
	report(hfi2);
	report(hfdb);

	return 0;
}