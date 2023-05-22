#include <iostream>

using namespace std;

const int SIZE = 10;

int Fill_array(double*, int);
void Show_array(double*, int);
void Reverse_array(double*, int);

int main()
{
	double arr[SIZE];
	int cnt = 0;
	cnt = Fill_array(arr, SIZE);
	Show_array(arr, cnt);
	Reverse_array(arr, cnt);
	Show_array(arr, cnt);

	return 0;
}

int Fill_array(double* arr, int n)
{
	int cnt = 0;
	cout << "크기 " << n << "개의 배열에 값을 채우시오: ";
	while (cnt < n && (cin >> arr[cnt]))
	{
		cnt++;
	}
	return cnt;
}
void Show_array(double* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void Reverse_array(double* arr, int n)
{
	double tmp = 0;
	int cnt = n / 2;
	for (int i = 0; i < cnt; i++)
	{
		tmp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = tmp;
	}
}