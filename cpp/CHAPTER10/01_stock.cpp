#include <iostream>
#include "stock.h"

void Stock::acquire(const std::string& co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "주식 수는 음수가 될 수 없으므로, " << company << " shares를 0으로 설정합니다.\n";
		shares = 0;
	}
	else
		shares = n;
	
	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "매입 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "매도 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다.\n";
	}
	else if (num > shares)
	{
		cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, 거래가 취소되었습니다.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::ios_base;

	// < set format to #.### >
	// 
	// 원본 플래그 저장
	// fmtflags는 ios_base 클래스에서 정의된 데이터 형으로 std 이름 공간에서 정의 된다.
	// orig는 모든 플래그를 보유하고 있으며, 리셋 구문은 그 정보를 사용하여 고정 소수점 표기와 과학적 기수법을 위한 플래그를 포함하고 있는 floatfield에 있는 정보를 리셋한다.
	// setf(...)는 플래그를 고정 소수점 표기를 사용하기 위해 cout 개체 안에 플래그를 세팅한다.
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);

	// 정확성을 위해 이전 값을 저장한다.
	std::streamsize prec = cout.precision(3);

	std::cout << "회사명: " << company
		<< "주식 수: " << shares << '\n'
		<< "주가: $" << share_val;

	// < set format to #.## >
	cout.precision(2);
	std::cout << "주식 총 가치: $" << total_val << '\n';

	// < restore original format >
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
