#include <iostream>
#include "stonewt.h"
using std::cout;

void display(const Stonewt, int);

int main()
{
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);	// == Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	cout << "태너 가수의 몸무게: ";
	pavarotti.show_stn();
	
	cout << "탐정의 몸무게: ";
	wolfe.show_stn();
	
	cout << "대통령의 몸무게: ";
	taft.show_lbs();

	cout << "---------------------------------------\n";
	pavarotti = 276.8;	// 변환을 위해 생성자를 사용한다.
	taft = 325;			// taft = Stonewt(325) 와 같다.
	cout << "저녁 식사를 마친 후 테너 가수의 몸무게: ";
	pavarotti.show_stn();
	cout << "저녁 식사를 마친 후 대통령의 몸무게: ";
	taft.show_lbs();
	cout << "레슬링 선수는 그보다 더 무겁다.\n";
	display(422, 2);
	cout << "비만은 건강의 최대의 적이다.\n";

	cout << "---------------------------------------\n";
	cout << "           <변환 함수 테스트>\n";
	
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;	// 암시적 변환
	cout << "double형으로 변환 => ";
	cout << "Poppins: " << p_wt << "파운드\n";
	cout << "int형으로 변환 => ";
	cout << "Poppins: " << (int)poppins << "파운드\n";

	return 0;
}

void display(const Stonewt st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "와! ";
		st.show_stn();
	}
}