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
	//auto p2 = f2;	// 자동 형 변환(윗줄 코드와 같음)
	
	cout << "함수 포인터: \n";
	cout << "주소 값\n";
	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl << endl;

	cout << "================================================================\n";

	const double* (*pa[3])(const double*, int) = { f1, f2, f3 };
	const double* (**pb)(const double*, int) = pa;
	// auto pb = pa;	// (윗줄 코드와 같음)

	cout << "함수 포인터를 원소로 가지는 배열:\n";
	cout << "주소 값\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	
	cout << "\n================================================================\n";

	cout << "포인터를 원소로 가지는 배열을 가리키는 포인터: \n";
	cout << "주소 값\n";
	const double* (*(*pc)[3])(const double*, int) = &pa;
	// auto pc = &pa // (윗줄 코드와 같음)
	
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl << endl;

	cout << "================================================================\n";
	// pd를 선언하는 복잡한 방법
	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;
	
	// 또 다른 방법
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