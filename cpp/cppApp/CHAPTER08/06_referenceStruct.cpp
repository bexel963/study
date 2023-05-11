#include <iostream>
#include <string>

struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws&);
void set_pc(free_throws&);
free_throws& accumulate(free_throws&, const free_throws&);

int main()
{
	// 부분 초기화 - 멤버는 0에 세팅된 상태로 남음.
	free_throws one = { "Ifelsa Branch", 13, 14 };
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };

	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);

	// 리턴 값을 매개변수로 사용
	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	// 리턴 값을 대입 값으로 사용
	dup = accumulate(team, five);
	std::cout << "team 출력: \n";
	display(team);
	std::cout << "대입 이후 dup 출력:\n";
	display(dup);
	set_pc(four);

	// 문제의 소지가 있는 대입
	accumulate(dup, five) = four;
	std::cout << "문제 소지가 있는 대입 이후 dup 출력:\n";
	display(dup);

	return 0;
}

void display(const free_throws& ft)
{
	using std::cout;
	cout << "Name: " << ft.name << '\n';
	cout << "Made: " << ft.made << '\t';
	cout << "Attempts: " << ft.attempts << '\t';
	cout << "Percent: " << ft.percent << '\n';
	cout << std::endl;
}

void set_pc(free_throws& ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * (float)ft.made / (float)ft.attempts;
	else
		ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);

	return target;
}

/*
	- 참조는 기본 built-in 데이터 타입보다는 주로 사용자 정의 데이터형에 사용하기 위해 도입된 것이다.
*/

/*
	- 함수가 종료할 때 수명이 함께 끝나는 메모리 위치에 대한 참조를 리턴하지 않아야 한다.

			const free_throws& clone(free_throws& ft)
			{
				free_throws newGuy;
				newGuy = ft;
				
				return newGuy;		// 복사본을 리턴...
			}
	  함수가 종료할 때 함께 사라질 운명인 임시 변수에 대한 참조를 리턴한다.

	- 위 문제를 피하는 방법은, 함수에 매개변수로 전달된 참조를 리턴하는 것이다. 참조 매개변수는 호출 함수가 사용하는 데이터를 참조한다.
	  그러므로 리턴되는 참조도 동일한 그 데이터를 참조한다.
	
			const free_throws& clone(free_throws& ft)
			{
				free_throws *pt;
				*pt = ft;
				
				return *pt;		// 복사본에 대한 참조를 리턴...
			}
*/