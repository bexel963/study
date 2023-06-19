/*
	- string 클래스는 string 헤더 파일을 통해 지원된다.
	- string.h, cstring 헤더파일은 string 클래스가 아니라 C스타일의 문자열을 처리하는 C라이브러리 문자열 함수들을 지원한다.
*/

/*
	- string 클래스의 생성자들..
		
		1. string(const char* s)
		2. string(size_type n, char c)				: 문자 c로 모두 초기화된 원소 n개의 string 객체를 생성한다.
		3. string(const string& str)
		4. string()									: 크기가 0인 디폴트 string 객체를 생성
		5. string(const char* s, size_type n)		: string 객체를 s가 지시하는 NBTS로 초기화하되, NBTS의 크기를 초과하더라도 n개의 문자까지 진행한다.
													  정수 매개변수는 복사할 문자들의 개수를 나타낸다.
		
		   template<class Iter>
		6. string(Iter begin, Iter end)
			: Iter는 포인터들의 일반화이다.

		7. string(const string& str, size_type pos, size_type n = npos)	: str에 있는 pos 위치에서 시작해서 str의 끝까지 가거나, n 문자를 사용하되 str의 끝을 넘어갈 수 없다.
																		  한 string 객체의 일부를 생성된 객체에 복사한다.
		8. string(string&& str) noexcept

		9. string(initializer_list<char> li)		: string 객체를 초기자 목록 li에 있는 문자로 초기화한다.		
													  string 클래스의 리스트 초기화를 가능하게 한다.
			string piano_man = { 'L', 'i', 's', 'z', 't' };
			string comp_lang = { 'L', 'i', 's', 'P' };
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	// 1
	string one("Lottery Winner!"); 
	cout << one << endl;

	// 2
	string two(20, '$');
	cout << two << endl;

	// 3
	string three(one);
	cout << three << endl;		

	one += " Oops!";
	cout << one << endl;		// Lottery Winner Oops!

	two = "Sorry! That was ";
	three[0] = 'P';				// Porry! That was

	// 4
	string four;
	four = two + three;	
	/*
		- 오버로딩 연산자 +를 사용하여 임시 string 객체를 생성한다.
		  이 임시 string객체는 오버로딩 연산자 = 를 사용하여 four 객체에 대입된다.
		  + 연산자는 다중으로 오버로딩되어 있기 때문에, 제2 피연산자의 위치에 string 객체, C스타일의 문자열, 하나의 char형 값이 올 수 있다.
	*/

	cout << four << endl;		// Sorry! That was Pottery Winner

	char alls[] = "All's well that ends well";

	// 5
	string five(alls, 20);
	/*
		- 정수 매개변수가 C스타일의 문자열 길이를 초과하더라도 요청한 개수만큼 무조건 복사를 진행한다.
		  따가서 20을 40으로 바꾸면 alls 뒤에 있는 메모리 내용을 문자 코드로 인식하고, 15개의 쓰레기 문자를 덧붙인다.
	*/
	cout << five << "!\n";		// All's well that ends!

	// 6
	string six(alls + 6, alls + 10);
	/*
		- alls+6, alls+10 은 둘 다 char* 형 포인터이기 때문에, 템플릿의 Iter가 char* 형으로 대체되어 사용된다.
	*/
	cout << six << ", ";					// well,
	string seven(&five[6], &five[10]);		
	/*
		- string seven(five + 6, five + 10)
			: 배열의 이름과는 달리, 객체의 이름은 그 객체의 주소로 간주되지 않는다.
			  즉, five가 포인터가 아니므로 five + 6 은 무의미한 것이 된다.
			  five[6]은 하나의 char형 값이다. 그래서 &five[6]은 주소이다. 따라서 그것을 이 생성자에 매개변수로 사용할 수 있다.
	*/
	cout << seven << "...\n";				// well...

	// 7
	string eight(four, 7, 16);
	cout << eight << "in motion!" << endl;	// That was Pottery in motion!
	
	return 0;
}

/*
	- =+ 연산자는 다중으로 오버로딩 되어 있으므로, string 객체나 단일 문자도 덧붙일 수 있다.
	- = 연산자도 오버로딩되어 string 객체, C스타일의 문자열, 하나의 단순한 char형 값을 string 객체에 대입할 수 있다.
	- [] 연산자가 오버로딩되어 배열 표기를 사용하여 string 객체에 들어 있는 개별적인 문자들에 접근할 수 있다.
*/

/*
	
*/