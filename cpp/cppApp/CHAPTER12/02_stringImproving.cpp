#include <cstring>
#include "stringImproving.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

String::String()
{
	len = 4;

	// str = "디폴트 문자열";		-> X - new[] 가 없음
	// str = new char;			-> X - [] 가 없음
	// str = 0;					-> O
	// str = nullptr;			-> O
	str = new char[1];
	str[0] = '\0';
	// 위 두 줄은 str = 0; 으로 대체할 수 있다. (str를 널 포인터로 설정한다.)
	// c++98 버전에서 0은 숫자 값 0 과 null pointer의 두 가지 의미가 있었다.
	// c++11 부터는 str = nullptr; 로 표기한다. (nullptr은 키워드)

	num_strings++;
}
/*
	- str=new char; == str=new char[1];
		: 두 형식 모두 같은 크기의 메모리를 대입한다. 다만, 첫 번째 형식은 이 클래스의 파괴자와 호환되지 않는다.
		  delete [] 를 사용하는 것은, new [] 를 사용하여 초기화시킨 포인터 및 널 포인터와 호환된다.
		: delete [] 를 다른 방법으로 초기화시킨 포인터와 함께 사용했을 때의 결과는 어떻게 될지 알 수 없다.

	- str = new char;
		: new를 적용하지만, 정확한 크기의 메모리를 요청하지 못한다.
		  그러므로 new는 영문자 하나를 넣을 수 있는 크기의 블록을 리턴한다. 
		  그 위치에 긴 문자열을 복사하려고 시도하면 메모리 문제가 발생할 것이다.
*/

// 변환 함수 (매개변수가 하나인 생성자..)
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

// 복사 생성자
String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;		// 모든 생성자가 이것과 어울려야 한다.
}

// String을 String에 대입한다.
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
/*
	- 보통의 문자열을 String 객체에 대입 
			String name;
			char temp[40];
			cin.getline(temp, 40);

			name = temp;
	  : (과정1)
		위 코드에서 프로그램은 String(const char*) 생성자를 사용하여, temp에 저장된 문자열의 복사본이 들어있는,
	    String 임시 객체를 생성한다.
	    (하나의 매개변수를 사용하는 생성자는 변환 함수의 역할을 수행한다. - 11장)
		그러고 나서 프로그램은 String& String::operator=(const String&) 함수를 사용하여, 그 임시 객체의 정보를
		name 객체에 복사한다.
		마지막으로 프로그램은 ~String() 파괴자를 호출하여 그 임시 객체를 파괴한다.
*/

// C 스타일의 문자열을 String에 대입한다.
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
/*
	- 과정1을 좀 더 효율적으로 만드는 가장 쉬운 방법은, 대입 연산자를 오버로딩하여 보통의 문자열을 직접 다룰 수 있게 하는 것이다.
*/

char& String::operator[](int i)
{
	return str[i];
}
/*
	- [] 기호는 하나의 연산자이다. operator[]() 라는 메서드를 사용하여 이 연산자를 오버로딩할 수 있다.
			char city[40] = "Amsterdam";
			cout << city[0] << endl;	// 문자 'A'를 출력
	  : city는 첫 번째 피연산자이고, 0은 두 번째 피연산자이다.

			String opera("The Magic Flute");
	  : opera[4] 라는 표현이 사용되면, C++은 String::operator[](int i) 같은 메서드 정의를 찾는다.
		일치하는 원형을 컴파일러가 찾았다면 opera[4] 라는 표현은 opera.operator[](4) 함수로 대체된다.
		즉, opera 객체가 그 메서드를 호출하고 리턴값은 opera.str[4] 이다. 'M'
		그 public 메서드가 private 데이터에 개별적으로 접근한 결과이다.

	  : 리턴형을 char& 형으로 선언했기 때문에, 하나의 특정 원소에 값을 대입하는 것이 가능한다.
			String means("might");
			means[0] = 'r';			==> means.operator[](0) = 'r';  ==> means.str[0] = 'r';
*/

const char& String::operator[](int i) const
{
	return str[i];
}
/*
	- C++는 const 함수 시그내처와 const가 아닌 함수 시그내처를 구별한다
	  그래서 const String객체가 사용할 수 있는 operator[]()의 제2의 버전을 제공할 수 있다.
	  두 정의를 모두 제공한다면, 보통의 String 객체에는 읽기쓰기 접근이 모두 허용되고, const String 데이터에는 읽기 접근만 허용된다.
		String text("Once upon a time");
		const String answer("futile");
		cout << text[1];	// operator[]()의 const가 아닌 버전 사용
		cout << answer[1];	// operator[]()의 const 버전 사용
		cin >> text[1];		// operator[]()의 const가 아닌 버전 사용
		cin >> answer[1];	// 컴파일 에러!!
*/

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
/*
	- strcpm()는 첫 번째 매개변수가 두 번째 매개변수보다 앞에 오면 음수를 리턴한다.
	- 내장된 < 연산자가 이미 bool형의 값을 리턴하고 있기 때문에 바로 return 뒤에 코드를 넣어도 된다.
	- 비교 함수들을 프렌드로 만들면, String객체와 보통의 C스타일의 문자열을 비교할 수 있다.
		if("love" == answer)
		=> if(operator==("love", answer))
		=> if(operator==(String("love"), answer))	// 컴파일러가 생성자 중 어느 하나를 사용하여 이렇게 변환한다.
*/

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}
/*
	- 여기서 리턴형은 ostream이 아니라 ostream&이 되어야 한다.
	  ostream 리턴형을 사용하면, ostream 복사 생성자의 호출을 요구할 것이다.
	  ostream 클래스는 public 복사생성자를 만들지 않는다.
	  메서드나 함수가 ostream 클래스와 같이 public 복사 생성자가 없는 클래스의 객체를 리턴한다면, 객체에 대한 참조를 리턴해야 한다.
	  다행이도, cout에 대한 참조를 리턴하는 것은, 호출하는 함수의 사용 범위안에 이미 cout이 들어있기 때문에
	  문제를 일으키지 않는다. (vector.cpp line-175)
*/

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get()!='\n')
		continue;

	return is;
}

int String::HowMany()
{
	return num_strings;
}
/*
	- static 클래스 멤버 함수
		: 멤버 함수를 static으로 선언하는 것이 가능하다.
		  키워드 static은 함수 정의가 아니라 함수 선언에 나타나야 한다.
		: static 멤버 함수는 객체에 의해 호출될 필요가 없다. static 멤버 함수는 this 포인터도 갖지 않는다.
		: static 멤버 함수는 어떤 특정 객체와도 결합하지 않기 때문에, 사용할 수 있는 데이터 멤버는 static 데이터 멤버밖에 없다.
*/

/*
	- NULL, 0, nullptr
		: 널 포인터는 0 또는 NULL로 타나낼 수 있다. NULL은 여러개의 헤더 파일에 0으로 정의되어있는 기호 상수이다.
		  C 프로그래머들은 흔히 그 값이 포인터 값이라는 사실을 잊지 않기 위해 0 대신 NULL을 사용한다.
		  그들은 또 널 문자를 나타낼 때에도 0 대신 '\0'을 사용한다. (그 값이 문자라는 사실을 잊지 않기 위해서...)
		: NULL 대신에 보다 간단한 0을 사용하기 위해 nulptr 키워드를 대안으로 제시한다.
*/



/*
	- 생성자에 new를 사용할 때 주의사항
		1) 생성자에서 new를 사용하여 포인터 멤버를 초기화한다면, 파괴자에 반드시 delete를 사용해야 한다.
		2) new와 delete의 사용은 서로 어울려야 한다. new는 delete와 짝을 이루고, new[]는 delete[]와 짝을 이루어야 한다.
		3) 생성자가 여러 개일 경우, 모두 대괄호를 사용하든지 아니면 모두 대괄호 없이 사용하든지, 모든 생성자가 같은 방법으로
		   new를 사용해야 한다.
		4) 파괴자는 하나밖에 없으므로, 모든 생성자가 그 파괴자와 어울려야 한다.
		   그러나 하나의 생성자에서 new를 사용하여 포인터를 초기화하고, 다른 생성자에서 널 포인터(NULL 또는 0)로 초기화하는 것은
		   허용이 된다.
		   그 이유는 대괄호가 있건 없건 delete 연산자를 널 포인터에 적용할 수 있기 때문이다.
*/