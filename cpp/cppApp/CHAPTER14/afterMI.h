#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

class Worker
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
	/*
		- Data() 를 private으로 만들면 Waiter 코드가 Worker::Data()를 사용하지 못하게 막는다.
		  그러나 protected로 만들면, 그 계열에 속한 모든 클래스들이 내부적으로 그것을 사용할 수 있으면서도
		  바깥 세계로부터는 은닉시킬 수 있다.
	*/

public:
	Worker() : fullname("no name"), id(0L) { }
	Worker(const std::string& s, long n) : fullname(s), id(n) { }

	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) { }
	Waiter(const std::string& s, long n, int p = 0) : Worker(s, n), panache(p) { }
	Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) { }
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();
private:
	static char* pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other) { }
	Singer(const std::string& s, long n, int v = other) : Worker(s, n), voice(v) { }
	Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) { }
	void Set();
	void Show() const;
};

// 다중 상속
class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter() { }
	SingingWaiter(const std::string& s, long n, int p = 0, int v = other)
		: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) { }
	SingingWaiter(const Worker& wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk, p), Singer(wk, v) { }
	SingingWaiter(const Waiter& wt, int v = other)
		: Worker(wt), Waiter(wt), Singer(wt, v) { }
	SingingWaiter(const Singer& wt, int p = 0)
		: Worker(wt), Waiter(wt, p), Singer(wt) { }
	void Set();
	void Show() const;

};
#endif


/*
	- 다중 상속은 기초 클래스 포인터들의 배열을 사용하여 다양한 종류의 객체를 참조하는 기법(다형)을 어렵게 만든다.	  
			SingingWaiter ed;
			Worker* pw = &ed;	// 모호하다.
	  이와 같은 대입은 기초 클래스 포인터를 파생 객체 안에 있는 기초 클래스 객체의 주소로 설정한다.
	  그러나 여기서 ed는 두 개의 Worker 객체를 내포하고 있다. 그래서 선택할 수 있는 주소가 두 개이다.
	  강제 데이터형 변환을 사용하여 어느 객체를 말하는지 지정할 수 있다.
			Worker* pw1 = (Waiter*)&ed;
			Worker* pw1 = (Singer*)&ed;
*/

/*
	class Singer : public Worker {...};
	class Waiter : public Waiter {...};
	class SingingWaiter : public Worker, public Waiter {...};

		- SingingWaiter 객체는 두 개의 Worker 객체를 상속한다.
*/

/*
	class Singer : virtual public Worker {...};
	class Waiter : virtual public Waiter {...};
	class SingingWaiter : public Worker, public Waiter {...};

		- SingingWaiter 객체는 Worker 객체의 복사본 하나만 내포한다.
		  본질적으로 이것은, 상속된 Singer 객체와 Waiter 객체가 복사본을 각각 하나씩 갖는 대신에 하나의 Worker 객체를 공유한다.

		- 가상 기초 클래스는, 하나의 공통 조상을 공유하는 여러 개의 기초 클래스로부터 공통 조상의 유일 객체를 상속하는 방식으로,
		  객체를 파생시키는 것을 허용한다.
*/

/*
	- 가상 메서드, 가상 기초 클래스는 서로 관련이 없고 단지, virtual 오버로딩이다.
	- 가상 기초 클래스가 작동되게 하려면, C++ 규칙을 몇 가지 조정할 필요가 있다.
	
				class A
				{
					int a;
				public:
					A(int n=0) { a = n; }
					...
				};
				
				class B : public A
				{
					int b;
				public:
					B(int m=0, int n=0) : A(n) { b = m; }
					...
				};

				class C : public B
				{
					int c;
				public:
					C(int q=0, int m=0, int n=0) : B(m,n) { c = q; }
					...
				};

	  C 생성자는 m, n값을 B 생성자에게 전달하고, B 생성자는 n값을 A 생성자에 전달한다.
	  이와 같은 정보의 자동 전달은, Worker가 가상 기초 클래스일 때에는 동작하지 않는다.

				SingingWaiter(const Worker& wk, int p=0, int v=Singer::other) : Waiter(wk, p), Singer(wk, v) { }	// 결함이 있다.

	  위 코드에서 문제는, 정보의 자동 전달에 의해 wk가 서로 다른 두 경로(Waiter, Singer)를 거쳐 Worker 객체에 전달된다는 것이다.
	  이와 같은 잠재적인 충돌을 피하기 위해, 기초 클래스가 가상일 경우에 C++는 중간 클래스를 통해 기초 클래스에 자동으로 정보를 전달하는 기능을 정지시킨다.
	  그러므로 위 생성자는 panache와 voice 멤버는 초기화하지만, wk 매개변수에 있는 정보는 Waiter 종속 객체에 전달되지 않는다.
	  그러나 컴파일러는 파생 객체들을 생성하기 전에 기초 객체 성분을 생성해서 이 경우에는, 디폴트 Worker 생성자를 사용하게 된다.
	  가상 기초 클래스를 위해 디폴트 생성자가 아닌 것을 사용하기를 원한다면, 적절한 기초 생성자를 명시적으로 호출해야 한다.

				SingingWaiter(const Worker& wk, int p=0, int v=Singer::other) : Worker(wk), Waiter(wk, p), Singer(wk, v) { }

	  위 코드는 Worker(const Worker&) 생성자를 명시적으로 호출한다.
*/