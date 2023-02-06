#include <iostream>

const int ArSize = 8;

int sum_arr(const int*, const int*);

int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	cout << "�迭 �ּ� = " << cookies << endl;                                           
	cout << "sizeof cookies = " << sizeof cookies << endl << endl;;

	int sum = sum_arr(cookies, cookies+ArSize);
	cout << "���� ���� �� �հ�: " << sum << "\n\n";

	sum = sum_arr(cookies, cookies + 3);
	cout << "ó�� �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n\n";

	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "������ �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n\n";

	return 0;
}

int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
		total = total + *pt;

	return total;
}