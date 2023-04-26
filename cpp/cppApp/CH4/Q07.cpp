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
	TCL pizza;
	
	cout << "회사명 입력: ";
	getline(cin, pizza.cooName);
	cout << "피자의 지름 입력: ";
	cin >> pizza.diameter;
	cout << "피자의 중량 입력: ";
	cin >> pizza.weight;

	cout << "=====출력=====\n";
	cout << "회사명: " << pizza.cooName << endl;
	cout << "피자 지름: " << pizza.diameter << endl;
	cout << "피자 중량: " << pizza.weight << endl;

	return 0;
}