#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT, POL};
	private:
		double x;	// 수평 성분
		double y;	// 수직 성분
		double mag;	// 벡터의 길이
		double ang;	// 방위(도)로 표시되는 벡터의 방향
		Mode mode;

		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double m2, Mode form = RECT);
		~Vector();

		// 인라인 함수
		double xVal() const { return x; }
		double yVal() const { return y; }
		double magVal() const { return mag; }
		double angVal() const { return ang; }
		void polar_mode();		// 모드를 'p'로 설정
		void rec_mode();		// 모드를 'r'로 설정

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}

#endif