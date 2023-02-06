#include <iostream>

const int ArSize = 8;

int sum_arr(int[], int);

int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	
	cout << "배열 주소 = " << cookies << endl;
	cout << "sizeof cookies = " << sizeof cookies << endl << endl;;
	
	int sum = sum_arr(cookies, ArSize);
	cout << "먹은 과자 수 합계: " << sum << "\n\n";
	
	sum = sum_arr(cookies, 3);
	cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다.\n\n";
	
	sum = sum_arr(cookies + 4, 4);
	cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n\n";

	return 0;
}

int sum_arr(int arr[], int n)
{
	using namespace std;

	int total = 0;
	
	cout << "arr        = " << arr << endl;
	cout << "sizeof arr = " << sizeof arr << endl;

	for (int i = 0; i < n; i++)
		total = total + arr[i];

	return total;
}