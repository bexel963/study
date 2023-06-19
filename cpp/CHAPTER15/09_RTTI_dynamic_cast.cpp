/*
	- RTTI (runtime type identification)(���� �ð� �������� ����)
		: ���α׷��� ���� ���߿� ��ü�� ���������� �����ϴ� ǥ�� ����� �����ϴ� ���̴�.

	- RTTI�� ����
		: �ϳ��� ���� ���� Ŭ�����κ��� ��ӵ� Ŭ���� ������ �ִٰ� ��������. �� Ŭ���� ������ ���� �ִ� Ŭ�������� � ��ü�� 
		  ���� Ŭ���� �����Ͱ� �����ϵ��� ������ �� �ִ�.
		  �� ������, � ������ ó���� �� �̵� Ŭ������ �� ��� �ϳ��� �����ϰ�, �� Ŭ�������� �� ��ü�� �����ϰ�, ���� Ŭ���� �����Ϳ�
		  �����ϱ� ���� �� ��ü�� �ּҸ� �����ϴ� �Լ��� ȣ���Ѵ�.
		  �� ��, �� �����Ͱ� �����ϴ� ��ü�� ������ �������� ��� �� �� ������....
		  (�� ���������� �˰� ���� ������ � Ŭ���� �޼����� ��Ȯ�� ������ ȣ���ϰ� �ͱ� �����̴�...)

	- RTTI�� ���� ���
		: C++�� RTTI�� �����ϴ� �� ���� ��Ҹ� ������ �ִ�.

			1) dynamic_cast
				-> ���� Ŭ�������� �����ϴ� �����ͷκ��� �Ļ� Ŭ�������� �����ϴ� �����͸� �����Ѵ�.
				   �������� �ʴٸ�, �� �������� 0�� �����Ѵ�.

			2) typeid ������
				-> � ��ü�� ��Ȯ�� ���������� �ĺ��ϴ� �ϳ��� ���� �����Ѵ�.

			3) type_info ����ü
				-> � Ư���� ���������� ���� ������ �����Ѵ�.

		: RTTI�� ���� �Լ����� ������ �ִ� Ŭ���� ������ ���ؼ��� ����� �� �ִ�. �� ������, �׵��� �Ļ� ��ü���� �ּҸ� ���� Ŭ���� �����͵鿡 �����ؾ�
		  �ϴ� ������ Ŭ���� �����̱� �����̴�.

	- �������� ��ȯ�� �������� ����� ����, � ������ ��ü�� �����ϴ��� ����� �ͺ��� �� �Ϲ����̰� �� �����ϴ�.
	  ���������� �˷��� �ϴ� �Ϲ����� ������, � Ư���� �޼��带 ȣ���ϴ� ���� �������� �˱� ���� ���̴�.
	  � �޼��带 ȣ���ϴ� �� ��Ȯ�� �������� ��ġ�� �ݵ�� �ʿ��� ���� �ƴϴ�.
	  �� �޼����� ���� ������ ���� ���ǵ� ���� ���������� �� ���������� �� �� �ִ�.

				class Grand { //����޼����... };
				class Superb : public Grand { ... };
				class Magnificent : public Superb { ... };

				Grand* pg = new Grand;
				Grand* ps = new Superb;
				Grand* pm = new Magnificent;

				Magnificent* p1 = (Magnificent*)pm;	// ����
				Magnificent* p2 = (Magnificent*)pg;	// ����X
				Superb* p3 = (Magnificent*)pm;		// ����

				=> public �Ļ��� Magnificent ��ü�� Superb ��ü(���� ����)�̰�, Grand ��ü(���� ����)�̱⵵ �ϴٴ� ���� �����Ѵ�.
*/

/*
	- dynamic_cast ������
		: �̰��� �����Ͱ� �����ϴ� ��ü���� �������� �˷� ���� �ʴ´�. �� ��ſ� �� ��ü�� �ּҸ� Ư������ �����Ϳ� �����ϰ� ������ �� �ִ��� �˷� �ش�.

				Superb* pm = dynamic_cast<Superb*>(pg);

		: �� �ڵ�� ������ pg�� Superb* ������ �����ϰ� ��ȯ�� �� �ִ��� �ǹ��� �����Ѵ�.
	      ��ȯ�� �� �ִٸ�, �� �����ڴ� �� ��ü�� �ּҸ� �����Ѵ�. ��ȯ�� �� ���ٸ�, �� �������� 0�� �����Ѵ�.

				dynamic_cast<Type*>(pt)

		: ������ pt�� ���� ���õǴ� ��ü(*pt)�� Type���̰ų�, Type�����κ��� ���� �Ǵ� ���������� �Ļ��� ��ü�� ��쿡, ������ pt�� Type* ���� �����ͷ� ��ȯ�Ѵ�.
		  �׷��� ���� ��쿡, �� ǥ���� �� �������� 0���� �򰡵ȴ�.						
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;

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
	std::srand(std::time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = getOne();
		pg->speak();
		if (ps = dynamic_cast<Superb*>(pg))	// pg�� ����Ű�� ��ü�� Superb�� �Ǵ� Magnificent�� �� �� ��� �ϳ��� �� ���̵ȴ�.
			ps->say();
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
	- dynamic_cast�� ������ �Բ� ����� ���� �ִ�. 
	  �� ���������� �ش��ϴ� �������� �������� �ʱ� ������, ���и� ��Ÿ���� �� ����� �� �ִ� Ư���� �������� ����.
	  �� ��ſ� �������� ��û�� ���õ� ��, dynamic_cast�� bad_cast���� ���ܸ� �߻���Ų��.
	  �� ���ܴ�, exception Ŭ�����κ��� �Ļ��� ���̸�, typeinfo ��� ���Ͽ� ���ǵǾ� �ִ�.

				#include <typeinfo>
				...
				try
				{
					Superb& rs = dynamic_cast<Superb&>(rg);
					...
				}
				catch(bad_cast&)
				{
					...
				};
*/