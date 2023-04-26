#include <iostream>
#include <new>	// 위치 지정 new 연산자 사용

/*
	new와 new[] 연산자는 다음 두 개의 함수를 호출한다.

	void* operator new(std::size_t);	// new에서 호출
	void* operator new[](std::size_t);	// new[]에서 호출

	int* pi1 = new int;
		=> int* pi1 = new(sizeof(int)); 를 호출한다.

	int* pi2 = new int[40];
		=> int* pi2 = new(40 * sizeof(int)); 를 호출한다.
*/
struct where
{
	double x;
	double y;
	double z;
};
const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	using namespace std;

	float* p_fees = new float[20];
	int* pi = new int(6);						// *pi를 6으로 초기화
	double* pd = new double(99.99);			
	where* one = new where{ 2.5, 5.3, 7.2 };	// 순차적인 구조체 초기화 (초기화 리스트 사용) -> C++11에서만 가능
	int* ar = new int[4]{ 1, 2, 3, 4 };			// 순차적인 변수 초기화 (초기화 리스트 사용) -> C++11에서만 가능
	int* pin = new int{ 6 };					// 초기화 리스트를 사용한 *pin 초기화 -> C++11
	double* pdo = new double{ 99.99 };	
	

	double* pd1, * pd2;
	int i;

	cout << "new와 위치 지정 new의 첫 번째 호출: \n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];

	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "메모리 주소: \n" << pd1 << " : 힙;      " << (void*)buffer << " : 정적" << endl;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "에 " << pd1[i] << ";    ";
		cout << &pd2[i] << "에 " << pd2[i] << ";" << endl; 
	}

	cout << "\nnew와 위치 지정 new의 두 번째 호출:  \n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];	// pd4로 buffer의 내용을 덮어쓴다.
	
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd3[i] << "에 " << pd3[i] << ";    ";
		cout << &pd4[i] << "에 " << pd4[i] << ";" << endl;
	}
	
	cout << "\nnew와 위치 지정 new의 세 번째 호출: \n";
	delete [] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "메모리 내용:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "에 " << pd1[i] << ";    ";
		cout << &pd2[i] << "에 " << pd2[i] << ";" << endl;
	}

	delete[] pd1;
	delete[] pd3;
	// 위치 지정 new에 의해 사용된 메모리를 delete를 사용하여 해제하지 않는다.
	// buffer에 의해 지정된 메모리는 정적 메모리이기 때문이다.
	// delete는 보통의 new에 의해 대입된 힙 메모리를 지시하는 포인터에만 사용할 수 있다.

	return 0;
}