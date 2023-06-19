#include "privateInheritance.h"

using namespace std;

double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

const string& Student::Name() const
{
	return (const string&)*this;	// Student 객체 안에 들어 있는, 상속된 string 객체에 대한 참조를 리턴한다.
}
/*
	- 기초 클래스 객체에 접근하기
		: 컴포지션 버전은 name 멤버인 string 객체를 리턴하게 함으로써 Name() 메서드를 구현한다.
		  그러나 private 상속 버전에서는, string 객체가 이름을 가지지 않기 때문에 데이터형 변환을 사용하여 접근한다.
		: this 포인터는 호출하는 객체를 지시한다.
*/

double& Student::operator[] (int i)
{
	return ArrayDb::operator[](i);	// ArrayDb::operator[]() 사용
}
double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

// private 메서드
ostream& Student::arr_out(ostream& os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i % 5 == 4)
				os << endl;
		}
	}
	else
		os << " 빈 배열";

	return os;
}

// 프렌드
// operator>>() 의 string 버전을 사용한다.
istream& operator>>(istream& is, Student& stu)
{
	is >> (string&)stu;
	return is;
}

// string 프렌드 getline(ostream&, const string&)을 사용한다.
istream& getline(istream& is, Student& stu)
{
	getline(is, (string&)stu);
	return is;
}

// operator<<()의 string 버전을 사용한다
ostream& operator<<(ostream& os, const Student& stu)
{
	os << "Scores for " << (const string&)stu << ":\n";	// 형변환을 생력하면 프렌드 함수의 원형과 일치하여 재귀 호출을 일이키게 된다.
	stu.arr_out(os);
	return os;
}
/*
	- 클래스 이름을 사용하여 함수 이름을 명시적으로 지정하는 테크닉은, 프렌드 함수가 클래스에 속하지 않기 때문에 적용되지 않는다.
      그러나 기초 클래스로 변환하는 명시적인 데이터형 변환을 사용하여 정확한 함수를 호출할 수 있다.

*/