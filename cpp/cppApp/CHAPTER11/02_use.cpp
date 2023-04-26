#include <iostream>
#include <cstdlib>		// rand(), srand()의 원형
#include <ctime>		// time()의 원형
#include "vect.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	while (cin >> target)
	{
		cout << "보폭을 입력하십시오: ";
		if (!(cin >> dstep))
			break;
		
		while (result.magVal() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << steps << " 걸음을 걸은 후 술고래의 현재 위치:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " 또는\n" << result << endl;
		cout << "걸음당 기둥에서 벗어난 평균 거리 = "
			<< result.magVal() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "목표 겨리를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}

/*
	- rand()
		: 0에서부터 구현 시스템에 따라 다른 어떤 특정 값의 범위에 속하는 하나의 무작위 정수를 리턴
		: 초기 씨앗값에 어떤 알고리즘을 적용하여 하나의 무작위 값을 얻는다.
		  그 무작위 값은 다시 다음 번 함수 호출에 씨앗값으로 사용되어 동일한 난수 집합이 생긴다.
	- srand()
		: 디폴트 씨앗값을 무시하고 다른 난수 집합을 발생시킬 수 있다.
	- time(0)
		: 특정 지정일로부터 경과한 현재의 달력 시간을 초 단위 수로 리턴한다.
	- srand(time(0))
		: 프로그램을 실행할 때마다 다른 씨앗값을 설정한다.
*/