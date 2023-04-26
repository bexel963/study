#include <iostream>

using namespace std;

int main()
{
	float distanceDriven, amountOfGasoline;

	cout << "주행거리: ";
	cin >> distanceDriven;ㅣ
	cout << "소비한 휘발유 양: ";
	cin >> amountOfGasoline;

	cout << "Km 당 리터 수: " << amountOfGasoline / distanceDriven;

	return 0;
}

	
