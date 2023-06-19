#include <iostream>
#include "stackTemplate.h"

template <template <class T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() { };
	
	// Thing Ŭ������ push()�� pop() ����� ������ �ִٰ� �����Ѵ�.
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }
};
/*
	- Crab Ŭ���� ������ Thing���� ��Ÿ���� ���ø� Ŭ������ ���� �� ������ �����Ѵ�.
		  �� Ŭ������ push()�� ������ �Ѵ�.
		  �� Ŭ������ pop()�� ������ �Ѵ�.
		  �� �޼������ �ϳ��� Ư���� �������̽��� ������ �Ѵ�.
	- Crab Ŭ������ Thing�� ����� ��ġ�ϰ�, push() �޼���� pop() �޼��带 �ݵ�� ������ �ִ� � ���ø� Ŭ������ ����� �� �ִ�.
*/

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	Crab<Stack> nebula;		
	/*
		- Stack Ŭ������ template <class T> class Thing�� ��ġ�ؾ� �Ѵ�.
		- ��üȭ
			Thing<int> s1;		=> Stack<int> s1;
			Thing<double> s2;	=> Stack<double> s2;
	*/

	int ni;
	double nb;
	cout << "4 3.5�� ���� int double ���� �Է��϶�(�������� 0 0):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}

	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	
	cout << "���α׷� ����\n";

	return 0;
}


/*
	- ���ø� �Ű������� �Ϲ� �Ű������� ȥ���Ͽ� ����� �� �ִ�.

	template <template <class T> class Thing, class U, class V>
	class Crab
	{
	private:
		Thing<U> s1;
		Thing<V> s2;
		...
	}

	int main()
	{
		Crab<Stack, int, double> nebula;
	}
*/
