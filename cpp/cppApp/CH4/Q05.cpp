#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
	string brandName;
	float weight;
	int cal;
};
int main()
{
	CandyBar snack =
	{
		"Mocha Munch", 2.3, 350
	};

	cout << "��ǥ��: " << snack.brandName << ", �߷�: " << snack.weight << ", Į�θ�: " << snack.cal << endl;

	return 0;
}