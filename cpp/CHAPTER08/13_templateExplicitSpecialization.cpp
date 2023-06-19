#include <iostream>

template<typename T>
void Swap(T&, T&);

struct job
{
	char name[40];
	double salary;
	int floor;
};

//template<> void Swap<job>(job&, job&);
template<> void Swap(job&, job&);	// job을 위한 특수화라는 것을 함수 매개변수의 데이터형이 알려 주기 때문에, Swap<job>에 있는 <job>은 생략할 수 있다.
void Show(job&);

int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);				// Swap(int&, int&)을 생성한다.
	cout << "이제 i, j = " << i << ", " << j << ".\n\n";

	job sue = { "Susan Yaffe", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "job 교환 전: \n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);		// void Swap(job&, job&)을 생성한다.
	
	cout << "job 교환 후: \n";
	Show(sue);
	Show(sidney);

	return 0;
}

template<typename T>
void Swap(T& a, T& b)	// 템플릿 원형
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<> void Swap<job>(job& j1, job& j2)		// job형을 위한 명시적 특수화
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j)
{
	using namespace std;
	cout << j.name << ": (" << j.floor << "층에 거주) "
		<< "$" << j.salary << endl;
}

/*
	- 함수 이름이 하나 주어지면, 사용자는 템플릿이 아닌 함수, 템플릿 함수, 명시적 특수화 템플릿 함수를 가질 수 있다.
	  또한 이 모든 것들의 오버로딩 버전도 가질 수 있다.
	- 명시적 특수화를 하기 위한 원형과 정의 앞에 template<>가 와야 한다. 그리고 그 특수형의 이름을 서술해야 한다.
	- 특수화는 템플릿을 무시하고, 템플릿이 아닌 함수는 특수화와 템플릿 둘 다 무시한다.

	- 이들이 함께 공존할 때, 컴파일러는 명시적 특수화 버전이나 템플릿 버전보다 템플릿이 아닌 버전을 선택한다.
	  그리고 템플릿 버전보다는 명시적 특수화 버전을 선택한다.
*/