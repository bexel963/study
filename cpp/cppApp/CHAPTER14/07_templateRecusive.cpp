#include <iostream>
#include "arrayTemplate.h"

int main()
{
	using std::cout;
	using std::endl;
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);	// 정수를 출력할 때 더 큰 폭이 필요 없다면, 그 다음 항목이 영문자 2개 크기의 필드 폭으로 출력되도록 만든다.
			cout << twodee[i][j] << ' ';
		}
		cout << ": 합계 = ";
		cout.width(3);
		cout << sums[i] << ", 평균 = " << aves[i] << endl;
	}

	cout << "프로그램을 종료합니다.\n";

	return 0;

}

/*
	- 템플릿의 재귀적 사용
		ArrayTP < ArrayTP<int, 5>, 10 > twodee;
		: 이것은 twodee를 10개의 원소를 가진 배열로 만든다. 그 배열의 각 원소는 5개의 int값으로 이루어진 배열이다.
		  보통의 배열을 사용하는 이와 동등한 선언은 다음과 같다.
				int twodee[10][5];
		  템플릿을 사용하는 문법은 보통의 2차원 배열을 사용하는 문법과 차원을 나타내는 순서가 반대이다.
*/