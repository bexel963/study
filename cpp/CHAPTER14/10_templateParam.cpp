#include <iostream>
#include "stackTemplate.h"

template <template <class T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() { };
	
	// Thing 클래스가 push()와 pop() 멤버를 가지고 있다고 가정한다.
	bool push(int a, double x) { return s1.push(a) && s2.push(x); }
	bool pop(int& a, double& x) { return s1.pop(a) && s2.pop(x); }
};
/*
	- Crab 클래스 선언은 Thing으로 나타내는 템플릿 클래스에 관해 세 가지를 가정한다.
		  그 클래스는 push()를 가져야 한다.
		  그 클래스는 pop()를 가져야 한다.
		  이 메서드들은 하나의 특별한 인터페이스를 가져야 한다.
	- Crab 클래스는 Thing형 선언과 일치하고, push() 메서드와 pop() 메서드를 반드시 가지고 있는 어떤 템플릿 클래스도 사용할 수 있다.
*/

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	Crab<Stack> nebula;		
	/*
		- Stack 클래스는 template <class T> class Thing과 일치해야 한다.
		- 구체화
			Thing<int> s1;		=> Stack<int> s1;
			Thing<double> s2;	=> Stack<double> s2;
	*/

	int ni;
	double nb;
	cout << "4 3.5와 같이 int double 쌍을 입력하라(끝내려면 0 0):\n";
	while (cin >> ni >> nb && ni > 0 && nb > 0)
	{
		if (!nebula.push(ni, nb))
			break;
	}

	while (nebula.pop(ni, nb))
		cout << ni << ", " << nb << endl;
	
	cout << "프로그램 종료\n";

	return 0;
}


/*
	- 템플릿 매개변수를 일반 매개변수와 혼합하여 사용할 수 있다.

	template <template <class T> class Thing, class U, class V>
	class Crab
	{
	private:
		Thing<U> s1;
		Thing<V> s2;
		...
	}

	int main()
	{
		Crab<Stack, int, double> nebula;
	}
*/
