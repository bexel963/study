#include <iostream>
using std::cout;
#include "stonewt.h"

/*
	- 표준 데이터형의 어떤 값을 표준 데이터형의 한 변수에 대입하는 구문을 작성하면, 두 데이터형이 서로 호환될 때, C++은 그 값의 데이터형을
	  대입받는 입장에 있는 변수와 동일한 데이터형으로 자동으로 변환한다.
			long count = 8;		// int형 -> long형
			double time = 11;	// int형 -> double형
			int side = 3.33;	// double형 -> int형
	  다향한 수치 데이터형들이 모두 기본적으로 동일한 수를 나타내고, C++가 데이터형 변환을 위한 내부 규칙을 적용하기 때문에, 이러한 대입 구문들은 바르게 동작한다.

	- C++은 호환되지 않는 데이터형은 자동으로 변환하지 않는데 이 때 강제 데이터형 변환을 이용할 수 있다.
			int* p = (int*)10;		// p에 주소 10을 저장한다.

	- 기본 데이터형이나 다른 어떤 클래스와 충분히 관련되어 있어, 서로 간에 변환할 수 있는 클래스를 정의할 수 있다.
	  그러한 경우, 자동 변환을 할 것인지 강제 변환을 할 것인지 사용자가 C++에게 지시할 수 있다.
*/

Stonewt::Stonewt(double lbs)	// 변환함수 (double형 값을 Stonewt 객체로 변환하는 템플릿)
{
	stone = (int)lbs / Lbs_per_stn;
	pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
	pounds = lbs;
}
/*
	- 하나의 매개변수를 사용하는 생성자는, 그 매개변수의 데이터형을 클래스형으로 변환하는 것을 정의한다.
	  그 생성자가 키워드 explicit로 제한된 경우에는, 명시적 데이터형 변환만 할 수 있다.

	- C++에서, 하나의 매개변수를 취하는 생성자는 그 매개변수 데이터형의 값을 클래스형으로 변환하는 설계도처럼 동작한다.
			Stonewt myCat;
			myCat = 19.6;		// Stonewt(double)을 사용하여 19.6을 Stonewt으로 변환한다.
							   Stonewt(double)을 사용하여 Stonewt 임시 객체를 생성하고 초기값으로 19.6을 사용한다.
							   그러고 나서 멤버별 대입으로 임시 객체의 내용을 myCat에 복사한다.
							   이 과정은 명시적 데이터형 변환이 필요 없이 자동으로 이루어지므로 암시적 데이터형 변환이라고 한다.

	- 하나의 매개변수만 사용할 수 있는 생성자만이 이와 같은 변환 함수로 동작한다.
	- 매개변수가 여러개라도 하나 빼고 전부 디폴트 값을 제공할 경우, 변환 함수의 역할을 한다.

	- 암시적 데이터형 변환의 부작용을 막기 위해 explicit 라는 새로운 키워드가 추가 되었다.
	  explicit 키워드는 앞의 예와 같은 암시적 데이터형 변환을 못하게 막는다. 그러나 명시적 데이터형 강제 변환은 여전히 허용된다.
			explicit Stonewt(double lbs);
			Stonewt myCat;
			myCat = 19.6;				// 암시적 데이터형 변환 -> Error
			myCat = Stonewt(19.6);		// 명시적 데이터형 변환 -> OK
			myCat = (Stonewt)19.6;		// 명시적 데이터형 변환 -> OK				

	- 컴파일러는 Stonewt(double) 함수를 다음과 같은 상황에서 사용한다.
		1) Stonewt 객체를 double형 값으로 초기화할 때
		2) Stonewt 객체에 double형 값을 대입할 때
		3) Stonewt형 매개변수를 기대하는 함수에 double형 값을 전달할 때
		4) Stonewt형 값을 리턴하도록 선언된 함수가 double형 값을 리턴하려고 시도할 때
		5) double형 대신 모호하지 않게 double형으로 변환할 수 있는 내장 데이터형을 사용할 때
				Stonewt jumbo(700);		// int형 -> double형 -> Stonewt(double) 사용
				jumbo = 7300;			// int형 -> double형 -> Stonewt(double) 사용	
		   만약, 그 클래스가 Stonewt(long) 생성자도 따로 정의해 두었다면 컴파일러는 이들 구문의 수행을 거부한다. (모호)
*/


Stonewt::Stonewt(int stn, double lbs)	// 변환함수 아님.
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() { }

void Stonewt::show_stn() const
{
	cout << stone << "스톤, " << pds_left << "파운드\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << "파운드\n";
}

std::ostream& operator<<(std::ostream& os, Stonewt s)
{
	cout << s.pounds << "파운드\n";

	return os;
}

// 변환 함수 정의
Stonewt::operator int() const
{
	return (int)(pounds + 0.5);
}
Stonewt::operator double() const
{
	return pounds;
}
/*
	- Stonewt wolfe(285.7);
	  double host = wolfe;		// 가능?

	- 생성자는 어떤 데이터형을 클래스형으로 변환하는 것만 허용한다.
	  이 과정을 반대로 하기 위해서는, 변환 함수라고 부르는 특별한 형태의 C++연산자 함수를 사용해야 한다.
	  변환 함수는 사용자 정의 강제 데이터형 변환이다. 따라서 일반적인 강제 데이터형 변환 처럼 사용하면 된다.
			double host = double(wolfe);		// 방법1
			doble thinker = (double)wolfe;		// 방법2
			double star = wolfe;				// 방법3 - 컴파일러가 변환 함수를 암시적으로 사용
	  방법3에서 오른쪽이 Stonewt형이고 왼쪽이 double형이라는 것을 인식한 컴파일러는, 사용자가 이 문제를 해결할 수 있는
	  변환 함수를 정의했는지 찾아보고, 만약 그러한 정의를 찾을 수 없다면, 컴파일러는 Stonewt형을 double형에 대입할 수 없다는
	  에러 메시지를 내보낸다.

	- 변환 함수 작성
			operator typeName();
	  : 변환 함수는 클래스의 메서드여야 한다.
	  : 변환 함수는 리턴형을 가지면 안 된다.
	  : 변환 함수는 매개변수를 가지면 안 된다. -> typeName 부분이 어떤 데이터형으로 변환할 것인지 알려주므로...

	- 모호성 
		ex1) cout << "Poppins: " << poppins << "파운드\n";  <- 프렌드 정의 안 되어있다고 가정... 
			int형으로 변환해야 하는지 double형으로 변환해야 하는지 모호하기 때문에 컴파일 에러..
		ex2) long gone = poppins;
			int형, double형 둘 다 long형 변수에 대입할 수 있어서 모호함..
		
		=> 명시적 변환을 사용하여 암시적 변환의 가능성을 없애는 것이 좋다.
				explicit operator int() const;
				explicit operator double() const;
		   이러한 선언이 있다면, 사용자는 명시적으로 호출한 경우에만 형변환을 사용할 수 있다.

	- 변환 함수 -> 비변환 함수
		Stonewt::operator int() { return int (pounds + 0.5); }
		int plb = (int)poppins;
		->
		int Stonewt::Stone_to_Int() { return int (pounds + 0.5); }
		int plb = poppins.Stone_to_Int();
			
*/

Stonewt Stonewt::operator+(const Stonewt& st) const
{
	double pds = pounds + st.pounds;
	Stonewt sum(pds);
	return sum;	
}
Stonewt operator-(const Stonewt& st1, const Stonewt& st2)
{
	double pds = st1.pounds - st2.pounds;
	Stonewt sum(pds);
	return sum;
}

/*
	- double형 값을 Stonewt형 값에 더하기
		1) friend operator+(const Stonewt&, const Stonewt&);
			: Stonewt(double) 생성자를 사용하여 double형 매개변수를 Stonewt형 매개변수로 변환한다.
		2) Stonewt operator+(double);
		3) friend Stonewt operator+(double, Stonewt&);

		total = jennySt + kennyD;	==> 2번 호출
		total = kennyD + jennySt;	==> 3번 호출
*/