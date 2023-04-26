#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};	// 스톤당 파운드 수
	int stone;			// 정수부(스톤)
	double pds_left;	// 소수부(파운드)
	double pounds;		// 파운드로 나타낸 전체 무게
public:
	Stonewt(double);		// double형 파운드를 위한 생성자
	Stonewt(int, double);	// stone, lbs를 위한 생성자
	Stonewt();
	~Stonewt();
	
	void show_lbs() const;
	void show_stn() const;

	// 변환 함수들...
	operator int() const;
	operator double() const;
};

#endif
