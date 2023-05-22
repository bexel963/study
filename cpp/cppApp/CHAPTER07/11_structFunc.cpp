#include <iostream>

struct travel_time
{
	int hours;
	int mins;
};

const int Mins_per_hr = 60;

travel_time sum(travel_time, travel_time);
void show_time(travel_time);

int main()
{
	using namespace std;
	travel_time day1 = { 5, 45 };
	travel_time day2 = { 4, 55 };

	travel_time trip = sum(day1, day2);
	cout << "이틀간 소요시간: ";
	show_time(trip);

	travel_time day3 = { 4, 32 };
	cout << "사흘간 소요시간: ";
	show_time(sum(trip, day3));

	return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
	travel_time total;

	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;

	return total;
}

void show_time(travel_time t)
{
	using namespace std;
	cout << t.hours << "시간 " << t.mins << "분\n";
}

/*
	- 구조체 변수와 배열은 둘 다 여러 개의 항목을 한 군데에 모아서 저장한다는 점에서 비슷하지만,
	  구조체 변수는 기본적으며 단일한 값을 가지는 보통의 변수처럼 행동한다.
	- 구조체 변수는 보통의 변수처럼 함수에 값으로 전달할 수 있다.
	- 함수는 구조체를 리턴할 수 있다.
	- 배열 이름은 그 배열의 첫 번째 원소의 주소라는 등의 특별한 어떤 것이 구조체에는 없다.
*/