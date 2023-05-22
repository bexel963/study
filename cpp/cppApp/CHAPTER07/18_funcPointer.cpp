#include <iostream>

double gildong(int);
double moonsoo(int);
void estimate(int, double (*)(int));

int main()
{
	using namespace std;
	int code;

	cout << "필요한 코드의 행 수를 입력하십시오: ";
	cin >> code;
	cout << "홍길동의 시간 예상: \n";
	estimate(code, gildong);
	cout << "박문수의 시간 예상:\n";
	estimate(code, moonsoo);

	return 0;
}

double gildong(int lns)
{
	return 0.05 * lns;
}

double moonsoo(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;
	cout << lines << "행을 작성하는데 " << (*pf)(lines) << "시간이 걸립니다.\n";
}

/*
	- 함수의 주소는 그 함수에 해당하는 기계어 코드가 저장되어 있는 메모리 블록의 시작 주소이다.
	- 다른 함수의 주소를 매개변수로 취하는 함수를 작성할 수 있다.
	- think()가 함수라면 think는 그 함수의 주소이다.
	- 함수를 매개변수로 전달하려면 함수 이름만 전달하면 된다.
	- 어떤 데이터형을 지시하는 포인터를 선언하려면, 그 포인터가 정확하게 어떤 데이터형을 지시하는지 선언에서 정확하게 지정해야 한다.
	  마찬가지로, 함수를 지사하는 포인터를 선언할 때에도, 그 포인터가 지시하는 함수의 데이터형을 지정해야 한다.
	  이것은 포인터 선언이 함수의 리턴형과 함수의 시그내체(매개변수 리스트)를 알려 주어야 한다는 것을 의미한다.

		double pam(int n);	// 함수 원형
		double (*pf)(int);	// 함수 포인터 선언
		pf = pam;

		double x = pam(4);
		double y = (*pf)(4);
		double z = pf(4);
*/