/*
	- Vector 클래스
		: 벡터는 크기와 방향을 함께 가지는 물리량이다.
		: 벡터는 하나의 값으로 나타낼 수 없으므로, 벡터를 나타내는 클래스를 정의하는 것이 필요하다
		: 벡터를 표시하는 방법은 극좌표 형식, 직각좌표 형식 두 가지이다.
*/

#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

// 이름 공간의 개방성을 사용하여, VECTOR라는 이름 공간에 그 메서드 정의들을 추가한다.
namespace VECTOR
{
	// 1 라디안 내의 각도 (1 라디안에 대한 degree 값을 계산)
	const double Rad_to_deg = 45.0 / atan(1.0);

	// private 메서드들
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}
	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	// form이 r이면 직각 좌표로부터 벡터를 구한다.
	// form이 p이면 극 좌표로부터 벡터를 구한다.
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
			cout << "그래서 벡터를 0으로 설정하였다.\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Vector()에 전달된 제3의 매개변수가 잘못되었다.\n";
			cout << "그래서 벡터를 0으로 설정하였다.\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{

	}
	
	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rec_mode()
	{
		mode = RECT;
	}

	// 멤버 함수 연산자 오버로딩
	Vector Vector::operator+(const Vector& b) const
	{
		// 생성자는 두 개의 새로운 값들을 이용하여 이름이 없는 새로운 객체를 생성한다.
		// 그리고 나서 그 객체의 복사본을 리턴한다.
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	// 프렌드 메서드 구현
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		// operator<<()는 프렌드 기능이지 클래스 범위의 일부가 아니기 때문에, RECT 대신 Vector::RECT를 사용해야 한다.
		// 그러나 VECTOR 이름 공간 안에 존재하기 때문에 완전한 전체 이름 VECTOR::Vector::RECT를 사용할 필요는 없다.
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		else
			os << "Vector 객체의 모드 지정이 틀렸습니다.\n";

		return os;
	}
}

/*
	: 클래스는 어떤 것이 지니고 있는 서로 다른 측면과 서로 다른 표기 형식을 하나의 객체 안에 넣는 것을 허용한다.
		1) 서로 다른 표기 형식을 하나의 객체에 저장할 수 있다.
		2) 하나의 표기 형식으로 값을 대입하면, 다른 표기 형식에도 값이 자동으로 대입되는 클래스 함수를 만들 수 있다.
	: 클래스는 이러한 변환을 내부적으로 처리함으로써, 어떤 수량을 다룰 때 표기 형식이 아니라 본질적인 의미에만 집중하면 되므로 편리하다.
*/
