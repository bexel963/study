#include <iostream>
#include <string>
#include "account.h"
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	Brass* p_clients[CLIENTS];
	string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌번호를 입력하십시오: ";
		cin >> tempnum;
		cout << "계좌 개설 잔액을 입력하십시오: $";
		cin >> tempbal;

		cout << "Brass 계좌는 1, BrassPlus 계좌는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1 아니면 2, 둘 중 하나를 입력하십시오: ";

		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한도를 입력하십시오: ";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	/*
		- 가상 파괴자
			: 파괴자들이 가상이 아니라면, 포인터형에 해당하는 파괴자만 호출된다.
			  이것은 포인터 p_clients[i]가 BrassPlus 객체를 지시하는 경우에도 Brass 파괴자가 호출된다는 것을 의미한다.
			  파괴자가 가상이면, 객체형에 해당하는 파괴자가 호출된다.
			  그래서 포인터가 BrassPlus 객체를 지시한다면, BrassPlus 파괴자가 호출된다.
			  일단 BrassPlus 파괴자가 수행되고 나서 기초 클래스 파괴자가 자동으로 호출된다.
			  그래서 가상 파괴자의 사용은 파괴자들이 올바른 순서로 호출되도록 만든다.
	*/

	cout << "프로그램을 종료합니다.";

	return 0;
}