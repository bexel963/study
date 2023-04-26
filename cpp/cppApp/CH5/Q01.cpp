/*
	- 정수 두 개 입력 받음.
		: 둘 중 작은 정수를 먼저 입력한다고 가정
	- 입력받은 두 정수를 포함하여 그 사이에 있는 모든 정수들의 합을 출력
*/
#include <iostream>

using namespace std;

int main()
{
	int n1, n2;
	int sum = 0;
	
	cout << "정수 두개 입력(정수1 정수2): ";

	cin >> n1;
	cin >> n2;

	for (int i = n1; i <= n2; i++)
		sum += i;

	cout << n1 << "부터 " << n2 << "사이에 있는 모든 정수들의 합: " << sum << endl;
	
	return 0;
}