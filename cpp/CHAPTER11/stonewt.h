#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
private:
	// �ֽ� �����Ϸ����� enum�� ��ü ������ static const int Lbs_per_stn = 14; �� ����Ѵ�.
	enum {Lbs_per_stn = 14};	// ����� �Ŀ�� ��
	int stone;			// ������(����)
	double pds_left;	// �Ҽ���(�Ŀ��)
	double pounds;		// �Ŀ��� ��Ÿ�� ��ü ����
public:
	Stonewt(double);		// double�� �Ŀ�带 ���� ������
	Stonewt(int, double);	// stone, lbs�� ���� ������
	Stonewt();
	~Stonewt();
	
	void show_lbs() const;
	void show_stn() const;

	// ��ȯ �Լ���...
	operator int() const;
	operator double() const;

	friend std::ostream& operator<<(std::ostream&, Stonewt);

	// ��ȯ�� ������
	Stonewt operator+(const Stonewt&) const;
	friend Stonewt operator-(const Stonewt&, const Stonewt&);
};

#endif
