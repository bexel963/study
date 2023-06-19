#include <iostream>

double hmean(double, double);

using namespace std;
int main()
{
	double x, y, z;

	cout << "�� ���� �Է��Ͻʽÿ�: ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "�� ���� ���� �Է��Ͻʽÿ�: ";
			continue;
		}
		cout << x << ", " << y << "�� ��ȭ����� " << z << "�Դϴ�.\n";
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "�߸��� hmean() �Ű�����: a = -b�� ������ �ʽ��ϴ�.\n";

	return 2.0 * a * b / (a + b);
}

/*
	- ���� �߻���, �װ��� �Լ� ������ �����Ų�ٴ� ������ ���� ������ ����� ����ϴ�.
	  �׷��� ���� �߻���, ȣ���� ���α׷��� ��� �ѱ��� �ʰ�, �� try����� ���ԵǾ� �ִ� �Լ��� �߰��� ������ 
	  ���� ȣ���� �Լ����� ���⸦ �Ž��� �ö󰣴�.

	- � �Լ��� ���ܸ� �߻���Ű�µ� try ����� ���ų� ���������� ��ġ�ϴ� ���� �ڵ鷯�� ���ٸ�
	  ���α׷��� �⺻������ abort()�Լ��� ȣ���Ѵ�.
*/