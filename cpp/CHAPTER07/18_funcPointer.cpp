#include <iostream>

double gildong(int);
double moonsoo(int);
void estimate(int, double (*)(int));

int main()
{
	using namespace std;
	int code;

	cout << "�ʿ��� �ڵ��� �� ���� �Է��Ͻʽÿ�: ";
	cin >> code;
	cout << "ȫ�浿�� �ð� ����: \n";
	estimate(code, gildong);
	cout << "�ڹ����� �ð� ����:\n";
	estimate(code, moonsoo);

	return 0;
}

double gildong(int lns)
{
	return 0.05 * lns;
}

double moonsoo(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;
	cout << lines << "���� �ۼ��ϴµ� " << (*pf)(lines) << "�ð��� �ɸ��ϴ�.\n";
}

/*
	- �Լ��� �ּҴ� �� �Լ��� �ش��ϴ� ���� �ڵ尡 ����Ǿ� �ִ� �޸� ����� ���� �ּ��̴�.
	- �ٸ� �Լ��� �ּҸ� �Ű������� ���ϴ� �Լ��� �ۼ��� �� �ִ�.
	- think()�� �Լ���� think�� �� �Լ��� �ּ��̴�.
	- �Լ��� �Ű������� �����Ϸ��� �Լ� �̸��� �����ϸ� �ȴ�.
	- � ���������� �����ϴ� �����͸� �����Ϸ���, �� �����Ͱ� ��Ȯ�ϰ� � ���������� �����ϴ��� ���𿡼� ��Ȯ�ϰ� �����ؾ� �Ѵ�.
	  ����������, �Լ��� �����ϴ� �����͸� ������ ������, �� �����Ͱ� �����ϴ� �Լ��� ���������� �����ؾ� �Ѵ�.
	  �̰��� ������ ������ �Լ��� �������� �Լ��� �ñ׳�ü(�Ű����� ����Ʈ)�� �˷� �־�� �Ѵٴ� ���� �ǹ��Ѵ�.

		double pam(int n);	// �Լ� ����
		double (*pf)(int);	// �Լ� ������ ����
		pf = pam;

		double x = pam(4);
		double y = (*pf)(4);
		double z = pf(4);
*/