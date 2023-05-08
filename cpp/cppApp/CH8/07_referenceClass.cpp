#include <iostream>
#include <string>

using namespace std;

string version1(const string&, const string&);
const string& version2(string&, const string&);		// 부수 효과
const string& version3(string&, const string&);		// 나쁜 설계

int main()
{
	string input;
	string copy;
	string result;

	cout << "문자열을 입력하시오: ";
	getline(cin, input);
	copy = input;
	cout << "입력한 문자열: " << input << endl << endl;

	result = version1(input, "**");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
	cout << endl;

	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
	cout << endl;
	
	cout << "원래 문자열 재설정\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
	cout << endl;
	
	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;

	return temp;
}
const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;

	return s1;
}
const string& version3(string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;

	return temp;	// 지역 변수에 대한 참조를 리턴하므로 안전하지 않다.
}

/*
	- 일반적으로 C++는, 클래스 객체를 함수에 전달할 때 참조를 사용한다.
*/

/*
	- const 참조 형식 매개변수의 특성으로 실매개변수의 데이터형이 참조 매개변수의 데이터형과 일치하지 않지만, 참조 데이터형으로 변환될 수 있으면,
	  프로그램은 올바른 데이터형의 임시 변수를 만들고, 변환된 값으로 그것을 초기화하고, 임시 변수를 참조에 전달한다.
*/

/*
	- 포인터 vs 참조

		: 함수가 전달된 데이터를 변경하지 않고 사용만 하는 경우
			데이터 객체가 기본 데이터형이나 작은 구조체면 값으로 전달한다.
			데이터 객체가 배열이라면 포인터가 유일한 선택이므로 포인터를 사용한다.
			데이터 객체가 덩치 큰 구조체라면 const포인터나 const참조를 사용한다.
			데이터 객체가 클래스 객체라면 const참조를 사용한다. => 클래스 객체 매개변수의 전달은 참조로 전달하는 것이 표준이다.

		: 함수가 호출 함수의 데이터를 변경하는 경우
			데이터 객체가 기본 데이터형이면 포인터를 사용한다.
			데이터 객체가 배열이면 유일한 선택은 포인터를 사용하는 것이다.
			데이터 객체가 구조체이면 참조 또는 포인터를 사용한다.
			데이터 객체가 클래스 객체이면 참조를 사용한다.
*/