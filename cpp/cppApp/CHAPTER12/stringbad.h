#include <iostream>

#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
private:
	char* str;
	int len;
	static int num_strings;
public:
	StringBad(const char*);
	StringBad();
	~StringBad();

	StringBad(const StringBad&);				// 복사 생성자
	StringBad& operator=(const StringBad&);		// 대입 연산자

	friend std::ostream& operator<<(std::ostream&, const StringBad&);
};

#endif
