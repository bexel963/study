#include <iostream>

const double* f1(const double[], int);
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
	using namespace std;
	double av[3] = { 1112.3, 1542.6, 2227.9 };

	const double* (*p1)(const double*, int) = f1;
	const double* (*p2)(const double*, int) = f2;
	//auto p2 = f2;	// �ڵ� �� ��ȯ(���� �ڵ�� ����)
	
	cout << "�Լ� ������: \n";
	cout << "�ּ� ��\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl << endl;

	cout << "================================================================\n";

	const double* (*pa[3])(const double*, int) = { f1, f2, f3 };
	const double* (**pb)(const double*, int) = pa;
	// auto pb = pa;	// (���� �ڵ�� ����)

	cout << "�Լ� �����͸� ���ҷ� ������ �迭:\n";
	cout << "�ּ� ��\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	
	cout << "\n================================================================\n";

	cout << "�����͸� ���ҷ� ������ �迭�� ����Ű�� ������: \n";
	cout << "�ּ� ��\n";
	const double* (*(*pc)[3])(const double*, int) = &pa;
	// auto pc = &pa // (���� �ڵ�� ����)
	
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl << endl;

	cout << "================================================================\n";
	// pd�� �����ϴ� ������ ���
	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;
	
	// �� �ٸ� ���
	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;

	return 0;
}

const double* f1(const double* ar, int n)
{
	return ar;
}
const double* f2(const double ar[], int n)
{
	return ar + 1;
}
const double* f3(const double ar[], int n)
{
	return ar + 2;
}