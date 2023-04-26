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
	virtual void Withdraw(double amt);
	double Balance() const;
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
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};

#endif
