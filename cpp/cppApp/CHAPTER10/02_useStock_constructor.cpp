#include <iostream>
#include "stock_constructor.h"

int main()
{
	{
		using std::cout;
		cout << "생성자를 사용하여 새로운 객체들을 생성한다.\n";

		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();

		Stock stock2 = Stock("Boffo Objects", 2, 2.0);
		stock2.show();
		cout << "----------------------------\n";

		cout << "stock1을 stock2에 대입한다.\n";
		/*
			- 구조체 대입과 마찬가지로, 클래스 객체 대입은, 기본적으로 한 객체의 멤버를 
			  다른 객체에 복사하는 것이다.
		*/
		stock2 = stock1;
		cout << "stock1과 stock2를 출력한다.\n";
		stock1.show();
		stock2.show();
		cout << "----------------------------\n";

		cout << "생성자를 사용하여 객체를 재설정한다.\n";
		/*
			- 생성자에 대한 호출이 임시객체를 먼저 생성하고, 그 임시 객체가 stock1에 복사된다.
			  그러고 나서 임시 객체는 버린다. -> 임시 객체에 대해 파괴자 호출
		*/
		stock1 = Stock("Nifty Foods", 10, 50.0);		// 임시 객체
		cout << "갱신된 stock1:\n";
		stock1.show();
		cout << "----------------------------\n";

		cout << "프로그램을 종료합니다.\n";
		cout << "----------------------------\n";

		// 리스트 초기화 구문 사용
		Stock hot_tip = { "Derivatives Plus Plus", 100, 45.0 };
		Stock jock{ "Sport Age Storage, Inc" };
		Stock temp{ };
	}

	return 0;
}