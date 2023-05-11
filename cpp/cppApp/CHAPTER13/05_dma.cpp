#include "dma.h"
#include <cstring>

// baseDMA 메서드들
baseDMA::baseDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
baseDMA::~baseDMA()
{
	delete[] label;
}
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "상표: " << rs.label << std::endl;
	os << "등급: " << rs.rating << std::endl;
	return os;
}

// lacksDMA 메서드들
lacksDMA::lacksDMA(const char* c, const char* l, int r) : baseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "색상: " << ls.color << std::endl;
	return os;
}

// hasDMA 메서드들
hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char* s, const baseDMA& rs) : baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
/*
	- hasDMA 복사 생성자는 hasDMA 데이터에만 엑세스할 수 있으므로 데이터의 baseDMA 공유를 처리하려면 baseDMA 복사 생성자를 호출해야 한다.
	  여기서 멤버 초기자 리스트가 baseDMA 생성자에 hasDMA 참조를 전달하는 것에 주목해야 한다.
	  hasDMA 참조형을 매개변수로 사용하는 baseDMA 생성자는 없다. 그러나 그것은 있을 필요가 없다.
	  왜냐하면 baseDMA 복사 생성자가 baseDMA 참조형의 매개변수를 사용하고 있고, 기초 클래스 참조가 파생형을 참조할 수 있기 때문이다.
	  그러므로 그 baseDMA 복사 생성자가, hasDMA 매개변수의 baseDMA 부분을 사용하여, 새 객체의 baseDMA 부분을 생성한다.
*/

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);		// 기초 클래스 부분을 복사한다.
	delete[] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}
/*
	- hasDMA도 동적 메모리 대입을 사용하기 때문에, hasDMA도 명시적인 대입 연산자를 필요로 한다.
	  그것은 hasDMA 메서드이기 때문에, 그것만이 hasDMA 데이터에 직접적으로 접근할 수 있다.
	  그럼에도 불구하고, 파생 클래스의 명시적 대입 연산자는, 상속받은 baseDMA 기초 클래스 객체를 위한 대입을 처리할 수 있어야 한다.
	  기초 클래스 대입 연산자를 명시적으로 호출함으로써 이것을 처리할 수 있다.	  
		
				baseDMA::operator=(hs);

	  연산자 표기 대신 함수 표기를 사용함으로써, 사용 범위 결정 연산자를 사용할 수 있도록 허용한다.
	  *this = hs; 와 같이 하면 컴파일러는 hasDMA::operator=()를 사용하게 되고, 이것은 재귀 호출을 일으킨다.
*/

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;	// operator<<(ostream&, const baseDMA&)을 위해 강제 데이터형 변환
	os << "스타일: " << hs.style << std::endl;
	return os;
}
/*
	- 위 함수는 hasDMA 클래스의 프렌드이기 때문에, style 멤버에 접근할 수 있다.
	  그러나 이 함는 baseDMA 클래스에 대해서는 프렌드가 아니기 때문에 rabel과 rating에 접근할 수 없다.
	  이 문제에 대한 해결책은 baseDMA 클래스에 대해 프렌드인 operator<<() 를 사용하는 것이다.
	  그러나 프렌드는 멤버 함수가 아니기 때문에, 어느 함수를 사용할 것인지를 나타내기 위해 사용 범위 결정 연산자를 사용할 수 없다.
	  이 문제에 대한 해결책은, 강제 데이터형 변환을 사용하여 원형 일치를 통해 올바른 함수를 선택할 수 있도록 하는 것이다.
*/

/*
	- 정리
		: 기초 클래스와 파생 클래스가 둘 다 동적 메모리 대입, 파생 클래스 파괴자, 복사 생성자, 대입 연산자를 사용할 때
		  이들은 모두 기초 클래스 성분을 처리하기 위해 그들의 기초 클래스 대응물을 사용해야 한다.
		  이 공통된 요구 사항은 서로 다른 세 가지 방법으로 이루어진다.

		  1) 파괴자
			: 그것은 자동으로 이루어진다.
		  2) 생성자
			: 그것은 멤버 초기자 리스트에서 기초 클래스 복사 생성자를 호출함으로써 이루어지거나, 디폴트 생성자가 자동으로 호출된다.
		  3) 대입 연산자
			: 그것은 기초 클래스 대입 연산자의 명시적 호출에서 사용 범위 결정 연산자를 사용함으로써 이루어진다.
*/