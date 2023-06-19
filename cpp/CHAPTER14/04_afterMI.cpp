#include "afterMI.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Worker �޼����
Worker::~Worker() { }	// ���� �Լ������� ���� �ı��ڸ� �����ؾ� �Ѵ�.

// protected �޼����
void Worker::Data() const
{
	cout << "��� �̸�: " << fullname << endl;
	cout << "��� ��ȣ: " << id << endl;
}
void Worker::Get()
{
	getline(cin, fullname);
	cout << "�����ȣ�� �Է��Ͻʽÿ�: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}


// Waiter �޼����
void Waiter::Set()
{
	cout << "�������� �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}
void Waiter::Show() const
{
	cout << "����: ������\n";
	Worker::Data();
	Data();
}
// protected �޼����
void Waiter::Data() const
{
	cout << "������ ���: " << panache << endl;
}
void Waiter::Get()
{
	cout << "������ ����� �Է��Ͻʽÿ�: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

// Singer �޼����
char* Singer::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	cout << "������ �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}
void Singer::Show() const
{
	cout << "����: ����\n";
	Worker::Data();
	Data();
}

// protected �޼����
void Singer::Data() const
{
	cout << "��Ҹ� ����: " << pv[voice] << endl;
}
void Singer::Get()
{	
	cout << "������ ��Ҹ� ���� ��ȣ�� �Է��Ͻʽÿ�::\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "0���� ũ�ų� ���� " << Vtypes << "���� ���� ���� �Է��Ͻʽÿ�." << endl;

	while (cin.get() != '\n')
		continue;
}

// SingingWaiter �޼����
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}
void SingingWaiter::Set()
{
	cout << "���� �� �������� �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show() const
{
	cout << "����: ���� �� ������\n";
	Worker::Data();
	Data();
}

/*
			SingingWaiter newhire("Madonna", 2005, 6, soprano);
			newhire.Show(); => ��ȣ�ϴ�.
	
	- ���� ��ӿ����� Show()�� �ٽ� �������� ������ ���� ����� ������ ���ǰ� ���ȴ�.
	  �� ���, ������ ������ ������ Show() �Լ��� ���� �ϳ��� ������ �ְ� �̰��� ȣ���� ��ȣ�ϰ� �����.
	  ->
			SingingWaiter newhire("Madonna", 2005, 6, soprano);
			newhire.Singer::Show();	=> ��� ���� ���� �����ڸ� ����ϸ� ��� ���� ���ϴ��� Ȯ���ϰ� �� �� �ִ�.

	- �� ���� ��� ��, �Ļ� �޼��尡 ���� �޼��带 ȣ���ϰ� �ϴ� �����, ���� ��ӿ����� �� �����Ѵ�.

			void Worker::Show() const
			{
				cout << "��� �̸�: " << fullname << "\n";
				cout << "��� ��ȣ: " << id << "\n";
			}
			void Waiter::Show() const
			{
				Worker::Show();
				cout << "������ ���: " << panache << "\n";
			}
			void HeadWaiter::Show() const
			{
				Waiter::Show();
				cout << "�ܸ� ���: " << presence << "\n";
			}

	- ���� ���� ������ ���� ����� SingerWaiter�� ���ؼ��� �����Ѵ�.

			void SingingWaiter::Show()
			{
				Singer::Show();
			}
	  Waiter ������ �����ϱ� ������ �����Ѵ�. Waiter ������ �Բ� ȣ�������ν� �� ���� �ذ��� ���� �ִ�.
			void SingingWaiter::Show()
			{
				Singer::Show();
				Waiter::Show();
			}
	  �׷��� �̰���, ��� �̸��� ��� ��ȣ�� �� �� ǥ���ϰ� �����.
*/

/*
	- ������ ���� ��� ��ſ� ��� ���� ����� ����ϴ� ����� �ִ�.
	  ��, �� ������ ���� ����ϴ� �޼��带 ���� ������ ��, SingingWaiter::Show()���� �� ���е��� �����ϴ� ���̴�.

			void Worker::Data() const
			{
				cout << "��� �̸�: " << fullname << "\n";
				cout << "��� ��ȣ: " << id << "\n";
			}
			void Waiter::Data() const
			{
				cout << "������ ���: " << panache << endl;
			}
			void Singer::Data() const
			{
				cout << "��Ҹ� ����: " << pv[voice] << endl;
			}
			void SingingWaiter::Data() const
			{
				Singer::Data();
				Waiter::Data();
			}
			void SingingWaiter::Show() const
			{
				cout << "����: ���� �� ������\n";
				Worker::Data();
				Data();
			}

*/