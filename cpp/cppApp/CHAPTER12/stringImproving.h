#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;	// cin 입력 한계
public:
	String(const char*);			// 생성자
	String();						// 디폴트 생성자
	String(const String&);			// 복사 생성자
	~String();
	int length() const
	{
		return len;
	}
	
	// 오버로딩 연산자 메서드
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int);
	const char& operator[](int) const;
	
	// 오버로딩 연산자 프렌드
	friend bool operator < (const String&, const String&);
	friend bool operator > (const String&, const String&);
	friend bool operator == (const String&, const String&);
	friend ostream& operator << (ostream&, const String&);
	friend istream& operator >> (istream&, String&);

	// static 함수
	static int HowMany();
};

#endif
