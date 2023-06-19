#include <iostream>

void cheers(int);
double cube(double);

int main(void)
{
	using namespace std;
	cheers(5);
	cout << "하나의 수를 입력하십시오: ";
	double side;
	cin >> side;
	
	// main()은 리턴값 저장 위치에 있는 리턴값을 조사하여 volume에 대입한다.
	double volume = cube(side);

	cout << "한 번의 길이가 " << side << "센티미터인 정육면체의 부피는 ";
	cout << volume << "세제곱센티미터입니다.\n";
	cheers(cube(2));

	return 0;
}

void cheers(int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << "Cheers! ";
	cout << endl;
}

// cube()는 리턴값을 계산하여 리턴값 저장위치(CPU의 레지스터나 메모리의 어떤 지정된 위치)에 그 값을 넣는다.
double cube(double x)
{
	return x * x * x;
}

/*
	- 정수, 부동 소수점수, 포인터, 구조체 등 배열을 제외한 그 밖의 모든 데이터형들은 리턴값으로 사용할 수 있다.
	- 일반적으로 함수는 자신의 리턴값을 CPU의 지정된 레지스터나 메모리에 복사하는 방법으로 리턴한다.
	  그러면 함수를 호출한 프로그램이 그 위치에 무엇이 있는지 조사한다. 그러므로 리턴하는 함수와 호출하는 함수는 그 위치에 놓을 값의 데이터형을 서로 일치시켜야 한다.
	  함수 원형은 호출한 프로그램에게 그 위치에 어떤 데이터형이 놓일지 알려 준다.

	- C++ 에서는 잘못된 산술 데이터형이 함수에 전달되면 함수 원형에 정의되어 있는 데이터형으로 자동 형변환 시켜준다. 
	- 함수 원형은 이치에 맞을 때에만 데이터형을 변환한다.
	- 함수 원형 비교는 컴파일 시에 이루어진다. 이것을 정적 데이터형 검사라 한다.
*/