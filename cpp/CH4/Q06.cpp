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
	CandyBar snacks[3] = {
		{ "abc", 0.1f, 10 },
		{ "def", 0.2f, 20 },
		{ "ghi", 0.3f, 30 }
	};

	for (int i = 0; i < 3; i++)
	{
		cout << "��ǥ��: " << snacks[i].brandName << ", �߷�: " << snacks[i].weight << ", Į�θ�: " << snacks[i].cal << endl;
	}

	return 0;
}