#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
private:
	// 최신 컴파일러들은 enum의 대체 구문인 static const int Lbs_per_stn = 14; 를 사용한다.
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

	friend std::ostream& operator<<(std::ostream&, Stonewt);

	// 변환과 프렌드
	Stonewt operator+(const Stonewt&) const;
	friend Stonewt operator-(const Stonewt&, const Stonewt&);
};

#endif
