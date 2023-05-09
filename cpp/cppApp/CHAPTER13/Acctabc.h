#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};

	const std::string& FullName() const { return fullName; }
	long AcctNum() const { return acctNum; }
	Formatting SetFormat() const;
	void Restore(Formatting& f) const;

public:
	AcctABC(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	double Balance() const { return balance; };
	virtual void Withdraw(double amt) = 0;	// 순수 가상함수
	virtual void ViewAcct() const = 0;		// 순수 가상함수
	virtual ~AcctABC() { }
};

class Brass : public AcctABC
{
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) { }
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() { }
};

class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }

	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);	
};

#endif

/*
	- 추상화 기초 클래스
		
		: is-a 규칙을 적용하는 것이 생각처럼 쉽지 않을 때가 있다.
		  		 		
					class Ellipse			// 타원 클래스
					{
					private:
						double x;
						double y;
						double a;			// 반장경
						double b;			// 단장경
						double angle;		// 각도 단위의 방위각
					public:
						...
						void Move(int x, int y) { x = nx; y = ny; }
						virtual double Area() const { return 3.14159 * a * b; }
						virtual void Rotate(double nang) { angle += nang; }
						virtual void Scale(double sa, double sb) { a *= sa; b += sb; }
						...
					}

					class Circle : public Ellipse	
					{
						...
					}

		  원이 타원에 속한다고 할지라도 이와 같은 파생은 어색하다. 
		  타원과 달리 원의 크기와 모양을 서술하는 데에는 반장경과 반단경이 필요 없고, 반지름 하나만 있으면 된다.
	      또 원 클래스에는 angle 매개변수와 Rotate()는 전혀 의미가 없다.
	      상속을 사용하지 않고 Circle 클래스를 정의할 수도 있지만 그렇게 하면, Circle과 Ellipse는 공통적인 것이 많은데, 그것들을 따로따로 정의하게 된다.
	   
	      다른 해결책으로는 Circle 클래스와 Ellipse 클래스로부터 공통적인 것들을 추출하여, 그것들을 추상화 기초 클래스(ABC)에 넣을 수 있다.
		  그러고 나서, Circle과 Ellipse 클래스를 둘 다 ABC로부터 파생시키는 것이다.
		  그렇게 하면 기초 클래스 포인터들의 배열을 사용하여, Ellipse 객체와 Circle 객체들이 혼합된 것을 관리할 수 있다.

		  위의 경우에, 두 클래스에 공통적인 것들은 x, y, Move(), Area() 이다.
		  ABC는 필요한 데이터 멤버를 가지고 있지 않기 때문에, Area()를 ABC에서 구현할 수 없다.
		  C++는 구현되지 않는 이러한 함수를 위해 순수 가상 함수라는 것을 사용한다.
		  순수 가상 함수는 함수 선언 뒤에 =0 을 가진다.
					
					class BaseEllipse
					{
					private:
						double x;
						double y;
						...
					public:
						BaseEllipse(double d1 = 0, double d2 = 0) : x(d1), y(d2) { }
						virtual ~BaseEllipse() { }
						void Move(int n1, int n2) { x = n1; y = ny; }
						
						virtual double Area() const = 0;	// 순수 가상 함수
					}

		  클래스 선언에 순수 가상 함수가 들어 있으면, 그 클래스의 객체를 생성할 수 없다.
		  그 이유는 순수 가상 함수를 가지고 있는 클래스는 기초 클래스의 역할을 하기 위해서만 존재하기 때문이다.
		  어떤 클래스가 진짜 추상화 기초 클래스가 되려면, 적어도 하나의 순수 가상 함수를 가져야 한다.
		  가상 함수를 순수 가상 함수로 만드는 것은 원형에 있는 =0 이다.
		  순수 가상 함수가 정의를 가지는 것도 허용된다.

		  즉, 원형에 =0 가 있으면, 그 클래스가 추상화 기초 클래스이며, 그 클래스가 함수를 반드시 정의할 필요는 없다는 것을 나타낸다.
		  이 클래스들을 사용하는 프로그램은 BaseEllipse 포인터들의 배열을 사용하여 Circle 객체와 Ellipse 객체를 관리할 수 있다.

*/
