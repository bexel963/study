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
		cout << "상표명: " << snacks[i].brandName << ", 중량: " << snacks[i].weight << ", 칼로리: " << snacks[i].cal << endl;
	}

	return 0;
}