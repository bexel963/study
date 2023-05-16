#include <iostream>
#include <string>
#include <cctype>
#include "templateClass.h"
using std::cin;
using std::cout;

int main()
{
	Stack<std::string> st;
	/*
		- 템플릿의 구체화를 요청하려면, 템플릿 클래스형의 객체를 선언하되, 포괄적인 데이터형 이름을 구체적인 데이터형으로 대체해야 한다.
		- 함수 매개변수의 데이터형을 사용하여, 컴파일러가 어떤 종류의 함수를 생성할 것인지 결정하는 일반적인 함수 템플릿과는 다르게
		  클래스 템플릿에서는 사용하려는 데이터형을 명시적으로 제공해야 한다.
					template<class T>
					void simple(T t) { cout << t << '\n'; }
					...
					simple(2);			// void simple(int) 생성
					simple("two");		// void simple(char*) 생성
	*/

	char ch;
	std::string po;
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
		<< "종료하려면 Q를 입력하십시오.\n";

	while (cin >> ch && std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "추가할 주문서의 번호를 입력하십시오: ";
			cin >> po;
			if (st.isfull())
				cout << "스택이 가득 차 있습니다.\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "스택이 비어있습니다.\n";
			else
			{
				st.pop(po);
				cout << "#" << po << " 주문서를 처리했습니다.\n";
			}
			break;
		}
		cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n"
			<< "종료하려면 Q를 입력하십시오.\n";
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}


/*
	- 포인터를 클래스 템플릿의 데이터형으로 사용할 수 있을까?
	- 포인터들의 스택을 잘못 사용하는 경우
			
			버전1)
				Stack<char*> st;
				string po;	-> char* po;

	  -> cin >> po; 에서 error난다.
			: 포인터의 단순한 생성은 입력 문자열들의 저장 공간을 생성하지 않기 때문에, 이와 같은 접근은 즉시 실패한다.
			  프로그램이 컴파일은 되겠지만, cin이 입력을 부적절한 장소에 저장하려고 시도한 후 먹통이 될 것이다.

			버전2)
				Stack<char*> st;				
				string po;	-> char po[40];

	  -> 이것은 입력 문자열을 저장하기 위한 공간을 대입하고, po는 char*형이므로 스택에 넣을 수 있다.
	     그러나 배열은 pop() 메서드에서 약속한 가정과 기본적으로 불화를 일으킨다.
			: 참조 변수 item은 배열 이름이 아니라 어떤 종류의 Lvalue를 참조해야 한다.
			: 이 코드는 item에 대입할 수 있다고 가정한다. item이 어떤 배열을 참조할 수 있을지라도, 배열 이름에는 대입할 수 없다.

			버전3)
				Stack<char*> st;
				char* po = new char[40];

	  -> 이것은 입력 문자열을 저장하기 위한 공간을 대입하는 데다가, po가 변수이므로 pop()과 불화를 일이키지 않는다.
	     그러나 po 변수는 하나밖에 없고, 그것은 항상 같은 메모리 위치를 지시한다.
		 그 메모리의 내용은 새로운 문자열을 읽을 때매다 바뀐다. 그러나 푸쉬 연산은 매번 정확히 동일한 주소를 스택에 넣는다.
		 그래서 스택을 팝하면, 항상 동일한 주소를 얻는다.
		 그러고 그것은 메모리에 마지막으로 읽어들인 문자열을 항상 참조한다.
		 특히, 그와 같은 스택은 새 문자열이 들어올 때마다 이들을 개별적으로 저장하지 않으므로 유용한 용도로 사용할 수 없다.
			

	=> 포인터들의 스택을 사용하는 한 가지 방법은, 호출한 프로그램이 포인터들의 배열을 제공하는 것이다.
	   그 포인터들의 배열에서 각각의 포인터는 서로 다른 문자열을 지시한다.
	   이러한 포인터들을 스택에 넣는 것은, 각각의 포인터가 서로 다른 문자열을 참조하기 때문에 논리적으로 틀리지 않는다.
			
*/