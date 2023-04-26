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

// ����: �����ְ� ���� �� �������� ������ �Ϻ� �Ǵ� ���θ� ������ �� �ִ� ����.
// (����)���: ���� ������ �ŷ��ڰ� ������ �Ⱓ�� �ݾ� �ѵ� ������ ���� ������ �ܾ� �̻� ��ǥ�� �������� ���� ������ �װ��� �����ϴ� ��. �Ǵ� �� �ʰ� ���޺�.
// ������: ���ݰ� ���ڰ� ���Ͽ��� �ݾ�
class BrassPlus : public Brass
{
private:
	double maxLoan;		// ��� �ѵ�
	double rate;		// ��� ����
	double owesBank;	// ��ȯ�� ������
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
