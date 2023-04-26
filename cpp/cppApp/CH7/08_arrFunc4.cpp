#include <iostream>

const int ArSize = 8;

int sum_arr(const int*, const int*);

int main()
{
	using namespace std;
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	cout << "배열 주소 = " << cookies << endl;                                           
	cout << "sizeof cookies = " << sizeof cookies << endl << endl;;

	int sum = sum_arr(cookies, cookies+ArSize);
	cout << "먹은 과자 수 합계: " << sum << "\n\n";

	sum = sum_arr(cookies, cookies + 3);
	cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다.\n\n";

	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n\n";

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
	- C와 C++가 배열을 처리하는 함수에 접근한 방법.
		1) 첫 번째 매개변수로 배열의 시작 위치를 지시하는 포인터를 전달하고, 두 번째 매개변수로 배열의 크기를 전달한다.
		   (그 포인터는 배열이 어디에 있는지와, 배열에 들어 있는 데이터의 종류가 무엇인지를 말해준다.)
		2) 두 개의 포인터 즉, 배열의 시작을 지시하는 포인터와 배열의 끝을 지시하는 포인터를 전달한다.
			: C++ 표준 템플릿 라이브러리 에서는 이러한 범위 접근 방법을 일반화한다.
			  STL 접근 방법은 원소들의 범위를 지정하기 위해 "끝 바로 다음" 이라는 개념을 사용한다.
			  즉, 어떤 배열이 있다고 했을 때, 배열의 끝을 인식하기 위한 매개변수는 배열의 마지막 원소 바로 다음을 지시하는 포인터가 될 것이다.
*/

/*
	- const 키워드는 포인터에 두 가지 방법으로 사용된다.
		1) 상수 객체를 지시하는 포인터를 만드는 것 -> 상수객체를 지시하는 포인터를 사용하여 그 포인터가 지시하는 값을 변경할 수 없다.
				int age = 34;
				const int* pt = &age;	// const int를 지시하는 포인터
		2) 포인터 자신을 상수로 만드는 것 -> 상수 포인터를 사용하여 그 포인터가 지시하는 장소를 변경할 수 없다.
				int age = 34;
				int* const pt = &age;	// int를 지시하는 const 포인터

	- C++는 const 변수의 주소를 const가 아닌 일반 포인터에 대입하는 것을 금지한다.
				const float moon = 1.63;
				float* pm = &moon;	// Error

				const int months[12] = { 31, 28, ..... };
				int sum(int arr[], int n);
				...
				int j = sum(months, 12);	// Error

	- const는 기본형을 지시하는 포인터에만 사용 가능하다.
*/

/*
	- 함수와 2차원 배열
		
		int sum(int (*arr)[4], int size);	// 함수 원형
		int sum(int arr[][4], int size);	// 이렇게 해도 됨.

			arr[r][c] == *(*(arr + r) + c)
			
			arr					=> 첫 번째 행(int형 4개짜리 배열)을 지시하는 포인터
			arr + r				=> r 번째 행(int형 4개짜리 배열)을 지시하는 포인터
			*(arr + r)			=> r 번째 행의 int형을 지시하는 포인터. 즉, arr[r]
			*(arr + r) + c		=> r 번째 행의 c 번째 int형을 지시하는 포인터. 즉, arr[r] + c
			*(*(arr + r) + c)	=> r 번째 행의 c 번째 int형의 값. 즉, arr[r][c]

		int data[3][4] = { {1,2,3,4}, {9,8,7,6}, {2,4,6,8} };	// 이 배열의 첫 번째 원소는 그 자체가 4개의 int값을 가지고 있는 배열이다.
		int total = sum(data, 3);

		
		int (*arr)[4]	=> 4개의 int값을 가진 배열을 지시하는 포인터
		int *arr[4]		=> int값을 지시하는 포인터를 4개 가지고 있는 배열을 선언
*/