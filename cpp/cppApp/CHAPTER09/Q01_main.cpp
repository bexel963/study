#include <iostream>
#include "Q01.h"

const int Cnt = 10;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	golf player[Cnt];
	int cnt = 0;

	cout << "=====선수 등록(최대 10명)=====" << endl;
	cout << "--" << cnt + 1 << "번--\n";	
	while (setgolf(player[cnt]) != 0 && cnt < Cnt)
	{
		cnt++;
		cout << "--" << cnt + 1 << "번--\n";
	}
	cout << "입력 종료~~" << endl;
	
	cout << "====선수 명단====" << endl;
	for (int i = 0; i < cnt; i++)
		showgolf(player[i]);


	return 0;
}