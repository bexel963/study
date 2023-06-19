#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stringImproving.h"

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	String name;
	cout << "안녕하십니까? 성합이 어떻게 되십니까?\n";
	cin >> name;
	
	cout << name << " 씨! 간단한 우리 속담 " << ArSize << "개만 입력해 주십시오(끝내려면 Enter):\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;

	if (total > 0)
	{
		cout << "(다음과 같은 속담들을 입력하셨습니다.)\n";
		for (i = 0; i < total; i++)
			cout << sayings[i] << "\n";

		String* shortest = &sayings[0];	// 첫 번째 객체로 초기화한다.
		String* first = &sayings[0];
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())	// 메서드에 접근
				shortest = &sayings[i];
			if (sayings[i] < *first)	// 객체 얻기
				first = &sayings[i];	// 주소 대입.
		}
		cout << "가장 짧은 속담:\n" << *shortest << endl;
		cout << "사전순으로 가장 앞에 나오는 속담:\n" << *first << endl;

		srand(time(0));
		int choice = rand() % total;

		String* favorite = new String(sayings[choice]);
		/*
			- 초기화값 sayings[choice]이 복사 생성자의 매개변수 데이터형(const String&)과 일치하므로,
			  위 구문은 복사 생성자를 호출한다.
		*/

		cout << "내가 가장 좋아하는 속담:\n" << *favorite << endl;
		delete favorite; // 단일 객체이기 때문에 대괄호 없는 delete를 사용한다.
	}
	else
		cout << "알고 있는 속담이 하나도 없어요?\n";
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

/*
	- new에 의한 객체 초기화
	  Class_name* pClass = new Class_name(value);
		: 다음과 같은 생성자를 호출한다.
			Class_name(Type_name);
		: 다음과 같은 사소한 변환도 이루어질 수 있다.
			Class_name(const Type_name&);
		: int를 double로 변환하는 것과 같은, 원형 일치에 의해 호출되는 변환은 모호성이 없는 한 이루어진다.
		: 다음과 같은 형식의 초기화는 디폴트 생성자를 호출한다.
			Class_name* ptr = new Class_name;
*/

/*
	- 포인터와 객체
		: 클래스 객체를 지시하는 포인터를 선언한다.
				String* glamour;

		: 포인터를 기존의 객체로 초기화한다.
				String* first = &saying[0];

		: 디폴트 클래스 생성자를 사용하여 포인터를 초기화한다.
				String* gleep = new String;

		: String(const char*) 생성자를 사용하여 포인터를 초기화한다.
				String* glop = new String("my my my");

		: String(const String&) 생성자를 사용하여 포인터를 초기화한다.
				String* favorite = new String(sayings[Choice]);

		: 포인터를 사용하여 클래스 메서드에 접근하기위해 -> 연산자를 사용한다..
				if(sayings[i].length() < shortest->length())

		: 포인터를 사용하여 객체를 얻기위해 내용 참조 연산자(*)를 사용한다.
				if(sayings[i] < *first)
*/