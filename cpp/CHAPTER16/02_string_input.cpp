/*
	- C스타일의 문자열에 대해서는 세 가지 입력 옵션을 사용할 수 있다.
		
		char info[100];

		1) cin >> info;					// 한 단어를 읽는다.
		2) cin.getline(info, 100);		// 한 행을 읽되, \n은 내버린다.
		3) cin.get(info, 100);			// 한 행을 읽되, \n을 큐에 남겨둔다.

	- string 객체의 경우에는 두 가지 옵션을 사용할 수 있다.

		string stuff;

		1) cin >> stuff;				// 한 단어를 읽는다.
		2) getline(cin, stuff);			// 한 행을 읽되, \n은 내버린다.

	- getline()의 두 버전은, 입력을 구분하는 용도로 어느 문자를 사용할 것인지를 지정하는 선택적 매개변수를 허용한다.

		cin.getline(info, 100, ':');		// :까지 읽고, :은 내버린다.
		getline(cin, stuff, ':');			// :까지 읽고, :은 내버린다.

		: ':'이 구분 문자로 지정되면, 개행 문자는 그냥 일반 문자가 된다.

	- 동작상의 주요한 차이는, string 버전들은 입력 문자들을 담을 수 있도록 타깃 string 객체의 크기를 자동으로 조절한다는 것이다.

		char fname[10];
		string lname;

		cin >> fname;				// 입력이 9개 문자보다 크면 문제가 생길 수 있다.
		cin >> lname;				// 매우 긴 워드를 읽을 수 있다.
		cin.getline(fname, 10);		// 입력이 잘릴 수도 있다.
		getline(cin, fname);		// 잘림 없음

		: 자동 크기 조절 기능은, getline()의 string 버전이, 읽을 입력 문자들의 개수를 제한하는 수치 매개변수를 생략하는 것을 허용한다.

	- 설계상의 차이는, C스타일 문자열 입력 버전은 istream 클래스의 메서드들인 반면, string 버전들은 독립형 함수들이라는 것이다.
	  이것이 cin이 C스타일 문자열 입력을 위한 호출 객체이고, string 객체 입력을 위한 함수 매개변수인 이유이다.
	  이것은 >> 형식에도 그대로 적용된다.

		cin.operator>>(fname);		// istream 클래스 메서드
		operator>>(cin, lname);		// 일반 함수
*/

/*
	- 문자열 입력 제한..

		1) 상수 string::npos로 나타내는 문자열의 최대 허용 크기 -> 일반적으로, unsigned int의 최대 크기
		2) 프로그램이 사용할 수 있는 메모리의 크기

	- string 클래스를 위한 getline()는 다음 세 가지 중 어느 하나가 일어나 때까지, 입력으로부터 문자들을 읽어 그들을 하나의 문자열로 저장한다.

		1) 파일의 끝을 만났을 때
				: 입력 스트림의 eofbit가 설정된다.
				  이것은 fail()과 eof()가 true를 리턴한다는 것을 의미한다.
		2) 구분 문자(디폴트는 \n)에 도달했을 때
				: 구분 문자는 입력 스트림으로 부터 제거되고 저장되지 않는다.
		3) 가능한 최대 문자 수(string::npos와, 대입에 사용할 수 있는 메모리의 바이트 수 중 더 적은 것)를 읽었을 때
				: 입력 스트림의 failbit가 설정된다.
				  이것은 fail()이 true를 리턴한다는 것을 의미한다.

		: 입력 스트림 객체는 그 스트림의 에러 상태를 추적하는 계산 시스템을 가지고 있다.
				eofbit 설정  -> 파일 끝 인식 등록
				failbit 설정 -> 입력 에러 인식 등록
				badbit 설정  -> 하드웨이 실패와 같은, 인식할 수 없는 실패 등록
				goodbit 설정 -> 만사가 OK라는 것을 나타낸다.

		: string 클래스를 위한 operator>>() 는 구분 문자까지 읽고 버리는 대신 화이트스페이스 문자까지 읽고 그 문자를 입력 큐에 남겨둔다.
		  화이트스페이스 문자는 빈칸, 개행, 탭 문자, isspace()가 true를 리턴하는 모든 문자들이다.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
	using namespace std;
	ifstream fin;
	fin.open("C:\\Users\\LIM\\Desktop\\std\\cpp\\cppApp\\CHAPTER16\\Debug\\tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "프로그램을 종료합니다.\n";
	fin.close();

	return 0;
}