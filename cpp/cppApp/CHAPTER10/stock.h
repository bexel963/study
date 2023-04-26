#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock
{
private:
	std::string company;
	long shares;			// �ֽ� ��
	double share_val;		// �ְ�
	double total_val;		// �� ��ġ
	
	// �ζ��� �Լ�: Ŭ���� ���� �ȿ� ���Ǹ� ������ �ִ� ��� �Լ��� �ڵ����� �ζ��� �Լ��� �ȴ�.
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
