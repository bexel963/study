/*
	- C++�� ���ÿ� ������ �÷� �θ鼭 �Լ� ȣ����� ó���Ѵ�.
	  ���α׷���, ȣ���� �Լ� ������ �ּҸ� ���ÿ� �÷� ���´�.
	  ȣ��� �Լ��� ������ ������, ���α׷��� ���ÿ� �÷� ���� �� �ּҸ� ����Ͽ� ���α׷� ������ ����� ��Ҹ� �����Ѵ�.
	  �Լ� ȣ����, �ڵ� ������ ��޵Ǵ� �Լ� �Ű��������� ���ÿ� �÷� ���´�.
	  ȣ��� �Լ��� ���ο� �ڵ� ������ �����ϸ� �װ͵� ���ÿ� �߰��ȴ�.
	  � �Լ��� ����Ǹ�, ���α׷� ������ �� �Լ��� ȣ��� �� ���ÿ� ������ �� �ּҷ� �Ѿ��, ������ ����Ⱑ �����ȴ�.
	  �׷��� �Ͽ� �� �Լ��� �װ��� ȣ���� �Լ����Է� ���ư���.
	  �� �Լ��� ������ �� �ڽ��� �ڵ� �������� �����Ѵ�.
	  �ڵ� ������ Ŭ���� ��ü�� ��쿡 Ŭ���� �ı��ڰ� ȣ��ȴ�.

	- ���α׷��� ���ܸ� ���� ����� ������ ���ÿ��� �޸𸮸� �����Ѵ�.
	  �׷��� ���ÿ��� ������ ù ��° ���� �ּҿ��� ������ �ʰ�, try ��Ͽ� ��� �ִ� ���� �ּҿ� ������ �� ���� ����ؼ� ������ �����Ѵ�.
	  �� �� ����� �Լ� ȣ�� �ڿ� ���� ù ��° ������ �ƴ϶�, try ����� ���� �̾����� ���� �ڵ鷯�� �Ѿ��. (���� Ǯ��)

	- return ������ �� �Լ��� ���ÿ� �÷� ���� ��ü�鸸 ó���Ѵ�. �׷��� throw ������ try ��ϰ� �� throw ���� ���̿� ���Ե� �Լ� ȣ�����
	  ��ü���� ���Ⱑ ���ÿ� �÷� ���� ��ü���� ��� ó���Ѵ�.
*/

#include <iostream>
#include <cmath>
#include <string>
#include "exceptionObj.h"

class demo
{
private:
	std::string word;
public:
	demo(const std::string& str)
	{
		word = str;
		std::cout << "demo " << word << " ����\n";
	}
	~demo()
	{
		std::cout << "demo " << word << " �ı�\n";
	}
	void show() const
	{
		std::cout << "demo " << word << " ����\n";
	}
};

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
double means(double a, double b) throw(bad_hmean, bad_gmean);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	{
		demo d1("found in block in main()");
		cout << "�� ���� �Է��Ͻʽÿ�: ";
		while (cin >> x >> y)
		{
			try {
				z = means(x, y);
				cout << x << "�� " << y << "�� ����� ����� " << z << endl;
				cout << "���� �� ���� �Է��Ͻʽÿ�: ";
			}
			catch (bad_hmean& bg)
			{
				bg.mesg();
				cout << "�ٽ� �Ͻʽÿ�.\n";
				continue;
			}
			catch (bad_gmean& hg)
			{
				cout << hg.mesg();
				cout << "���� �� ��: " << hg.v1 << ", " << hg.v2 << endl;
				cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
				break;
			}
		}
		d1.show();
	}

	cout << "���α׷��� �����մϴ�.\n";
	cin.get();
	cin.get();

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);

	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);

	return std::sqrt(a * b);
}

double means(double a, double b)
{
	double am, hm, gm;
	demo d2("found in means()");
	am = (a + b) / 2.0;		// ��� ���
	try
	{
		hm = hmean(a, b);	// ��ȭ ���
		gm = gmean(a, b);	// ���� ���
	}
	catch (bad_hmean& bg)				// bg�� ��ü�� ���纻�� �����Ѵ�. hmean()�� ����� �Ŀ� bad_hmean�� �� �̻� �������� �ʱ� �����̴�.
	{
		bg.mesg();
		std::cout << "means()���� ����\n";
		throw;
	}
	d2.show();

	return (am + hm + gm) / 3.0;
}

/*
	- ���α׷��� ���ܰ� ������ ������ �����ϱ� ���� ������ Ǯ ��, ���α׷��� ���ÿ� �ִ� �ڵ� ������ �������� �����Ѵ�.
	  � ������ Ŭ���� ��ü�� ��쿡�� �� ��ü�� ���� �ı��ڰ� ȣ��ȴ�.

	- gmean()�� bad_gmean ���ܸ� �߻���Ű��. means()�� bad_gmean ���ܸ� ���� �ʱ� ������, �� ���ܴ� main()�� ���� ���޵ȴ�.
	  �׸��� means()�� �ִ� ������ �ڵ�� �� �̻� ������� �ʴ´�. �׷��� �ٽ� �� ��, ���α׷��� ������ Ǯ ��, ���α׷���
	  �ڵ� ���� �������� �����Ѵ�. �׷��� d2�� ���� �ı��ڰ� ȣ��ȴ�.
*/

/*
	- �Լ��� ���ܸ� �߻���Ű���� �� �� (�� ���������� �� ��) � ���ܶ� �����ϴ� ����� ���� ���������� ���� ���� ��ȣ ...�� ����ϴ� ���̴�.
				catch (...)
				{
					// ������
				}
*/