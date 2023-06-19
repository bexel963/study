#include <iostream>
#include <string>

using namespace std;

struct TCL
{
	string cooName;
	float diameter;
	float weight;
};

int main()
{
	TCL* p = new TCL;


	cout << "피자의 지름 입력: ";
	(cin >> p->diameter).get();
	cout << "회사명 입력: ";
	getline(cin, p->cooName);
	cout << "피자의 중량 입력: ";
	cin >> p->weight;

	cout << "=====출력=====\n";
	cout << "회사명: " << p->cooName << endl;
	cout << "피자 지름: " << p->diameter << endl;
	cout << "피자 중량: " << p->weight << endl;

	return 0;
}