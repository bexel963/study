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
		cout << words << " ����\n";
	}
	~JustTesting()
	{
		cout << words << " �ı�\n";
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
	
	pc1 = new (buffer) JustTesting;			// ��ü�� buffer�� ���´�.
	pc2 = new JustTesting("Heap1", 20);		// ��ü�� heap�� ���´�.

	cout << "�޸� ��� �ּ�: \n" << "buffer: " << (void*)buffer << "    heap: " << pc2 << endl;
	cout << "�޸� ����:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();
	cout << endl;

	JustTesting* pc3, * pc4;
	pc3 = new (buffer) JustTesting("Bad Idea", 6);
	pc4 = new JustTesting("Heap2", 10);

	cout << "�޸� ����:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();
	cout << endl;

	delete pc2;
	delete pc4;

	delete[] buffer;
	/*
		- buffer�� new[] �� ����Ͽ� �ʱ�ȭ�ǹǷ�, delete[]�� ����Ͽ� �����Ǿ�� �Ѵ�.
		- delete[] buffe; �� new�� ���� ���Ե� �޸� ��� ��ü�� �����Ѵ�. �׷��� �װ��� ��ġ ���� new�� �� ��Ͽ� ������ ��ü�鿡 ���� �ı��ڸ� ȣ������ �ʴ´�.
		  (delete�� ��ġ ���� new�� �ƴ϶� new�� �����Ͽ� �����ϱ� �����̴�.)
		  �׷��Ƿ�, ��ġ ���� new�� ���� �����Ǵ� ��ü���� ���� �ı��ڸ� ��������� ȣ���ؾ��Ѵ�.
				pc3->~JustTesting();
				pc1->~JustTesting();
		- ��ü�� �����ϴ� �� ���Ǵ� ���۴�, �� ���ۿ� ��� �ִ� ��� ��ü�� �ı��� �Ŀ� �����Ǿ�� �Ѵ�.
	*/

	cout << "����\n";

	return 0;
	
}

/*
	- ��ġ ���� new��, �޸𸮸� �����ϴ� �� ����� �޸� ��ġ�� ����ڰ� ���� �����ϴ� ���� ����Ѵ�.
*/

/*
	- �ı��� ȣ�� �ñ�
		: �ڵ� ��ü�� �ı��ڴ� �װ��� ���ǵ� ����� ���� �������� �� ȣ��ȴ�.
		: ���� ��ü *pt�� �ı��ڴ� delete�� ������ pt�� ��������� ����Ǿ��� �� ȣ��ȴ�.
				Act* pt = new Act;
				delete pt;
		: static ��ü�� �ı��ڴ� ��ü ���α׷��� ���� �� ȣ��ȴ�.			
*/