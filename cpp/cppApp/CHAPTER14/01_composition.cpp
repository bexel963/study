#include "composition.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public 메서드들
double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}
/*
	- 내포된 객체의 인터페이스 사용
		: 내포된 객체의 인터페이스는 public이 아니다. 그러나 그것들을 Student클래스의 메서드 안에서 사용할 수 있다.
*/
const string& Student::Name() const
{
	return name;
}
double& Student::operator[](int i)
{
	return scores[i];
}
double Student::operator[](int i) const
{
	return scores[i];
}

// private 메서드
ostream& Student::arr_out(ostream& os) const
{
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
				os << endl;
		}
		if (i % 5 != 0)
			os << endl;
	}
	else
		os << "빈 배열 ";

	return os;
}
/*
	- arr_out()은 출력을 위해 <<의 valarray 구현을 사용할 수 있지만, 이 클래스에는 그것이 구현되어있지 않다.
	  그러므로, Student 클래스는 이 과업을 처리하는 헬퍼 메서드를 정의한다.
	  이와 같은 헬퍼를 사용하는 것은, 흩어진 지엽적인 사항들을 한데 모으고, 프렌드 함수의 코딩을 더 간결하게 만든다.
	  또한 헬퍼 함수는 그 밖의 사용자 레벨 출력 함수들을 위한 빌딩 블록 역할을 할 수도 있다.
*/

// 프렌드
// operator>>()의 string 버전을 사용한다.
istream& operator>>(istream& is, Student& stu)
{
	is >> stu.name;
	return is;
}

// string friend getline(ostream&, const string&) 을 사용한다.
istream& getline(istream& is, Student& stu)
{
	getline(is, stu.name);
	return is;
}

// operator<<()의 string 버전을 사용한다.
ostream& operator<<(ostream& os, const Student& stu)
{
	os << stu.name << " 학생의 성적표:\n";
	stu.arr_out(os);	// scores를 위해 private 메서드 사용
	return os;
}

