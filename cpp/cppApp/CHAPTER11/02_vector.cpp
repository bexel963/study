/*
	- Vector Ŭ����
		: ���ʹ� ũ��� ������ �Բ� ������ �������̴�.
		: ���ʹ� �ϳ��� ������ ��Ÿ�� �� �����Ƿ�, ���͸� ��Ÿ���� Ŭ������ �����ϴ� ���� �ʿ��ϴ�
		: ���͸� ǥ���ϴ� ����� ����ǥ ����, ������ǥ ���� �� �����̴�.
*/

#include <cmath>
#include "vect.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

// �̸� ������ ���漺�� ����Ͽ�, VECTOR��� �̸� ������ �� �޼��� ���ǵ��� �߰��Ѵ�.
namespace VECTOR
{
	// 1 ���� ���� ���� (1 ���ȿ� ���� degree ���� ���)
	const double Rad_to_deg = 45.0 / atan(1.0);

	// private �޼����
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

	// form�� r�̸� ���� ��ǥ�κ��� ���͸� ���Ѵ�.
	// form�� p�̸� �� ��ǥ�κ��� ���͸� ���Ѵ�.
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
			cout << "Vector()�� ���޵� ��3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
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
			cout << "Vector()�� ���޵� ��3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
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

	// ��� �Լ� ������ �����ε�
	Vector Vector::operator+(const Vector& b) const
	{
		// �����ڴ� �� ���� ���ο� ������ �̿��Ͽ� �̸��� ���� ���ο� ��ü�� �����Ѵ�.
		// �׸��� ���� �� ��ü�� ���纻�� �����Ѵ�.
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

	// ������ �޼��� ����
	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}
	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		// operator<<()�� ������ ������� Ŭ���� ������ �Ϻΰ� �ƴϱ� ������, RECT ��� Vector::RECT�� ����ؾ� �Ѵ�.
		// �׷��� VECTOR �̸� ���� �ȿ� �����ϱ� ������ ������ ��ü �̸� VECTOR::Vector::RECT�� ����� �ʿ�� ����.
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
			os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		else
			os << "Vector ��ü�� ��� ������ Ʋ�Ƚ��ϴ�.\n";

		return os;
	}
}

/*
	: Ŭ������ � ���� ���ϰ� �ִ� ���� �ٸ� ����� ���� �ٸ� ǥ�� ������ �ϳ��� ��ü �ȿ� �ִ� ���� ����Ѵ�.
		1) ���� �ٸ� ǥ�� ������ �ϳ��� ��ü�� ������ �� �ִ�.
		2) �ϳ��� ǥ�� �������� ���� �����ϸ�, �ٸ� ǥ�� ���Ŀ��� ���� �ڵ����� ���ԵǴ� Ŭ���� �Լ��� ���� �� �ִ�.
	: Ŭ������ �̷��� ��ȯ�� ���������� ó�������ν�, � ������ �ٷ� �� ǥ�� ������ �ƴ϶� �������� �ǹ̿��� �����ϸ� �ǹǷ� ���ϴ�.
*/
