#include <iostream>

const int ArSize = 8;

int sum_arr(int[], int);

int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	
	cout << "�迭 �ּ� = " << cookies << endl;
	cout << "sizeof cookies = " << sizeof cookies << endl << endl;		// 32
	
	int sum = sum_arr(cookies, ArSize);
	cout << "���� ���� �� �հ�: " << sum << "\n\n";
	
	sum = sum_arr(cookies, 3);
	cout << "ó�� �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n\n";
	
	sum = sum_arr(cookies + 4, 4);
	cout << "������ �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n\n";

	return 0;
}

int sum_arr(int arr[], int n)
{
	using namespace std;

	int total = 0;
	
	cout << "arr        = " << arr << endl;
	cout << "sizeof arr = " << sizeof arr << endl;		// 4

	for (int i = 0; i < n; i++)
		total = total + arr[i];

	return total;
}

/*
	- sizeof cookies�� �迭 ��ü�� ũ�⸦ �ǹ��Ѵ�.
	- sizeof arr�� ������ ������ ũ�⸦ �ǹ��Ѵ�.
		=> sum_arr() �Լ��� �迭 ������ ������ �� �� �ִ� ������ ����� �� ��° �Ű������� ���ؼ��̴�.
*/