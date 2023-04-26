#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	Time sum(const Time& t) const;
	void show() const;


	// 연산자 오버로딩
	Time operator+(const Time& t) const;
	Time operator-(const Time& t) const;
	Time operator*(double n) const;

	// 프렌드 함수
	friend Time operator*(double m, const Time& t) { return t * m; }	// 인라인 정의
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif
