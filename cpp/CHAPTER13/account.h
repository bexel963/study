#ifndef BRASS_H_
#define BRASS_H_
#include <string>

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	double Balance() const;

	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() { }
};

// 당좌: 예금주가 원할 때 언제든지 예금의 일부 또는 전부를 인출할 수 있는 예금.
// (당좌)대월: 당좌 예금의 거래자가 일정한 기간과 금액 한도 내에서 당좌 예금의 잔액 이상 수표를 발행했을 때에 은행이 그것을 지급하는 일. 또는 그 초과 지급분.
// 원리금: 원금과 이자가 합하여진 금액
class BrassPlus : public Brass
{
private:
	double maxLoan;		// 대월 한도
	double rate;		// 대월 이자
	double owesBank;	// 상환할 원리금
public:
	BrassPlus(const std::string& s = "Nullbody", long accountNum = -1, double bal = 0.0, double mL = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double mL = 500, double r = 0.11125);

	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }

	virtual void Withdraw(double amt);	
	virtual void ViewAcct() const;
};

#endif

/*
	- 소스 코드에 있는 함수 호출을 특정 블록에 있는 함수 코드를 실행하라는 뜻으로 해석하는 것을 "함수 이름을 결합한다." 라고 한다.
	  C언어 에서는 각각의 함수가 별개의 함수에 해당하기 때문에, 이 작업이 간단하지만 C++에서는 함수 오버로딩 때문에 이 작업이 복잡하다.
	  컴파일러는 함수 이름뿐만 아니라 함수 매개변수들도 조사해야 한다.
	- 컴파일하는 동안 일어나는 결합을 정적 결합 또는 초기 결합이라 한다.
	- 가상 함수의 경우에는 프로그램을 실행할 때 사용자가 객체를 결정하기 때문에, 컴파일하는 동안에는 그 객체가 어떤 종류인지 알 수 없다.
	  그러므로 컴파일러는, 프로그램을 실행할 때 올바른 가상 메서드가 선택되도록 하는 코드를 만들어 내야 한다.
	  이 작업을 동적 결합 또는 말기 결합이라 한다.
*/

/*
	- 가상 메서드
		: 메서드가 객체에 의해 호출되지 않고, 참조나 포인터에 의해 호출되었을 때 어느 메서드를 사용할 것인지를 결정한다.
		: virtual 키워드를 사용하지 않을 경우에, 프로그램은 참조형이나 포인터형에 기초하여 메서드를 선택한다.
			virtual 키워드를 사용했을 경우에, 프로그램은 참조나 포인터에 의해 지시되는 객체형에 기초하여 메서드를 선택한다.

				Brass dom("Dominic Banker", 11224, 4183.45);
				BrassPlus dot("Dorothy Banker", 12118, 2592.00);
				
				<ViewAcct()가 가상이 아닐 경우>	-> 참조형에 기초하여 ViewAcct() 가 선택된다.
				Brass& b1 = dom;
				Brass& b2 = dot;
				b1.ViewAcct();			// Brass::ViewAcct() 사용
				b2.ViewAcct();			// Brass::ViewAcct() 사용
				: 컴파일러는 가상이 아닌 함수에 대해서 정적 결합을 사용한다.

				<ViewAcct()가 가상일 경우>		-> 객체형에 기초하여 ViewAcct() 가 선택된다.
				Brass& b1 = dom;
				Brass& b2 = dot;
				b1.ViewAcct();			// Brass::ViewAcct() 사용
				b2.ViewAcct();			// BrassPlus::ViewAcct() 사용
				: 컴파일러는 가상 함수들에 대해서 동적 결합을 사용한다.

		: 파생 클래스에서 다시 정의되는 메서드들은, 기초 클래스에서 가상으로 선언하는 것이 일반적인 관행이다.
		  어떤 메서드가 기초 클래스에서 가상으로 선언되었을 때, 그것은 파생 클래스에서 자동으로 가상 메서드가 된다.
		  그러나 파생 클래스 선언에도 virtual 키워드를 사용함으로써, 어떤 함수들이 가상인지 표시해두는 것이 좋다.
		: virtual 키워드는 선언에서만 사용된다.
*/

/*
	- 정적 결합이 디폴트인 이유
		1) 효율성
			: 프로그램이 무언가를 실행 시간에 결정할 수 있도록 하려면, 기초 클래스 포인터나 참조가 지시하는 객체의 종류가 무엇인지 추적하는 방법이 필요하다.
			  그러려면 가외의 처리 부담이 생긴다.
			  정적 결합이 효율적이기 때문에 C++은 그것이 디폴트로 되어 있다.
			  그러므로 가상 함수는 프로그램 설계상 꼭 필요한 경우에만 사용해야 한다.
		2) 개념 모델
			: 기초 클래스에서 어떤 함수를 가상이 아닌 일반 함수로 정의하면 이 함수가 다시 정의되면 안 된다는 의도를 드러낸다.
			  이것은, 다시 정의될 것으로 기대되는 메서드들에 대해서만 가상 레이블을 사용할 필요가 있다는 것을 의미한다.	 
*/

/*
	- 가상 함수 사용 시 부담
		1) 각 객체의 크기가 주소 하나(가상 함수 테이블을 가리키는)를 저장하는 데 필요한 양만큼 커진다.
		2) 각각의 클래스에 대해, 컴파일러는 가상 함수들의 주소로 이루어진 하나의 테이블(배열)을 만든다.
		3) 각각의 함수 호출에 대해, 실행할 함수의 주소를 얻기 위해 테이블에 접근하는 가외의 단계가 더 필요하다.
*/

/*
	- 가상 함수 관련 사항
		1) 생성자는 가상으로 선언할 수 없다.
		2) 클래스가 기초 클래스로 사용된다면, 파괴자는 가상으로 선언해야 한다.
				Employee* pe = new Singer;
				delete pe;	// ~Employee() 일까 ~Singer() 일까?
		   디폴트인 정적 결합이 적용된다면, delete구문은 ~Employee() 파괴자를 호출한다.
		   그러면 이 코드는 Singer 객체에 새로 추가된 클래스 멤버들이 지시하는 메모리는 해제하지 않고,
		   Singer객체의 Employee 성분들이 지시하는 메모리만 해제한다.
		   일반적으로, 파괴자가 필요 없는 기초 클래스라 하더라도 가상 파괴자를 제공해야 한다.
		3) 프렌드는 가상 함수가 될 수 없다.  프렌드는 클래스의 멤버가 아니기 때문....

		4) 어떤 함수를 파새 클래스에서 다시 정의하면, 동일한 함수 시그내처를 가지고 있는 기초 클래스 선언만 가리는 것이 아니라,
		   매개변수 시그내처와는 상관없는 같은 이름을 가진 모든 기초 클래스 메서드들을 가린다.
			-> 규칙1) 상속된 메서드들 재정의할 경우에는 오리지널 원형과 정확히 일치시킬 필요가 있다.
			   예외) 리턴형이 기초 클래스에 대한 참조나 포인터인 경우, 파생 클래스에 대한 참조나 포인터로 대체될 수 있다. (리턴형의 공변)  
			-> 규칙2) 기초 클래스 함수 선언이 오버로딩되어 있다면, 파생 클래스에서 모든 기초 클래스 버전들을 재정의해야 한다.
*/

/*
	- protected
		: 파생 클래스의 멤버들은 기초 클래스의 protected 멤버에는 직접 접근할 수 있지만, 기초 클래스의 private 멤버에는 직접 접근할 수 없다.
*/