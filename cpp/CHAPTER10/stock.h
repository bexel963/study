#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private:
	std::string company;
	long shares;			// 주식 수
	double share_val;		// 주가
	double total_val;		// 총 가치
	
	// 인라인 함수: 클래스 선언 안에 정의를 가지고 있는 모든 함수는 자동으로 인라인 함수가 된다.
	void set_tot() {
		total_val = shares * share_val;
	}
public:
	void acquire(const std::string&, long, double);
	void buy(long, double);
	void sell(long, double);
	void update(double);
	void show();
};




#endif
