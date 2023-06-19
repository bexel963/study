#include <iostream>

int main()
{
	using namespace std;

	int x;

	cout << "대입 표현식 x = 100의 값은 " << (x = 100) << endl;
	cout << "현재 x의 값은 " << x << endl;
	cout << "관계 표현식 x < 3 의 정수값은 " << (x < 3) << endl;
	cout << "관계 표현식 x > 3 의 정수값은 " << (x > 3) << endl;
	
	cout.setf(ios_base::boolalpha);
	
	cout << "관계 표현식 x < 3 의 bool값은 " << (x < 3) << endl;
	cout << "관계 표현식 x > 3 의 bool값은 " << (x > 3) << endl;

	return 0;
}