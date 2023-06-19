/*
	- exception 헤더 파일은 C++ 가 언어를 지원하기 위해 사용하는 다른 예외 클래스들의 기초 클래스로 사용하는 exception 클래스를 정의한다.
	  exception 클래스는 whta() 이라는 하나의 가상 멤버 함수가 주어진다. 그것은 시스템의 특성에 따라 하나의 문자열을 리턴한다.

				  #include <exception>

				  class bad_hmean : public std::exception
				  {
				  public:
					  const char* what() { return "hmean()에 잘못된 매개변수"; }
					  ...
				  };

				  class bad_gmean : public std::exception
				  {
				  public:
					  const char* what() { return "gmean()에 잘못된 매개변수"; }
					  ...
				  };

				  try {
					  ...
				  }
				  catch (std::exception& e)
				  {
					  cout << e.what() << endl;
				  }
		
*/

/*
	- stdexcept 헤더파일은 몇 가지 예외 클래스들을 더 정의한다.
			1) logic_error 클래스
			2) runtime_error 클래스
	  이들은 exception으로부터 public으로 파생된다.
	  생성자의 매개변수인 string 객체는 what() 에 의해 C스타일 문자열로 리턴된 문자 데이터를 제공한다.

				  class logic_error : public exception
				  {
				  public:
					  explicit logic_error(const string& what_arg);
					  ...
				  }

				  class runtime_error : public exception
				  {
				  public:
					  explicit runtime_error(const string& what_arg);
					  ...
				  }
*/

/*
	- logic_error 패밀리
		: 일반적인 논리 에러들을 서술한다.
		: 클래스들
			domain_error
			invalid_argument
			length_error
			out_of_bounds
		: 각각의 클래스는, 사용자가 what() 에 의해 리턴되는 문자열을 제공하는, logic_error의 생성자와 같은, 생성자를 가지고 있다.

	- domain_error
		정의역 -> 함수가 정의되는 값들로 이루어짐
		치역   -> 그 함수가 리턴하는 값들로 이루어짐
			ex) 사인 함수의 정의역 -> -무한 ~ +무한
			    사인 함수의 치역   -> -1 ~ +1
				아크사인의 정의역  -> -1 ~ +1
				아크사인의 치역    -> -무한 ~ +무한

				std::sin() 함수에 매개변수를 전달하는 함수를 작성한다면, 매개변수가 -1 ~ 1 까지의 정의역을 벗어날 때 그 함수가 
				domain_error 객체를 발생시키도록 할 수 있다.

	- invalid_argument
		: 기대하지 않는 값이 함수에 전달되었다는 것을 사용자에게 경고한다.

	- length_error
		: 원하는 액션을 취할 만큼 충분한 공간을 사용할 수 없다는 것을 나타내는 데 사용된다.

	- out_of_bounds
*/

/*
	- runtime_error
		: 예측이 어렵고 예방도 어려운, 실행하는 동안에 나타날 수 있는 에러들을 서술한다.
			range_error
			overflow_error
			underflow_error

		: 각각의 클래스는, 사용자가 what() 에 의해 리턴되는 문자열을 제공하는, runtime_error의 생성자와 같은, 생성자를 가지고 있다.

	- range_error
		: 언더플로나 오버플로 없이 계산 결과가 함수의 적절한 치역을 벗어날 수도 있다. 그러한 상황에서 range_error 예외를 사용할 수 있다.
*/

/*
	- 모든 에러 클래스들의 공통점은 서로 다른 클래스 이름들이 각각의 예외 데이터형을 개별적으로 처리할 수 있게 허용한다는 것이다.
	  한편, 상속 관계는 원한다면 그들을 일괄적으로 함께 다루는 것을 허용한다.
				try{
					...
				}
				catch(out_of_bounds& oe)
				{
					...
				}
				catch(logic_error& oe)
				{
					...
				}
				catch(exception& oe)
				{
					....
				}
*/

/*
	- bad_alloc 예외와 new
		: C++ 시스템들이 new를 사용할 때 일어나는 메모리 대입 문제를 해결하는 두 가지 방법
			1) 메모리 요청을 충족시킬 수 없을 경우 new가 널 포인터를 리턴한다.
			2) new가 bad_alloc 예외를 발생시킨다.

		: new 헤더파일에는 exception 클래스에서 public으로 파생된 bad_alloc 클래스의 선언이 들어있다.
*/

// - 예외가 포착되면 프로그램은 상속받은 what() 메서드가 리턴하는, 시스템마다 다른 메시지를 출력하고 즉시 종료되는 프로그램.....

#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

struct Big
{
	double stuff[20000];
};

int main()
{
	Big* pb;
	
	try {
		cout << "큰 메모리 블록 대입을 요청하고 있습니다.\n";
		pb = new Big[100000];		// 1,600,000,000 바이트 대입
	}
	catch (bad_alloc& ba)
	{
		cout << "예외가 감지되었습니다.\n";
		cout << "메모리 블록 대입 요청이 거부되었습니다.\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "메모리 블록이 성공적으로 대입되었습니다.\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;

	return 0;
}

/*
	- 대부분의 소스 코드는 new가 실패하면 null 포인터를 리턴하도록 작성되어있다.
	  일부 컴파일러들은 사용자가 원하는 행동을 플래그나 스위치로 세팅하여 이행할 수 있도록 새로운 new를 지원한다.
	  현재 표준은 null을 리턴하는 과거의 new를 대체하는 형태를 제공하고 있다.

	- 새로운 new는 다음과 같이 사용한다.
			int* pi = new (std::nothrow) int;
			int* pa = new (std::nothrow) int[500];
*/

//int main()
//{
//	Big* pb;
//
//	pb = new (std::nothrow) Big[10000];
//	if (pb == 0)
//	{
//		cout << "메모리 블록 대입 요청이 거부되었습니다.\n";
//		exit(EXIT_FAILURE);
//	}
//}