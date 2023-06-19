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

	cout << "상표명: " << snack.brandName << ", 중량: " << snack.weight << ", 칼로리: " << snack.cal << endl;

	return 0;
}