/*
	- 프로그램이 하나의 문자를 문자열에 추가할 때, 이미 사용중인 이웃 메모리를 침범할 수도 있기 때문에,
	  문자열을 제자리에서 마냥 자라게 할 수 없다.
	  그래서 새로운 블록을 대입하고, 이전의 내용을 새로운 위치로 복사해야 한다.
	  이 일을 하는 것은 많이 비효율적일 수 있다. 그래서 많은 C++ 시스템들은 실제 문자열보다 훨씬 큰 메모리 블록을
	  대입하여 문자열이 자랄 수 있는 공간을 제공한다.
	  그러고 나서, 그 문자열이 마침내 그 크기를 초과하게 되면, 프로그램은 그 크기의 두 배인 새로운 블록을 대입하여
	  연속적인 크기 조절 없이 문자열이 자랄 수 있게 더 많은 공간을 제공한다.
	  capacity()는 현재 블록의 크기를 리턴하고, reserve()는 그 블록을 위한 최소 크기를 사용자가 요청하게 한다.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	
	cout << "크기:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	
	cout << "용량:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;

	empty.reserve(50);
	cout << "empty.reserve(50) 이후 용량: " << empty.capacity() << endl;

	return 0;
}

/*
	- c_str() 메서드
		: string 객체 -> C스타일의 문자열
		
		: open()는 C스타일 문자열 매개변수를 요구한다.
			
			string filename;
			cout << .파일명을 입력하시오: ";
			cin >> filename;
			ofstream fout;

			fout.open(filename.c_str());		
*/

/*
	- string 클래스는 템플릿 클래스에 기초하고 있다.

			template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
			basic_string
			{
				...
			}

		: 이 클래스에는 다음과 같은 네 가지 typedef이 들어 있다.

			typedef basic_string<char> string;
			typedef basic_string<wchar_t> wstring;
			typedef basic_string<char16_t> u16string;
			typedef basic_string<char32_t> u32string;

			=> 이는 char 뿐만 아니라, wchar_t형, wchar16_t형, wchar32_t형에 기초하는 문자열오 사용할 수 있게 허용한다.
*/