/*
	- 연산자 오버로딩
		: = 나 + 와 같은 C++의 표준 연산자를 클래스 객체에 사용할 수 있게 해 주는 것이다.
		: C++가 가진 다형(polymorphism) 특성의 한 예이다.
		: C++는 피연산자의 개수와 데이터 형을 판단하여 어떤 연산을 수행해야 하는지를 결정한다.
		: 오버로딩된 연산자 표기는 내부 계산은 드러내지 않고, 단지 해당 객체들에 대해서 연산하고 있다는 사실만 강조한다.

	- 연산자 함수
		: 연산자를 오버로딩 하려면, 연산자 함수라는 특별한 함수를 사용해야 한다.
			operator+(argument-list)
			operator*(argument-list)
			operator[](argument-list)
			....
		: 예)
			district = sid + sara;
				피연산자들이 클래스에 속한다는 것을 컴파일러가 인식하면, 컴파일러는 그 연산자를 해당하는 연산자 함수로 대체한다.
				왼쪽 피연산자가 호출한 객체이다.
					district = sid.operator+(sara);
						: sid객체를 암시적으로 사용하고(메서드를 호출하는 객체이므로..), sara객체를 명시적으로 사용한다.(매개변수로 전달되었으므로...)						

	- 두 개 이상의 객체 더하기
		: t1, t2, t3, t4 가 객체라면...
			t4 = t1 + t2 + t3;	// 적법
				t4 = t1.operator+(t2 + t3);
					t4 = t1.operator+(t2.operator+(t3));

	- 오버로딩 제약
		1) 오버로딩된 연산자는, 적어도 하나의 피연산자가 사용자 정의 데이터형일 것을 요구한다.
		   이 제약은 표준 데이터형을 위해서 사사용되는 연산자들이 오버로딩 당하는것을 막아 준다.
		2) 오버로딩된 연산자를, 오리지널 연산자에 적용되는 문법 규칙을 위반하는 방식으로 사용할 수 없다.
			ex) 하나의 피연산자에게만 적용할 수 있도록 나머지 연산자(%)를 오버로딩할 수 없다.
		3) 연산자 우선순위를 변경할 수 없다.
		4) 연산자 기호를 새로 만들 수 없다.

		5) 다음과 같은 연산자들은 오버로딩 할 수 없다.
				sizeof				sizeof 연산자
				.					멤버 연산자
				.*					멤버 지시 포인터 연산자
				::					사용 범위 결정 연산자
				?;					조건 연산자
				typeid				PRTI 연산자
				const_cast			데이터형 변환 연산자
				dynamic_cast		데이터형 변환 연산자
				reinterpret_cast	데이터형 변환 연산자
				static_cast			데이터형 변환 연산자

		6) 다음과 같은 연산자들을 오버로딩하는 데 멤버 함수만 사용할 수 있다.
				=				대입 연산자
				()				함수 호출 연산자
				[]				배열 인덱스 연산자
				->				클래스 멤버 접근 포인터 연산자

*/


#include <iostream>
#include "mytime.h"

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::addMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::addHr(int h)
{
	hours += h;
}
void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::show() const
{
	std::cout << hours << "시간, " << minutes << "분";
}

/*
	- 지역 변수에 대한 참조 또는 다른 임시 객체에 대한 참조를 리턴하면 안 된다.
	  함수가 종료되고 지역 변수나 임시 객체가 사라질 때, 그러한 참조는 존재하지 않는
	  데이터에 대한 참조가 된다.
*/
Time Time::sum(const Time& t) const
{
	Time sum;
	sum.minutes = this->minutes + t.minutes;
	sum.hours = this->hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	
	return sum;
}



// 연산자 오버로딩
Time Time::operator+(const Time& t) const
{
	Time sum;
	sum.minutes = this->minutes + t.minutes;
	sum.hours = this->hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

Time Time::operator-(const Time& t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;

	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalMinutes = hours * mult * 60 + minutes * mult;
	result.hours = totalMinutes / 60;
	result.minutes = totalMinutes % 60;

	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << "시간, " << t.minutes << "분";
	return os;
}
/*
	- 프렌드
		1) 프렌드 함수
		2) 프렌드 클래스
		3) 프렌드 멤버함수

		: 함수를 어떤 클래스에 대해 프렌드로 만들면, 그 프렌드는 클래스의 멤버 함수들이 가지는 것과 동등한 접근 권한을 가진다.
		: 흔히, 어떤 클래스에 대해 이항 연산자를 오버로딩하면, 프렌드를 만들 필요성이 생긴다.
		: 위에서 정의한 곱셈 연산자와 같이 서로 다른 두 데이터형을 결합시킬 때 연산자를 사용하는 방법이 제한을 받는다.

		: 왼쪽 연산자가 호출한 피연산자 이다.
				A = B * 2.5;	==>		A = B.operator*(2.75);
				A = 2.5 * B;	==>		2.75는 객체가 아니기 때문에 컴파일러는 그 표현을 멤버함수 호출로 번역하지 못한다.

		: 이것을 해결하기 위해 멤버가 아닌 함수를 사용하는 것이다.
		  멤버가 아닌 함수는 객체를 사용하여 호출하지 않는다. 그 대신 멤버가 아닌 함수는, 객체를 포함하여 어떤 값을 명시적 매개변수로
		  사용하여 호출한다.
				Time operator*(double m, const Time& t);
				A = 2.75 * B;	==>		A = operator*(2.75, B);

		: 멤버가 아닌 오버로딩 연산자 함수를 사용할 때, 연산자 표현식의 왼쪽 피연산자는 그 연산자 함수의 첫 번째 매개변수에 대응하고,
		  오른쪽 피연산자는 두 번째 매개변수에 대응한다.
		  그러나 이렇게하면 멤버가 아닌 함수들은 클래스에 들어있는 private 데이터에 직접 접근할 수 없다는 문제가 발생한다.

	- 프렌드 생성하기
		step1)
			클래스 선선언에 원형을 넣는다.
				friend Time operator*(double m, const Time& t);
		step2)
			함수 정의를 작성한다.
				: 프렌드는 멤버 함수가 아니기 때문에, Time:: 제한자를 사용하지 않는다.
				: friend라는 키워드도 사용하지 않는다.
					Time operator*(double mult, const Time& t)
					{
						Time result;
						long totalMinutes = t.hours * mult * 60 + t.minutes * mult;
						result.hours = totalMinutes / 60;
						result.minutes = totalMinutes % 60;

						return result;						
					}
		step3)
			프렌드 함수를 호출한다.
				A = 2.75 * B;		==>		A = operator*(2.75, B);

		: 프렌드 함수는 클래스 선언 안에 선언되지만 멤버 함수가 아니다. 그러므로 멤버 연산자를 사용하여 호출되지 않는다.
		: 프렌드 함수는 그것이 비록 멤버 함수는 아니지만 멤버 함수와 동등한 접근 권한을 가진다.

		: 위 프렌드 함수는, 곱셈에서 어떤 값이 먼저 나오도록 정의를 다음과 같이 고침으로써 프렌드가 아닌 함수로 작성할 수 있다.
			Time operator*(double m, const Time& t)
			{
				return t * m;
			}
*/

/*
	- << 연산자의 오버로딩		
		: ostream 클래스는 << 연산자를 오버로딩하여 출력 도구로 변환시킨다.
		  cout이 ostream 객체이며, C++의 모든 기본 데이터형을 인식할 수 있다.
		  이것은 ostream 클래스 선언이, 기본 데이터형 각각에 대해 오버로딩된 operator<<() 정의를 하나씩 가지고 있기 때문이다.
		  그래서 cout이 Time 객체를 인식하도록 가리치는 방법은, ostream 클래스 선언에 새로운 연산자 함수의 정의를 추가하는 것이다.
		  그러나 이것보다 Time 클래스 선언을 사용하여 Time 클래스에게 cout을 사용하는 법을 가리치는 것이 훨씬 바람직하다.

		: trip이 Time 객체라고 가정
			cout << trip;

		: Time 클래스에게 cout을 사용하는 법을 가르치려면, 프렌드 함수를 사용해야 한다.
		  (왼쪽 피연산자가 operator<<()를 호출하는 객체이기 때문에...)

			  void operator<<(ostream& os, const Time& t)
			  {
				  os << t.hours << "시간, " << t.minutes << "분";
			  }
		  
		: operator<<()이 Time 객체의 private 멤버들에 직접 접근하기 때문에, 그 함수는 Time 클래스에 대해 프렌드여야 한다.
		: ostream 객체의 private 멤버들에 직접 접근할 필요가 없기 때문에, 그 함수가 ostream 클래스에 대해 프렌드일 필요가 없다.

		: cout << "여행 일시: " << trip << " (화요일)\n";
			이것이 가능하게 하기 위해 operator<<()가 ostream 객체를 리턴하도록 해야 한다.

				ostream& operator<<(ostream& os, const Time& t)
			    {
					os << t.hours << "시간, " << t.minutes << "분";
			    }		
*/

/*
	- 멤버 함수 vs 멤버가 아닌 함수
		
		Time operator+(const Time& t) const;					// 멤버 함수
		friend Time operator+(const Time& t1, const Time& t2);	// 멤버 아닌 함수

		: 멤버 함수 버전은 this 포인터를 통하여 암시적으로 하나가 전달되고, 다른 하나는 함수 매개변수로 명시적으로 전달된다.
		: 프렌드 함수 버전은 둘 다 매개변수로 전달된다.

	- 오버로딩 연산자 함수의 멤버가 아닌 버전은, 연산자가 요구하는 수만큼의 형식 매개변수를 요구한다.
	  같은 연산자 함수의 멤버 버전은, 하나의 피연산자가 암시적으로 호출한 객체로 전달되기 때문에, 매개변수를 하나 적게 요구한다.
*/