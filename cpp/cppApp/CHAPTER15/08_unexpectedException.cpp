/*
	- 예외가 발생한 후, 문제를 일으킬 수 있는 두 가지 가능성
		: 예외가 예외 지정을 사용하는 함수 안에서 발생하면, 그 예외는 예외 지정자 리스트에 있는 데이터형들 중의 어느 하나와 일치해야 한다.
		  그렇지 않으면, 그 예외는 기대하지 않는 예외가 되고, 기본적으로 프로그램 실행이 중지된다.
		: 예외는 반드시 포착되어야 한다. 그렇지 않으면 기본적으로 프로그램 실행이 중지된다.


	1) 포착되지 않는 예외
		: 이 예외는 프로그램을 즉각 중지시키지 않고, 먼저 terminate() 를 호출한다.
		  terminate()는 abort()를 호출한다.
		  terminate()가 abort() 대신 다른 함수를 호출하도록 등록함으로써, terminate()의 행동을 바꿀 수 있다.
		  이를 위해서는 set_terminate()를 호출한다.
		  set_terminate(), terminate()는 exception 헤더 파일에 선언되어 있다.

				typedef void (*terminate_handler) ();	// terminate_handler를 '매개변수를 사용하지 않고 리턴값도 없는 함수를 가리키는 포인터'를 위한 데이터형 이름으로 만든다.

				terminate_handler set_terminates(terminate_handler f) noexcept();
				: 이 함수는 매개변수를 사용하지 않고 리넡형이 void인 함수의 이름(즉, 함수의 주소)을 매개변수로 사용한다.
				  그리고 이전에 등록된 함수의 주소를 리턴한다.
				  set_terminate() 함수를 한 번 이상 호출하게 되면, terminate()는 가장 최근의 set_terminate() 호출에 의해 설정된 함수를 호출한다.

		: EX

				#include <exception>
				using namespace std;

				void myQuit()
				{
					cout << "포착되지 않는 예외가 발생하여 프로그램을 중지시킵니다.\n";
					exit(5);
				}
				set _terminate(myQuit);	// 프로그램의 시작 위치에 위 함수를 프로그래머가 선택한 종료 행동으로 등록한다.
										   이렇게 하면, 예외가 발생했으나 포착되지 않으면, 프로그램은 terminate()를 호출하고, terminate()가 myQuit()를 호출한다.

	2) 기대하지 않는 예외
		: 어떤 함수에 예외 지정을 사용함으로써, 그 함수의 사용자들은 어떤 예외들이 포착될 것인지 알 수 있다.

		: EX
			
				double argH(double, double) throw(out_of_bounds);		// 함수 원형에 예외 지정...

				try {
					x = argH(a, b);
				}
				catch (out_of_bounds& ex)
				{
					...
				}
		: 예외 지정은, 그 예외 지정을 사용하는 함수가 호출되는 함수들이 발생시키는 예외들을 포함해야 한다.
		  예를 들어, argH()가 retort 객체 예외를 발생시키는 duh()를 호출한다면, duh() 예외 지정뿐만 아니라 argH() 예외 지정에도 retort가 들어 있어야 한다.

		: 기대하지 않는 예외가 발생했다면, 프로그램은 unexpected()를 호출한다.
		  이어서 unexpected()는 terminate()를 호출하고, terminate()는 기본적으로 abort()를 호출한다.
		  terminate()의 행동을 바꾸는 set_terminate()가 준비되어 있듯이, unexpected()의 행동을 바꾸는 set_unexpected()가 준비되어 있다.
		  이 함수들도 exception 헤더 파일에 선언되어 있다.

				typedef void (*unexpected_handler) ();
				
				unexpected_handler set_unexpected(unexpected_handler f) noexcept;

		: set_unexpected()를 위해 제공하는 함수의 행동은, set_terminate()에 제공하는 함수의 행동보다 더 세밀하게 제어할 수 있다.
				1) 디폴트 행동 - terminate() 호출, abort() 또는 exit()를 호출하여 프로그램을 종료시킬 수 있다.
				2) 예외를 발생시킬 수 있다.
					
		: 예외를 발생시킨 후의 결과는, unexpected_handler 대체 함수가 발생시키는 예외와, 기대하지 않는 데이터형의 예외를 발생시키는 그 함수의 오리저널 예외 지정에 달려 있다.
			-> 새로 발생된 예외가 오리지널 에외 지정과 일치하면, 프로그램은 그곳으로부터 정상적으로 진행한다.
			   즉, 새로 발생된 예외와 일치하는 catch 블록을 찾는다.

			-> 새로 발생된 예외가 오리지널 예외 지정과 일치하지 않고, 그 예외 지정에 std::bad_exception형이 들어 있지 않으면, 프로그램은 terminate()를 호출한다.
			   (bad_exception형은 exception형으로부터 파생되고, exception 헤더 파일에 선언되어 있다.)

			-> 새로 발생된 예외가 오리지널 예외 지정과 일치하지 않고, 오리지널 예외 지정에 std::bad_exception형이 들어 있으면, 그 일치하지 않는 예외는 
			   std::bad_exception형의 예외로 대체된다.

		: 결론적으로, 기대되는 것이든 기대되지 않는 것이든 모든 예외를 포착하고 싶으면 다음과 같이 작성하면 된다.

				#include <exception>
				using namespace std;

				void myUnexpected()					// 기대하지 않는 예외들을 bad_exception형으로 변환하고, 적절한 원형을 가지고 있는 대체 함수 설계
				{
					throw std::bad_exception();		// 예외 없이 그냥 throw만 사용하면 오리지널 예외가 다시 발생한다. 그러나 예외 지정에 그 데이터형이 들어 있으면, 그 예외는 bad_exception 객체로 대체된다.
				}
				
				set_unexpected(myUnexpected);		// 대체 함수 등록

				double argH(double, double) throw(out_of_bounds, bad_exception);
				...
				try {
					x = argH(a, b);
				}
				catch (out_of_bounds& ex)
				{
					...
				}
				catch (bad_exception& ex)
				{
					...
				}
*/
