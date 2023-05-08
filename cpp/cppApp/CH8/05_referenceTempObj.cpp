#include <iostream>

double cube(double);
double refcube(double&);

int main()
{
	using namespace std;
	double x = 3.0;

	cout << cube(x);
	cout << " = " << x << "의 세제곱\n";

	cout << refcube(x);
	cout << " = " << x << "의 세제곱\n";

	return 0;
}

double cube(double a)
{
	a *= a * a;

	return a;
}
double refcube(double& ra)
{
	ra *= ra * ra;

	return ra;
}
/*
	- 함수에 전달하는 정보를 그 함수가 변경하지 않고 사용만 하도록 하려면, 상수 참조를 사용해야 한다.
		double refcube(const double& ra);
*/

/*
	- C++는 실제 매개변수와 참조 매개변수가 일치하지 않을 때 임시 변수를 생성할 수 있다.
	- 참조 매개변수가 const일 경우, 컴파일러는 다음과 같은 두 가지 상황에서 임시 변수를 생성한다.
		1) 실제 매개변수가 올바른 데이터형이지만 lValue가 아닐 때
		2) 실제 매개변수가 잘못된 데이터형이지만 올바른 데이터형으로 변환할 수 있을 때	  

		double refcube(const double& ra)
		{
			return ra * ra * ra;
		}

		double side = 3.0;
		double* pd = &side;
		double& rd = side;
		long edge = 5L;
		double lens[4] = { 2.0, 5.0, 10.0, 12.0 };
		
		double c1 = refcube(side);	
		double c2 = refcube(lens[2]);	
		double c3 = refcube(rd);				// ra는 rd이며 side
		double c4 = refcube(*pd);				// ra는 *pd이며 side

		double c5 = refcube(edge);				// 1) -> ra는 임시 변수
		double c6 = refcube(7.0);				// 2) -> ra는 임시 변수
		double c7 = refcube(side + 10.0);		// 2) -> ra는 임시 변수

		c5, c6, c7의 경우 컴파일러는 익명의 임시 변수를 만들고, ra로 하여금 그것을 참조하게 한다.
	    임시 변수는 함수가 호출되어 있는 동안 유지되지만, 그 후에 컴파일러는 그것을 마음대로 없앨 수 있다.

	- 임시 변수의 생성은 상수 참조인 경우에만 허용한다.
			void swap(int& a, int& b)
			{
				int temp;
				temp = a;
				a = b;
				b = temp;
			}
			long a = 3, b = 5;
			swap(a, b);
	  데이터형이 일치하지 않으므로, 컴파일러는 두 개의 int형 임시 변수를 만들고 그 것들을 3과 5로 각각 초기화한 후 임시 변수의 내용을 서로 교환한다.
	  그러므로 여기서 a와 b는 변경되지 않는다.
	  참조 매개변수를 가진 함수의 목적이 매개변수로 전달되는 변수를 변경하는 것이라면, 임시 변수의 생성은 그 목적을 방해한다.
	  그래서 C++은 상수 참조가 아닌 경우에 임시 변수의 생성을 허용하지 않는다.

	- 함수 호출 실제 매개변수가 lValue가 아니거나, 그에 대응하는 const 참조 매개변수의 데이터형과 일치하지 않을 때, C++는 정확한 데이터형의 익명 변수를 생성하고,
	  그 익명 변수에 함수 호출 실제 매개변수의 값을 대입하고, 매개변수가 그 익명 변수를 참조하게 한다.
*/