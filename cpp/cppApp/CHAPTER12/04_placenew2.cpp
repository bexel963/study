#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string& s = "Just Testing", int n = 0)
	{
		words = s;
		number = n;
		cout << words << " 생성\n";
	}
	~JustTesting()
	{
		cout << words << " 파괴\n";
	}
	void Show() const
	{
		cout << words << ", " << number << endl;
	}
};

int main()
{
	char* buffer = new char[BUF];

	JustTesting* pc1, * pc2;

	pc1 = new (buffer) JustTesting;			// 객체를 buffer에 놓는다.
	pc2 = new JustTesting("Heap1", 20);		// 객체를 heap에 놓는다.

	cout << "메모리 블록 주소: \n" << "buffer: " << (void*)buffer << "    heap: " << pc2 << endl;
	/*
		- C++에서 포인터 변수를 출력할 때 형변환을 (void*)로 해야하는 이유
			: 포인터 변수는 주소 값을 나타내므로, 주소 값은 메모리 주소를 16진수로 표현해야 합니다. void* 형변환은 포인터를 주소 값으로 캐스팅하기 때문에, 
			  포인터 변수가 가리키는 메모리 주소를 16진수로 출력할 수 있습니다.
			: C++에서 포인터 변수는 다양한 타입을 가리킬 수 있으므로, 이를 일관성 있게 출력하기 위해 void* 형변환이 사용됩니다. 
			  예를 들어, int* 타입의 포인터 변수와 char* 타입의 포인터 변수가 있을 경우, 이를 각각 출력하면 출력 형식이 달라질 수 있습니다. 
			  하지만, void* 형변환을 사용하면 모든 포인터 변수를 동일하게 출력할 수 있습니다.
			: 포인터 변수를 출력할 때 void* 형변환을 사용하면, 포인터 변수가 가리키는 값이 무엇인지를 알 수 없어 보안상의 이점이 있습니다. 
			  포인터 변수가 가리키는 값이 민감한 정보일 경우, 해당 값이 노출되지 않도록 void* 형변환을 사용하여 출력할 수 있습니다.
			  따라서, C++에서 포인터 변수를 출력할 때는 일반적으로 (void*) 형변환을 사용하여 메모리 주소를 16진수로 출력합니다.
	*/

	cout << "메모리 내용:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();
	cout << endl;

	JustTesting* pc3, * pc4;
	pc3 = new (buffer) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "메모리 내용:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();
	cout << endl;

	delete pc2;
	delete pc4;

	pc3->~JustTesting();	// 1. pc3이 지시하는 객체를 파괴한다.
	pc1->~JustTesting();	// 2. pc1이 지시하는 객체를 파괴한다.
	delete[] buffer;		// 3. buffer 해제

	cout << "종료\n";

	return 0;

}