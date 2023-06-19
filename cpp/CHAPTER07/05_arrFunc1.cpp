#include <iostream>

const int ArSize = 8;

int sum_arr(int[], int);

int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, ArSize);
	cout << "먹은 과자 수 합계: " << sum << "\n";

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
	- C++의 함수 머리나 함수 원형에 사용될 때, int* arr와 int arr[]는 동일한 의미이다. (두 형태를 모두 사용할 수 있다.)
	  이와는 다른 상황에서는 int* arr와 int arr[] 표기는 서로 다른 의미를 갖는다.

	- 함수에 일반 변수를 전달하면 복사본을 가지고 작업한다. 그러나 함수에 배열을 전달하면 원본을 가지고 작업한다.
	
*/