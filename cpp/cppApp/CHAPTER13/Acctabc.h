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
	virtual void Withdraw(double amt) = 0;	// ���� �����Լ�
	virtual void ViewAcct() const = 0;		// ���� �����Լ�
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
	- �߻�ȭ ���� Ŭ����
		
		: is-a ��Ģ�� �����ϴ� ���� ����ó�� ���� ���� ���� �ִ�.
		  		 		
					class Ellipse			// Ÿ�� Ŭ����
					{
					private:
						double x;
						double y;
						double a;			// �����
						double b;			// �����
						double angle;		// ���� ������ ������
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

		  ���� Ÿ���� ���Ѵٰ� ������ �̿� ���� �Ļ��� ����ϴ�. 
		  Ÿ���� �޸� ���� ũ��� ����� �����ϴ� ������ ������ �ݴܰ��� �ʿ� ����, ������ �ϳ��� ������ �ȴ�.
	      �� �� Ŭ�������� angle �Ű������� Rotate()�� ���� �ǹ̰� ����.
	      ����� ������� �ʰ� Circle Ŭ������ ������ ���� ������ �׷��� �ϸ�, Circle�� Ellipse�� �������� ���� ������, �װ͵��� ���ε��� �����ϰ� �ȴ�.
	   
	      �ٸ� �ذ�å���δ� Circle Ŭ������ Ellipse Ŭ�����κ��� �������� �͵��� �����Ͽ�, �װ͵��� �߻�ȭ ���� Ŭ����(ABC)�� ���� �� �ִ�.
		  �׷��� ����, Circle�� Ellipse Ŭ������ �� �� ABC�κ��� �Ļ���Ű�� ���̴�.
		  �׷��� �ϸ� ���� Ŭ���� �����͵��� �迭�� ����Ͽ�, Ellipse ��ü�� Circle ��ü���� ȥ�յ� ���� ������ �� �ִ�.

		  ���� ��쿡, �� Ŭ������ �������� �͵��� x, y, Move(), Area() �̴�.
		  ABC�� �ʿ��� ������ ����� ������ ���� �ʱ� ������, Area()�� ABC���� ������ �� ����.
		  C++�� �������� �ʴ� �̷��� �Լ��� ���� ���� ���� �Լ���� ���� ����Ѵ�.
		  ���� ���� �Լ��� �Լ� ���� �ڿ� =0 �� ������.
					
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
						
						virtual double Area() const = 0;	// ���� ���� �Լ�
					}

		  Ŭ���� ���� ���� ���� �Լ��� ��� ������, �� Ŭ������ ��ü�� ������ �� ����.
		  �� ������ ���� ���� �Լ��� ������ �ִ� Ŭ������ ���� Ŭ������ ������ �ϱ� ���ؼ��� �����ϱ� �����̴�.
		  � Ŭ������ ��¥ �߻�ȭ ���� Ŭ������ �Ƿ���, ��� �ϳ��� ���� ���� �Լ��� ������ �Ѵ�.
		  ���� �Լ��� ���� ���� �Լ��� ����� ���� ������ �ִ� =0 �̴�.
		  ���� ���� �Լ��� ���Ǹ� ������ �͵� ���ȴ�.

		  ��, ������ =0 �� ������, �� Ŭ������ �߻�ȭ ���� Ŭ�����̸�, �� Ŭ������ �Լ��� �ݵ�� ������ �ʿ�� ���ٴ� ���� ��Ÿ����.
		  �� Ŭ�������� ����ϴ� ���α׷��� BaseEllipse �����͵��� �迭�� ����Ͽ� Circle ��ü�� Ellipse ��ü�� ������ �� �ִ�.

*/
