#include <iostream>

void swapr(int&, int&);
void swapp(int*, int*);
void swapv(int, int);

int main()
{
	using namespace std;
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "����1 = " << wallet1 << "��";
	cout << ", ����2 = " << wallet2 << "��\n\n";

	cout << "������ �̿��Ͽ� ������� ��ȯ:\n";
	swapr(wallet1, wallet2);						// ������ ����.
	cout << "����1 = " << wallet1 << "��";
	cout << ", ����2 = " << wallet2 << "��\n\n";

	cout << "�����͸� �̿��Ͽ� ������� �ٽ� ��ȯ:\n";
	swapp(&wallet1, &wallet2);						// ������ �ּҸ� ����.
	cout << "����1 = " << wallet1 << "��";
	cout << ", ����2 = " << wallet2 << "��\n\n";

	cout << "������ �����Ͽ� ���� ��ȯ �õ�:\n";
	swapv(wallet1, wallet2);						// ������ ���� ����
	cout << "����1 = " << wallet1 << "��";
	cout << ", ����2 = " << wallet2 << "��\n\n";

	return 0;
}

void swapr(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
void swapp(int* p, int* q)
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