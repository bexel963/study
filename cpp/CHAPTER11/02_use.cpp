#include <iostream>
#include <cstdlib>		// rand(), srand()�� ����
#include <ctime>		// time()�� ����
#include "vect.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	while (cin >> target)
	{
		cout << "������ �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep))
			break;
		
		while (result.magVal() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << steps << " ������ ���� �� ������ ���� ��ġ:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " �Ǵ�\n" << result << endl;
		cout << "������ ��տ��� ��� ��� �Ÿ� = "
			<< result.magVal() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "��ǥ �ܸ��� �Է��Ͻʽÿ�(�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}

/*
	- rand()
		: 0�������� ���� �ý��ۿ� ���� �ٸ� � Ư�� ���� ������ ���ϴ� �ϳ��� ������ ������ ����
		: �ʱ� ���Ѱ��� � �˰����� �����Ͽ� �ϳ��� ������ ���� ��´�.
		  �� ������ ���� �ٽ� ���� �� �Լ� ȣ�⿡ ���Ѱ����� ���Ǿ� ������ ���� ������ �����.
	- srand()
		: ����Ʈ ���Ѱ��� �����ϰ� �ٸ� ���� ������ �߻���ų �� �ִ�.
	- time(0)
		: Ư�� �����Ϸκ��� ����� ������ �޷� �ð��� �� ���� ���� �����Ѵ�.
	- srand(time(0))
		: ���α׷��� ������ ������ �ٸ� ���Ѱ��� �����Ѵ�.
*/