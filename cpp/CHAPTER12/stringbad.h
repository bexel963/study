#include <iostream>

#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
private:
	char* str;		// 이 클래스 선언이 문자열 자체를 위해 기억공간을 대입하지 않는다는 뜻이다.
	int len;
	static int num_strings;		// 객체의 수
public:
	StringBad(const char*);
	StringBad();
	~StringBad();

	StringBad(const StringBad&);				// 복사 생성자
	StringBad& operator=(const StringBad&);		// 대입 연산자

	friend std::ostream& operator<<(std::ostream&, const StringBad&);
};

#endif
