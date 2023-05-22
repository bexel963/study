#include <iostream>

using namespace std;

const float Level1 = 5000;
const float Level2 = 10000;
const float Level3 = 20000;
const float Level4 = 35000;
const float Level2_rate = 0.1;
const float Level3_rate = 0.15;
const float Level4_rate = 0.2;

int main()
{
	float income;
	float tax = 0;

	cout << "�ҵ� �Է�(�������� ���� �Է�): ";
	while ((cin >> income) && income > 0)
	{
		if (income >= Level1)
		{
			income -= Level1;
		}
		else
		{
			cout << "����: 0��" << endl;
			cout << "�ҵ� �Է�(�������� ���� �Է�): ";
			continue;
		}

		if (income >= Level2)
		{
			tax += Level2 * Level2_rate;
			income -= Level2;
		}
		else
		{
			tax += income * Level2_rate;
			cout << "����: " << tax << "��" << endl;
			tax = 0;
			cout << "�ҵ� �Է�(�������� ���� �Է�): ";
			continue;
		}
			
		if (income >= Level3)
		{
			tax += Level3 * Level3_rate;
			income -= Level3;
			if (income > 0)
				tax += income * Level4_rate;
		}
		else
		{
			tax += income * Level3_rate;
			cout << "����: " << tax << "��" << endl;
			tax = 0;
			cout << "�ҵ� �Է�(�������� ���� �Է�): ";
			continue;
		}

		cout << "����: " << tax << "��" << endl;
		tax = 0;
		cout << "�ҵ� �Է�(�������� ���� �Է�): ";
	}

	return 0;
	
	
	
	
}