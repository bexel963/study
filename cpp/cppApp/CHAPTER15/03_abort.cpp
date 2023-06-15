#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main()
{
	double x, y, z;

	std::cout << "�� ���� �Է��Ͻʽÿ�: ";
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << x << ", " << y << "�� ��ȭ����� " << z << "�Դϴ�.\n";
		std::cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
	}
	std::cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		std::cout << "�Ű��������� hmean()�� ������ �� �����ϴ�.\n";
		std::abort();
		// hmean()���� abort()�� ȣ���ϴ� ����, main() ���� �ٽ� ���ư��� �� ���� �� ���α׷��� ���� �����Ѵ�.
	}

	return 2.0 * a * b / (a + b);
}

/*
	- �� ���� ��ȭ����� �������� ����� ������ �����Ѵ�.
*/

/*
	- abort() �Լ��� ������ cstdlib ��� ���Ͽ� ��� �ִ�. �Ϲ������� abort()�� ȣ��Ǿ��� �� ǥ�� ���� ��Ʈ��(cerr�� ����ϴ� ��Ʈ��)�� 
	  "abnormal program temination" (���������� ���α׷� ����)�� ���� �޽����� ������ ���α׷��� �����Ű���� �����Ǿ� �ִ�.
	  ���� �� �Լ��� �� ���α׷��� �ٸ� ���α׷��� ���� �⵿�Ǿ��� ��쿡, �� ���α׷��� �⵿��Ų �θ� ���μ����� �ü���� �����Ϸ��� �������� � ���� �����Ѵ�.
*/