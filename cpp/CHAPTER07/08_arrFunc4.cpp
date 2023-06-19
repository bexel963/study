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

/*
	- C�� C++�� �迭�� ó���ϴ� �Լ��� ������ ���.
		1) ù ��° �Ű������� �迭�� ���� ��ġ�� �����ϴ� �����͸� �����ϰ�, �� ��° �Ű������� �迭�� ũ�⸦ �����Ѵ�.
		   (�� �����ʹ� �迭�� ��� �ִ�����, �迭�� ��� �ִ� �������� ������ ���������� �����ش�.)
		2) �� ���� ������ ��, �迭�� ������ �����ϴ� �����Ϳ� �迭�� ���� �����ϴ� �����͸� �����Ѵ�.
			: C++ ǥ�� ���ø� ���̺귯�� ������ �̷��� ���� ���� ����� �Ϲ�ȭ�Ѵ�.
			  STL ���� ����� ���ҵ��� ������ �����ϱ� ���� "�� �ٷ� ����" �̶�� ������ ����Ѵ�.
			  ��, � �迭�� �ִٰ� ���� ��, �迭�� ���� �ν��ϱ� ���� �Ű������� �迭�� ������ ���� �ٷ� ������ �����ϴ� �����Ͱ� �� ���̴�.
*/

/*
	- const Ű����� �����Ϳ� �� ���� ������� ���ȴ�.
		1) ��� ��ü�� �����ϴ� �����͸� ����� �� -> �����ü�� �����ϴ� �����͸� ����Ͽ� �� �����Ͱ� �����ϴ� ���� ������ �� ����.
				int age = 34;
				const int* pt = &age;	// const int�� �����ϴ� ������
		2) ������ �ڽ��� ����� ����� �� -> ��� �����͸� ����Ͽ� �� �����Ͱ� �����ϴ� ��Ҹ� ������ �� ����.
				int age = 34;
				int* const pt = &age;	// int�� �����ϴ� const ������

	- C++�� const ������ �ּҸ� const�� �ƴ� �Ϲ� �����Ϳ� �����ϴ� ���� �����Ѵ�.
				const float moon = 1.63;
				float* pm = &moon;	// Error

				const int months[12] = { 31, 28, ..... };
				int sum(int arr[], int n);
				...
				int j = sum(months, 12);	// Error

	- const�� �⺻���� �����ϴ� �����Ϳ��� ��� �����ϴ�.
*/

/*
	- �Լ��� 2���� �迭
		
		int sum(int (*arr)[4], int size);	// �Լ� ����
		int sum(int arr[][4], int size);	// �̷��� �ص� ��.

			arr[r][c] == *(*(arr + r) + c)
			
			arr					=> ù ��° ��(int�� 4��¥�� �迭)�� �����ϴ� ������
			arr + r				=> r ��° ��(int�� 4��¥�� �迭)�� �����ϴ� ������
			*(arr + r)			=> r ��° ���� int���� �����ϴ� ������. ��, arr[r]
			*(arr + r) + c		=> r ��° ���� c ��° int���� �����ϴ� ������. ��, arr[r] + c
			*(*(arr + r) + c)	=> r ��° ���� c ��° int���� ��. ��, arr[r][c]

		int data[3][4] = { {1,2,3,4}, {9,8,7,6}, {2,4,6,8} };	// �� �迭�� ù ��° ���Ҵ� �� ��ü�� 4���� int���� ������ �ִ� �迭�̴�.
		int total = sum(data, 3);

		
		int (*arr)[4]	=> 4���� int���� ���� �迭�� �����ϴ� ������
		int *arr[4]		=> int���� �����ϴ� �����͸� 4�� ������ �ִ� �迭�� ����
*/