#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
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
};

#endif
