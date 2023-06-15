/*
	- typeid ������
		: �� �����ڸ� ����Ͽ� �� ��ü�� ���������� ������ Ȯ���� �� �ִ�.
		  sizeof�� ����ϰ�, typeid �����ڴ� �� ������ �Ű������� �޾Ƶ��δ�.
			1) Ŭ������ �̸�
			2) ��ü�� �򰡵Ǵ� ��
		: typeid �����ڴ� type_info ��ü�� ���� ������ �����Ѵ�.
		  type_info�� typeinfo ��� ���Ͽ� ���ǵǾ� �ִ� Ŭ�����̴�.
		: type_info Ŭ������ ���������� ���ϴ� �� ����� �� �ֵ��� ==�� != �����ڸ� �����ε� �Ѵ�.

				typeid(Magnificent) == typeid(*pg)

		: pg�� Magnificent ��ü�� �����ϴ� �������̸� true�� �򰡵ȴ�.
		  pg�� �� �����͸�, ���α׷��� bad_typeid ���ܸ� �߻���Ų��.
		  �� ���� ���������� exception Ŭ�����κ��� �Ļ��� ���̰�, typeinfo ��� ���Ͽ� ����Ǿ� �ִ�.
		: type_info Ŭ������ ������ ��ü���� �ٸ�����, �Ϲ������� Ŭ������ �̸���, �ý��ۿ� ���� ���ڿ��� �����ϴ� name() ����� �����Ѵ�.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
using namespace std;

class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) { }
	virtual void speak() const { cout << "���� Grand Ŭ�����̴�!\n"; }
	virtual int value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) { }
	void speak() const { cout << "���� Super Ŭ�����̴�.!\n"; }
	virtual void say() const { cout << "���� ������ �ִ� Superb ���� " << value() << "�̴�.\n"; }
};

class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) { }
	void speak() const { cout << "���� Magnificent Ŭ�����̴�.!!!\n"; }
	void say() const { cout << "���� ������ �ִ� ���ڴ� " << ch << "�̰�, ������ " << value() << "�̴�.\n"; }
};

Grand* getOne();

int main()
{
	srand(time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = getOne();
		cout << "���� " << typeid(*pg).name() << "���� ó���ϰ� �ֽ��ϴ�.\n";
		pg->speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->say();
		if (typeid(Magnificent) == typeid(*pg))
			cout << "�׷�, �ʾ߸��� ��¥ Magnificient Ŭ�����̴�.\n";
	}

	return 0;
}

Grand* getOne()
{
	Grand* p;
	switch (std::rand() % 3)
	{
	case 0:
		p = new Grand(std::rand() % 100);
		break;
	case 1:
		p = new Superb(std::rand() % 100);
		break;
	case 2:
		p = new Magnificent(std::rand() % 100, 'A' + std::rand() % 26);
		break;
	default:
		p = new Grand(std::rand() % 100);
	}

	return p;
}

/*
	- dynamic_cast�� ���� �Լ����� �����ϰ� �ۼ��� ��ȿ������ �ڵ�

				Grand* pg;
				Superb* ps;
				Magnificent* pm;
				for(int i=0 ; i<5 ; i++)
				{
					pg = getOne();
					if(typeid(Magnificent) == typeid(*pg))
					{
						pm = (Magnificent*)pg;
						pm->speak();
						pm->say();
					}
					else if(typeid(Superb) == typeid(*pg))
					{
						ps = (Superb*)pg;
						ps->speak();
						ps->say();
					else
						pg->speak();
				}
				
*/