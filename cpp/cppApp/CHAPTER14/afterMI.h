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
		- Data() �� private���� ����� Waiter �ڵ尡 Worker::Data()�� ������� ���ϰ� ���´�.
		  �׷��� protected�� �����, �� �迭�� ���� ��� Ŭ�������� ���������� �װ��� ����� �� �����鼭��
		  �ٱ� ����κ��ʹ� ���н�ų �� �ִ�.
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

// ���� ���
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
	- ���� ����� ���� Ŭ���� �����͵��� �迭�� ����Ͽ� �پ��� ������ ��ü�� �����ϴ� ���(����)�� ��ư� �����.	  
			SingingWaiter ed;
			Worker* pw = &ed;	// ��ȣ�ϴ�.
	  �̿� ���� ������ ���� Ŭ���� �����͸� �Ļ� ��ü �ȿ� �ִ� ���� Ŭ���� ��ü�� �ּҷ� �����Ѵ�.
	  �׷��� ���⼭ ed�� �� ���� Worker ��ü�� �����ϰ� �ִ�. �׷��� ������ �� �ִ� �ּҰ� �� ���̴�.
	  ���� �������� ��ȯ�� ����Ͽ� ��� ��ü�� ���ϴ��� ������ �� �ִ�.
			Worker* pw1 = (Waiter*)&ed;
			Worker* pw1 = (Singer*)&ed;
*/

/*
	class Singer : public Worker {...};
	class Waiter : public Waiter {...};
	class SingingWaiter : public Worker, public Waiter {...};

		- SingingWaiter ��ü�� �� ���� Worker ��ü�� ����Ѵ�.
*/

/*
	class Singer : virtual public Worker {...};
	class Waiter : virtual public Waiter {...};
	class SingingWaiter : public Worker, public Waiter {...};

		- SingingWaiter ��ü�� Worker ��ü�� ���纻 �ϳ��� �����Ѵ�.
		  ���������� �̰���, ��ӵ� Singer ��ü�� Waiter ��ü�� ���纻�� ���� �ϳ��� ���� ��ſ� �ϳ��� Worker ��ü�� �����Ѵ�.

		- ���� ���� Ŭ������, �ϳ��� ���� ������ �����ϴ� ���� ���� ���� Ŭ�����κ��� ���� ������ ���� ��ü�� ����ϴ� �������,
		  ��ü�� �Ļ���Ű�� ���� ����Ѵ�.
*/

/*
	- ���� �޼���, ���� ���� Ŭ������ ���� ������ ���� ����, virtual �����ε��̴�.
	- ���� ���� Ŭ������ �۵��ǰ� �Ϸ���, C++ ��Ģ�� �� ���� ������ �ʿ䰡 �ִ�.
	
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

	  C �����ڴ� m, n���� B �����ڿ��� �����ϰ�, B �����ڴ� n���� A �����ڿ� �����Ѵ�.
	  �̿� ���� ������ �ڵ� ������, Worker�� ���� ���� Ŭ������ ������ �������� �ʴ´�.

				SingingWaiter(const Worker& wk, int p=0, int v=Singer::other) : Waiter(wk, p), Singer(wk, v) { }	// ������ �ִ�.

	  �� �ڵ忡�� ������, ������ �ڵ� ���޿� ���� wk�� ���� �ٸ� �� ���(Waiter, Singer)�� ���� Worker ��ü�� ���޵ȴٴ� ���̴�.
	  �̿� ���� �������� �浹�� ���ϱ� ����, ���� Ŭ������ ������ ��쿡 C++�� �߰� Ŭ������ ���� ���� Ŭ������ �ڵ����� ������ �����ϴ� ����� ������Ų��.
	  �׷��Ƿ� �� �����ڴ� panache�� voice ����� �ʱ�ȭ������, wk �Ű������� �ִ� ������ Waiter ���� ��ü�� ���޵��� �ʴ´�.
	  �׷��� �����Ϸ��� �Ļ� ��ü���� �����ϱ� ���� ���� ��ü ������ �����ؼ� �� ��쿡��, ����Ʈ Worker �����ڸ� ����ϰ� �ȴ�.
	  ���� ���� Ŭ������ ���� ����Ʈ �����ڰ� �ƴ� ���� ����ϱ⸦ ���Ѵٸ�, ������ ���� �����ڸ� ��������� ȣ���ؾ� �Ѵ�.

				SingingWaiter(const Worker& wk, int p=0, int v=Singer::other) : Worker(wk), Waiter(wk, p), Singer(wk, v) { }

	  �� �ڵ�� Worker(const Worker&) �����ڸ� ��������� ȣ���Ѵ�.
*/