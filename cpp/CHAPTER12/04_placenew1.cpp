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

	delete[] buffer;
	/*
		- buffer는 new[] 를 사용하여 초기화되므로, delete[]를 사용하여 해제되어야 한다.
		- delete[] buffe; 는 new에 의해 대입된 메모리 블록 전체를 삭제한다. 그러나 그것은 위치 지정 new가 그 블록에 생성한 객체들에 대한 파괴자를 호출하지 않는다.
		  (delete가 위치 지정 new가 아니라 new와 연계하여 동작하기 때문이다.)
		  그러므로, 위치 지정 new에 의해 생성되는 객체들을 위한 파괴자를 명시적으로 호출해야한다.
				pc3->~JustTesting();
				pc1->~JustTesting();
		- 객체를 저장하는 데 사용되는 버퍼는, 그 버퍼에 들어 있는 모든 객체가 파괴된 후에 해제되어야 한다.
	*/

	cout << "종료\n";

	return 0;
	
}

/*
	- 위치 지정 new는, 메모리를 대입하는 데 사용할 메모리 위치를 사용자가 직접 지정하는 것을 허용한다.
*/

/*
	- 파괴자 호출 시기
		: 자동 객체의 파괴자는 그것이 정의된 블록의 끝에 도달했을 때 호출된다.
		: 동적 객체 *pt의 파괴자는 delete가 포인터 pt에 명시적으로 적용되었을 때 호출된다.
				Act* pt = new Act;
				delete pt;
		: static 객체의 파괴자는 전체 프로그램이 끝날 때 호출된다.			
*/