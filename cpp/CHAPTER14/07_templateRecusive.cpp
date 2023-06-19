#include <iostream>
#include "arrayTemplate.h"

int main()
{
	using std::cout;
	using std::endl;
	ArrayTP<int, 10> sums;
	ArrayTP<double, 10> aves;
	ArrayTP<ArrayTP<int, 5>, 10> twodee;

	int i, j;
	for (i = 0; i < 10; i++)
	{
		sums[i] = 0;
		for (j = 0; j < 5; j++)
		{
			twodee[i][j] = (i + 1) * (j + 1);
			sums[i] += twodee[i][j];
		}
		aves[i] = (double)sums[i] / 10;
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout.width(2);	// ������ ����� �� �� ū ���� �ʿ� ���ٸ�, �� ���� �׸��� ������ 2�� ũ���� �ʵ� ������ ��µǵ��� �����.
			cout << twodee[i][j] << ' ';
		}
		cout << ": �հ� = ";
		cout.width(3);
		cout << sums[i] << ", ��� = " << aves[i] << endl;
	}

	cout << "���α׷��� �����մϴ�.\n";

	return 0;

}

/*
	- ���ø��� ����� ���
		ArrayTP < ArrayTP<int, 5>, 10 > twodee;
		: �̰��� twodee�� 10���� ���Ҹ� ���� �迭�� �����. �� �迭�� �� ���Ҵ� 5���� int������ �̷���� �迭�̴�.
		  ������ �迭�� ����ϴ� �̿� ������ ������ ������ ����.
				int twodee[10][5];
		  ���ø��� ����ϴ� ������ ������ 2���� �迭�� ����ϴ� ������ ������ ��Ÿ���� ������ �ݴ��̴�.
*/