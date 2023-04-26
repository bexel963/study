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
	CandyBar* p = new CandyBar[3];

	p->brandName = "abc";
	(p + 1)->cal = 1.2;
	(p + 2)->weight = 3.3;

	cout << p->brandName << endl;
	cout << (p + 1)->cal << endl;
	cout << (p + 1)->weight << endl;
	cout << (p + 2)->weight << endl;
	cout << p[2].weight << endl;

	return 0;
}