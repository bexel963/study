#include <cstring>
#include "stringbad.h"

/*
	- 동적메모리
		: 사용할 메모리의 크기를 컴파일할 때 결정하지 않고 프로그램을 실행할 때 상황에 따라 융통성 있게 결정한다.
*/
using std::cout;

int StringBad::num_strings = 0;
/*
	- static 멤버 변수를 클래스 선언 안에서 초기화할 수 없다.
	  선언은 단지 메모리를 어떻게 대입할지에 대한 서술일 뿐, 실제로 메모리를 대입하지 않기 때문이다.
	  그 서술을 사용하여 실제로 객체를 생성해야만 메모리를 대입하고 초기화한다.
	  그러므로 클래스 선언 바깥에서 별개의 구문을 사용하여 그 static 멤버를 독립적으로 초기화한다.
	  그렇게 하는 이유는 static 클래스 멤버가 객체의 일부분으로 저장되는 것이 아니라 별도로 저장되기 때문이다.
	  초기화 구문에는 사용 범위 결정 연산자를 사용하지만, static 키워드는 사용하지 않는다.

	- 예외적으로 static 데이터 멤버가 정수형 또는 열거형의 const인 경우에, static 데이터 멤버를 클래스 선언
	  안에 넣고 초기화할 수 있다. (10장 참고..)
*/
StringBad::StringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 객체 생성\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	std:: strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 디폴트 객체 생성\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" 객체 파괴, ";
	--num_strings;
	cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}
/*
	- 파괴자는 객체가 정의된 블록의 실행을 마칠 때 호출되고, 내부 블록이 없을 시 main()의 실행을 마친 후 호출된다.
*/

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}


// 복사 생성자
StringBad::StringBad(const StringBad& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	cout << num_strings << ": \"" << str << "\" 객체생성\n";
}
// 대입 연산자
StringBad& StringBad::operator=(const StringBad& st)
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
	- StringBad sailor = sports; == StringBad sailor = StringBad(sports);
		: sports는 StringBad형이기 때문에, 원형은 StirngBad(const String&); 이다.
		: 프로그램에서 하나의 객체를 다른 객체로 초기화하면, 컴파일러는 복사 생성자라고 부르는
		  생성자를 자동으로 발생시킨다.
		: 복사 생성자는 객체의 사본을 만든다.
		: 이 프로그램에서 자동으로 발생되는 복사 생성자는, static 변수인 num_strings를 갱신하는 것에 대해 알지 못한다.

	- C++이 자동으로 발생시키는 특별 멤버 함수
		1) 생성자를 전혀 정의하지 않았을 경우		-> 디폴트 생성자
		2) 디폴트 파괴자를 정의하지 않았을 경우	-> 디폴트 파괴자
		3) 복사 생성자를 정의하지 않았을 경우		-> 복사 생성자
		4) 대입 연산자를 정의하지 않았을 경우		-> 대입 연산자
		5) 주소 연산자를 정의하지 않았을 경우		-> 주소 연산자
*/

/*
	1) 디폴트 생성자
		Klunk::Klunk() { }	// 암시적 디폴트 생성자
		Klunk lunk;			// 암지석 디폴트 생성자 호출

		: 디폴트 생성자는 lunk를 보통의 자동 변수처럼 만든다. 즉, 초기에 그 값이 알려지지 않는다.
		: 명시적으로 초기화하지 않는 객체를 만들고 싶거나, 객체들의 배열을 만들고 싶다면, 디폴트 생성자를
		  명시적으로 정의해야 한다.
		: 매개변수를 사용하는 생성자들도, 모든 매개변수들에 디폴트 값을 제공한다면, 디폴트 생성자가 될 수 있다.
		: 디폴트 생성자는 하나만 가질 수 있다. 즉, 다음과 같이 할 수 없다.
			Klunk() { klunk_ct = 0 }			// 디폴트 생성자1
			Klunk(int n=0) { klunk_ct = n; }	// 디폴트 생성자2 (모호함..)
*/

/*
	2) 복사 생성자
		: 복사 생성자는 어떤 객체를 새로 생성되는 객체에 복사하는 데 사용된다.
		  즉, 복사 생성자는 일반적인 대입에 사용되는 것이 아니라 값 전달에 의한 함수 매개변수 전달을 포함한 초기화 작업에 사용된다.
		: 원형
			Class_name(const Class_name&);
			StringBad(const StringBad&);
		: 복사 생성자는 새로운 객체가 생성되어 같은 종류의 기존 객체로 초기화될 때마다 호출된다.
		  motto가 StringBad의 객체라고 가정하면..
				StringBad ditto(motto);							// StringBad(const StringBad&)를 호출
				StringBad ditto = motto;						// StringBad(const StringBad&)를 호출
				StringBad ditto = StringBad(motto);				// StringBad(const StringBad&)를 호출
				StringBad* pStringBad = new StringBad(motto);	// StringBad(const StringBad&)를 호출
		: 함수가 객체를 값으로 전달하거나 (callme2() 처럼..), 함수가 객체를 리턴할 때 복사 생성자가 사용된다.
		  예를 들어, 3개의 Vector 객체를 더할 때 중간 결과를 보관하기 위해 컴파일러는 Vector 임시객체를 생성할 것이다.
		  => 객체를 값으로 전달하면 복사 생성자가 호출되기 때문에, 참조로 전달하는 것이 더 좋다. (메모리 절약)

		: 디폴트 복사 생성자는 static 멤버를 제외한 멤버들을 멤버별로 복사한다. (얕은 복사)

		: 복사 생성자, 대입 연산자 주석 처리 후 테스트~~
			StringBad sailor = sports; 구문의 효과는 sailor.str = sports.str 이다.
			이것은 문자열 자체를 복사하지 않고 문자열을 지시하는 포인터를 복사한다.
			이것은 단순히 문자열을 출력하기 위해 그 포인터를 사용할 때는 문제가 되지 않지만,
			파괴자가 호출될 때에는 문제를 일으킨다.
			StringBad 파괴자는 str 포인터가 지시하는 메모리를 해제하는데 그 메모리를 지시하는 포인터가 두 개이기 때문에
			해체된 메모리를 한 번 더 해체하게 된다.
			이미 삭제한 데이터를 다시 삭제하려고 시도하는 것은 어떻게 될지 그 결과를 알 수 없다.
			메모리의 내용이 엉뚱한 것으로 바뀔 수도 있고, 프로그램이 먹통이 될 수도 있다.
		 => 복사 생성자를 필수적으로 정의(깊은 복사)해야 하는 이유는, 일부 클래스 멤버들이 데이터 자체가 아니라,
			new에 의해 초기화되는 데이터를 지시하는 포인터들이기 때문이다.
*/

/*
	3) 대입 연산자
		: ANSI C가 구조체 대입을 허용하는 것처럼, C++도 클래스 객체 대입을 허용한다.
		  어떤 클래스에 대해 대입 연산자를 자동으로 오버로딩함으로써 그것을 허용한다.
		: 원형
			Class_name& Class_name::operator=(const Class_name&);
			StringBad& operator=(const StringBad&);
		: 대입 연산자는 클래스 멤버 함수에 의해서만 오버로딩될 수 있는 몇 가지 연산자 중의 하나이다.
		: 오버로딩 대입 연산자는 하나의 객체를 기존의 다른 객체에 대입할 때 사용된다.
			StringBad knot;
			knot = headline1;

		: StringBad metoo = knot;
			metoo는 knot의 값으로 초기화되면서 새로 할당되는 객체이다. 따라서 복사 생성자가 사용된다.
			C++은 이 구문을 두 단계로 처리한다. 복사 생성자를 사용하여 임시 객체를 먼저 생성한 후, 대임을 사용하여 그 값들을 그 새로운 객체에 복사한다.

		: 복사 생성자와 마찬가지로, 대입 연산자의 암시적 구현은 멤버별 복사를 수행한다. static 데이터 멤버들은 영향을 받지 않는다.
		
		: 잘못된 디폴트 대입 연산자 때문에 발생하는 문제의 해결책은, 깊은 복사를 하는 대입 연산자 정의를 사용자가 직접 정의 하는것이다.
			1) 타깃 객체가, 이전에 대입된 데이터를 참조하고 있을 수도 있으므로, 그 함수는 delete[]를 사용하여 이전의 의무를 해제해 주어야 한다.
			2) 그 함수는 어떤 객체를 자기 자신에게 대입하지 못하게 막아야 한다.
			3) 그 함수는 호출한 객체에 대한 참조를 리턴한다.
				-> 객체를 리턴함으로써 그 함수는, 내장 데이터형들에 대해 보통의 대입을 사슬처럼 연결하는 것을 똑같이 에뮬레이트할 수 있다.
				   s0, s1, s2가 StringBad 객체라면, s0 = s1 = s2 와 같이 작성할 수 있다.
				   == s0.operator=(s1.operator=(s2));
*/