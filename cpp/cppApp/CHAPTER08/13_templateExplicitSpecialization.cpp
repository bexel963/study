#include <iostream>

template<typename T>
void Swap(T&, T&);

struct job
{
	char name[40];
	double salary;
	int floor;
};

//template<> void Swap<job>(job&, job&);
template<> void Swap(job&, job&);	// job�� ���� Ư��ȭ��� ���� �Լ� �Ű������� ���������� �˷� �ֱ� ������, Swap<job>�� �ִ� <job>�� ������ �� �ִ�.
void Show(job&);

int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�\n";
	Swap(i, j);				// Swap(int&, int&)�� �����Ѵ�.
	cout << "���� i, j = " << i << ", " << j << ".\n\n";

	job sue = { "Susan Yaffe", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "job ��ȯ ��: \n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);		// void Swap(job&, job&)�� �����Ѵ�.
	
	cout << "job ��ȯ ��: \n";
	Show(sue);
	Show(sidney);

	return 0;
}

template<typename T>
void Swap(T& a, T& b)	// ���ø� ����
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<> void Swap<job>(job& j1, job& j2)		// job���� ���� ����� Ư��ȭ
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j)
{
	using namespace std;
	cout << j.name << ": (" << j.floor << "���� ����) "
		<< "$" << j.salary << endl;
}

/*
	- �Լ� �̸��� �ϳ� �־�����, ����ڴ� ���ø��� �ƴ� �Լ�, ���ø� �Լ�, ����� Ư��ȭ ���ø� �Լ��� ���� �� �ִ�.
	  ���� �� ��� �͵��� �����ε� ������ ���� �� �ִ�.
	- ����� Ư��ȭ�� �ϱ� ���� ������ ���� �տ� template<>�� �;� �Ѵ�. �׸��� �� Ư������ �̸��� �����ؾ� �Ѵ�.
	- Ư��ȭ�� ���ø��� �����ϰ�, ���ø��� �ƴ� �Լ��� Ư��ȭ�� ���ø� �� �� �����Ѵ�.

	- �̵��� �Բ� ������ ��, �����Ϸ��� ����� Ư��ȭ �����̳� ���ø� �������� ���ø��� �ƴ� ������ �����Ѵ�.
	  �׸��� ���ø� �������ٴ� ����� Ư��ȭ ������ �����Ѵ�.
*/