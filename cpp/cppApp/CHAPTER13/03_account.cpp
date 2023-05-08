#include <iostream>
#include "account.h"
using std::cout;
using std::endl;
using std::string;


/*
	- public 다형 상속을 구현하는 방법
		1) 기초 클래스 메서드를 파생 클래스에서 다시 정의
		2) 가상 메서드 사용

	- BrassPlus 클래스는 is-a 조건을 만족한다.
		: Brass 객체가 할 수 있는 모든 것을 BrassPlus 객체도 할 수 있다.
*/

// 포멧팅 관련
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass 메서드들

Brass::Brass(const string& s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}
void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "마이너스 입금은 허용되지 않았습니다.\n"
		<< "그래서 입금이 취소되었습니다.\n";
	else
		balance += amt;
}
double Brass::Balance() const
{
	return balance;
}

void Brass::Withdraw(double amt)
{
	// ###.## 형식으로 설정한다.
	format initialState = setFormat();
	precis prec = cout.precision(2);
	
	if (amt < 0)
		cout << "마이너스 인출은 허용되지 않습니다.\n"
		<< "그래서 인출이 취소되었습니다.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "인출을 요구한 금액 $ " << amt
		<< "가 현재 잔액을 초과합니다.\n"
		<< "그래서 인출이 취소되었습니다.\n";

	restore(initialState, prec);
}
void Brass :: ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "고객 이름: " << fullName << endl;
	cout << "계좌 번호: " << acctNum << endl;
	cout << "현재 잔액: " << balance << endl;

	restore(initialState, prec);	// 원래 형식 복원
}


BrassPlus::BrassPlus(const string& s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass& ba, double ml, double r) : Brass(ba)	// 암시적 복사 생성자를 사용한다.
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

// Withdraw()의 동작을 다시 정의한다.
//		고객이 현재 잔액 보다 많은 금액의 인출을 요구하면, 그 메서드는 당좌 대월을 준비한다.
void BrassPlus::Withdraw(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();		// Balance()는 파생 클래스에서 다시 정의하지 않았기 때문에 사용 범위 결정 연산자를 사용하지 않아도된다.
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "당좌 대월 금액: $" << advance << endl;
		cout << "당좌 대월 이자: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "당좌 대월 한도가 초과되어 거래가 취소되었습니다.\n";

	restore(initialState, prec);
}
// ViewAcct()의 동작을 다시 정의한다.
void BrassPlus::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();	
	/*	
		- 파생 클래스 메서드에서 기초 클래스 메서드를 호출하기 위해 사용 범위 결정 연산자를 사용하는것은 매우 중요하다.
		  여기서 사용 범위 결정 연산자를 생략하면 재귀호출이 되어버린다.
	*/

	cout << "당좌 대월 한도액: $" << maxLoan << endl;
	cout << "상환할 원리금: $" << owesBank << endl;
	cout.precision(3);
	cout << "당좌 대월 이자율: " << 100 * rate << "%\n";

	restore(initialState, prec);
}



format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}
/*
	- 업 캐스팅
		: 파생 클래스 참조나 포인터를 기초 클래스의 참조나 포인터로 변환하는 것을 업 캐스팅이라고 한다.
		  public 상속에서는 명시적인 데이터형 변환이 없어도 업캐스팅이 언제든지 허용된다. 이 관계는 is-a 관게를 나타내는 한 부분이다.
	      업 캐스팅은 전이된다.
	- 다운 캐스팅
		: 기초 클래스 포인터나 참조를 파생 클래스의 참조나 포인터로 변환하는 것을 다운 캐스팅이라 한다.
		  다운 캐스팅은 명시적인 데이터형 변환 없이는 허용되지 않는다. 이렇게 제한한 이유는, 일반적으로 is-a 관계는 대칭적이지 않기 때문이다.

	- 암시적 업캐스팅은 기초 클래스 포인터나 참조가 기초 클래스 객체나 파생 클래스 객체를 참조하는 것을 가능하게 만든다.
*/