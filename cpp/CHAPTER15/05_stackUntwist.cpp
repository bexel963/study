/*
	- C++는 스택에 정보를 올려 두면서 함수 호출들을 처리한다.
	  프로그램은, 호출한 함수 구문의 주소를 스택에 올려 놓는다.
	  호출된 함수의 실행이 끝나면, 프로그램은 스택에 올려 놓은 그 주소를 사용하여 프로그램 실행을 계속할 장소를 결정한다.
	  함수 호출은, 자동 변수로 취급되는 함수 매개변수들을 스택에 올려 놓는다.
	  호출된 함수가 새로운 자동 변수를 생성하면 그것도 스택에 추가된다.
	  어떤 함수가 종료되면, 프로그램 실행이 그 함수가 호출될 때 스택에 저장해 둔 주소로 넘어가고, 스택의 꼭대기가 해제된다.
	  그렇게 하여 각 함수는 그것을 호출한 함수에게로 돌아간다.
	  각 함수는 종료할 때 자신의 자동 변수들을 해제한다.
	  자동 변수가 클래스 객체일 경우에 클래스 파괴자가 호출된다.

	- 프로그램이 예외를 통해 종료될 떄에도 스택에서 메모리를 해제한다.
	  그러나 스택에서 만나는 첫 번째 리턴 주소에서 멈추지 않고, try 블록에 들어 있는 리턴 주소에 도달할 때 까지 계속해서 스택을 해제한다.
	  이 때 제어는 함수 호출 뒤에 오는 첫 번째 구문이 아니라, try 블록의 끝에 이어지는 예외 핸들러로 넘어간다. (스택 풀기)

	- return 구문은 그 함수가 스택에 올려 놓은 객체들만 처리한다. 그러나 throw 구문은 try 블록과 그 throw 구문 사이에 개입된 함수 호출들의
	  전체적인 연쇄가 스택에 올려 놓은 객체들을 모두 처리한다.
*/

#include <iostream>
#include <cmath>
#include <string>
#include "exceptionObj.h"

class demo
{
private:
	std::string word;
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo " << word << " 생성\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " 파괴\n";
	}
	void show() const
	{
		std::cout << "demo " << word << " 생존\n";
	}
};

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
double means(double a, double b) throw(bad_hmean, bad_gmean);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	{
		demo d1("found in block in main()");
		cout << "두 수를 입력하십시오: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << x << "와 " << y << "의 평균의 평균은 " << z << endl;
				cout << "다음 두 수를 입력하십시오: ";
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "다시 하십시오.\n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "사용된 두 값: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
				break;
			}
		}
		d1.show();
	}

	cout << "프로그램을 종료합니다.\n";
	cin.get();
	cin.get();

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);

	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);

	return std::sqrt(a * b);
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;		// 산술 평균
	try
	{
		hm = hmean(a, b);	// 조화 평균
		gm = gmean(a, b);	// 기하 평균
	}
	catch (bad_hmean& bg)				// bg는 객체의 복사본을 참조한다. hmean()이 종료된 후에 bad_hmean은 더 이상 존재하지 않기 때문이다.
	{
		bg.mesg();
		std::cout << "means()에서 잡힘\n";
		throw;
	}
	d2.show();

	return (am + hm + gm) / 3.0;
}

/*
	- 프로그램이 예외가 잡히는 곳까지 도달하기 위해 스택을 풀 때, 프로그램은 스택에 있는 자동 기억공간 변수들을 해제한다.
	  어떤 변수가 클래스 객체인 경우에는 그 객체를 위한 파괴자가 호출된다.

	- gmean()은 bad_gmean 예외를 발생시키다. means()가 bad_gmean 예외를 잡지 않기 때문에, 이 예외는 main()에 까지 전달된다.
	  그리고 means()에 있는 나머지 코드는 더 이상 실행되지 않는다. 그러나 다시 한 번, 프로그램이 스택을 풀 때, 프로그램은
	  자동 지역 변수들을 해제한다. 그래서 d2를 위한 파괴자가 호출된다.
*/

/*
	- 함수가 예외를 발생시키는지 모를 때 (그 데이터형을 모를 때) 어떤 예외라도 포착하는 방법은 예외 데이터형에 대해 생략 부호 ...를 사용하는 것이다.
				catch (...)
				{
					// 구문들
				}
*/