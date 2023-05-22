#include <iostream>

const int ArSize = 8;

int sum_arr(int[], int);

int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, ArSize);
	cout << "���� ���� �� �հ�: " << sum << "\n";

	return 0;
}

int sum_arr(int arr[], int n)
{
	int total = 0;

	for (int i = 0; i < n; i++)
		total = total + arr[i];

	return total;
}

/*
	- C++�� �Լ� �Ӹ��� �Լ� ������ ���� ��, int* arr�� int arr[]�� ������ �ǹ��̴�. (�� ���¸� ��� ����� �� �ִ�.)
	  �̿ʹ� �ٸ� ��Ȳ������ int* arr�� int arr[] ǥ��� ���� �ٸ� �ǹ̸� ���´�.

	- �Լ��� �Ϲ� ������ �����ϸ� ���纻�� ������ �۾��Ѵ�. �׷��� �Լ��� �迭�� �����ϸ� ������ ������ �۾��Ѵ�.
	
*/