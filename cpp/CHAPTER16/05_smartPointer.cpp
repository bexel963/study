/*
	- smart pointer는 포인터처럼 행동하는 클래스 객체이지만, 몇 가지 추가 기능을 지닌다.

	- 문제 있는 코드

			void remmoder(string& str)
			{
				string* ps = new string(str);
				...
				str = ps;
				return;
			}
			: 이 함수는호출될 때마다 힙 메모리를 대입하지만 그것을 해제하지 않는다.
			  delete ps; 를 추가하는 것인 최선의 해결책이 아닌다. (빼먹을 가능성 높음..)

	- 함수가 정상적으로 종료될 때 또는 예외가 발생하여 종료될 때, 지역 변수는 스택 메모리로부터 삭제된다.
	  그래서 ps 포인터가 차지하고 있던 메모리가 해제된다. 이때 ps 포인터가 지시하는 메모리도 함게 해제된다면 좋을 것이다.
	  이것은 ps의 수명이 다했을 때 프로그램이 어떤 추가 조치를 취해야 한다는 것을 의미한다.
	  이러한 추가 서비스는 기본 데이터형들에 대해서는 제공되지 않고, 파괴자 메커니즘을 통해서 클래스들에 대해서면 제공된다.
	  그래서 ps가 클래스 객체가 아니라 일반 포인터인 것이 문제가 된다.
	  ps가 객체였다면, ps의 수명이 다했을 때 그것에 의해 지시되는 메모리도 파괴자를 통해서 함께 해제될 수 있기 때문이다.
	  이것이 auto_ptr가 탄생한 배경이다.
*/

/*
	- 스마트 포인터의 사용
			1) auto_ptr
			2) unique_ptr
			3) shared_ptr
		: 스마트 포인터 템플릿들은 각각 new를 통해 얻어지는 주소를 대입할 포인터를 정의한다.
		  스마트 포인터가 수명을 다했을 때, 파괴자는 delete를 사용하여 메모리를 해제한다.
		  따라서, 만일 new가 리턴하는 주소를 위 세 개의 객체 중 하나에 대입하게 되면, 나중에 메모리를 해제할 필요가 없으며,
		  스마트 포인터 객체가 수명이 다했을 때, 자동적으로 메모리가 해제된다.
		: 이러한 스마트 포인터 객체들 중 하나를 생성하기 위해서는 템플릿을 정의하는 memory 헤더 파일을 소스 코드에 포함해야 한다.
		  그 다음, 일반적인 템플릿 구문을 사용하여 필요한 포인터의 종류를 구체화 한다.

				template<class X> 
				class auto_ptr 
				{
				public:
					explicit auto_ptr(X* p=0) throw();	// 스마트 포인터 생성자
					...
				};

				auto_ptr<double> pd(new double);	// new double은 new가 리턴한 새로 대입된 메모리를 가리키는 포인터이다.
				auto_ptr<string> ps(new string);
*/
/*
	- 일반 포인터와 비교
				double* pd = new double;
				auto_ptr<double> ap(new double);
*/


#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s)
	{
		std::cout << "객체가 생성되었습니다.\n";
	}
	~Report()
	{
		std::cout << "객체가 삭제되었습니다.\n";
	}
	void comment() const
	{
		std::cout << str << std::endl;
	}
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("unique_ptr"));
		ps->comment();
	}

	return 0;
}

/*
	- 이 각각의 클래스들은 매개변수로 포인터를 받아들이기 위해 명시적 생성자를 가지고 있다.
	  따라서, 포인터를 auto_ptr로 변환하기 위해 자동 형 변환이 없어도 된다.

			share_ptr<double> pd;
			double* p_reg = new double;
			
			pd = p_reg;							// 허용되지 않음(암시적 변환)
			pd = (share_ptr<double>)p_reg;		// 허용됨(명시적 변환)

			share_ptr<double> pshared = p_reg;	// 허용되지 않음(암시적 변환)
			share_ptr<double> pshared(p_reg)	// 허용됨(명시적 변환)
			
	- 스마트 포인터 템플릿 클래스들은 일반 포인터처럼 동작할 수 있다.

	- 스마트 포인터를 사용하면 안되는 경우

			string vacation("I wandered lonely as a cloud.");
			shared_ptr<string> pvac(&vacation);		// error

		: pvac가 수명을 다했을 때 프로그램은 delete하려는 메모리가 heap에 존재하지 않기 때문에 위 코드는 잘못된 것이다.
*/