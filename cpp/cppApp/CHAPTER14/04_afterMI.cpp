#include "afterMI.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Worker 메서드들
Worker::~Worker() { }	// 순수 함수일지라도 가상 파괴자를 구현해야 한다.

// protected 메서드들
void Worker::Data() const
{
	cout << "사원 이름: " << fullname << endl;
	cout << "사원 번호: " << id << endl;
}
void Worker::Get()
{
	getline(cin, fullname);
	cout << "사원번호를 입력하십시오: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}


// Waiter 메서드들
void Waiter::Set()
{
	cout << "웨이터의 이름을 입력하십시오: ";
	Worker::Get();
	Get();
}
void Waiter::Show() const
{
	cout << "직종: 웨이터\n";
	Worker::Data();
	Data();
}
// protected 메서드들
void Waiter::Data() const
{
	cout << "웨이터 등급: " << panache << endl;
}
void Waiter::Get()
{
	cout << "웨이터 등급을 입력하십시오: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

// Singer 메서드들
char* Singer::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	cout << "가수의 이름을 입력하십시오: ";
	Worker::Get();
	Get();
}
void Singer::Show() const
{
	cout << "직종: 가수\n";
	Worker::Data();
	Data();
}

// protected 메서드들
void Singer::Data() const
{
	cout << "목소리 유형: " << pv[voice] << endl;
}
void Singer::Get()
{	
	cout << "가수의 목소리 유형 번호를 입력하십시오::\n";
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
		cout << "0보다 크거나 같고 " << Vtypes << "보다 작은 값을 입력하십시오." << endl;

	while (cin.get() != '\n')
		continue;
}

// SingingWaiter 메서드들
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
	cout << "가수 겸 웨이터의 이름을 입력하십시오: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show() const
{
	cout << "직종: 가수 겸 웨이터\n";
	Worker::Data();
	Data();
}

/*
			SingingWaiter newhire("Madonna", 2005, 6, soprano);
			newhire.Show(); => 모호하다.
	
	- 단일 상속에서는 Show()를 다시 정의하지 않으면 가장 가까운 조상의 정의가 사용된다.
	  이 경우, 직계의 인접한 조상이 Show() 함수를 각각 하나씩 가지고 있고 이것이 호출을 모호하게 만든다.
	  ->
			SingingWaiter newhire("Madonna", 2005, 6, soprano);
			newhire.Singer::Show();	=> 사용 범위 결정 연산자를 사용하면 어느 것을 말하는지 확실하게 할 수 있다.

	- 더 나은 방법 중, 파생 메서드가 기초 메서드를 호출하게 하는 방법은, 단일 상속에서는 잘 동작한다.

			void Worker::Show() const
			{
				cout << "사원 이름: " << fullname << "\n";
				cout << "사원 번호: " << id << "\n";
			}
			void Waiter::Show() const
			{
				Worker::Show();
				cout << "웨이터 등급: " << panache << "\n";
			}
			void HeadWaiter::Show() const
			{
				Waiter::Show();
				cout << "외모 등급: " << presence << "\n";
			}

	- 위와 같은 점층적 접근 방식은 SingerWaiter에 대해서는 실패한다.

			void SingingWaiter::Show()
			{
				Singer::Show();
			}
	  Waiter 성분을 무시하기 때문에 실패한다. Waiter 버전도 함께 호출함으로써 그 것을 해결할 수는 있다.
			void SingingWaiter::Show()
			{
				Singer::Show();
				Waiter::Show();
			}
	  그러나 이것은, 사원 이름과 사원 번호를 두 번 표시하게 만든다.
*/

/*
	- 점층적 접근 방식 대신에 모듈 접근 방식을 사용하는 방법이 있다.
	  즉, 각 성분을 따로 출력하는 메서드를 각각 제공한 후, SingingWaiter::Show()에서 그 성분들을 결합하는 것이다.

			void Worker::Data() const
			{
				cout << "사원 이름: " << fullname << "\n";
				cout << "사원 번호: " << id << "\n";
			}
			void Waiter::Data() const
			{
				cout << "웨이터 등급: " << panache << endl;
			}
			void Singer::Data() const
			{
				cout << "목소리 유형: " << pv[voice] << endl;
			}
			void SingingWaiter::Data() const
			{
				Singer::Data();
				Waiter::Data();
			}
			void SingingWaiter::Show() const
			{
				cout << "직종: 가수 겸 웨이터\n";
				Worker::Data();
				Data();
			}

*/