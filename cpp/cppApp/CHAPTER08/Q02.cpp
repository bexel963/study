#include <iostream>
#include <cstring>

using namespace std;


struct CandyBar
{
	char* name;
	double weight;
	int calorie;
};

void setting(CandyBar&, const char* name="Millenuim Munch", double w=2.85, int c=350);
void print(CandyBar&);

int main()
{
	CandyBar candy;	

	setting(candy);
	print(candy);

	return 0;
}

void setting(CandyBar& candy, const char* name, double weight, int calorie)
{
	int len = strlen(name);
	candy.name = new char[len + 1];
	strcpy(candy.name, name);
	//candy.name[len] = '\0';
	
	candy.weight = weight;
	candy.calorie = calorie;
}

void print(CandyBar& candy)
{
	cout << "상표명: " << candy.name << endl;
	cout << "중량: " << candy.weight << endl;
	cout << "칼로리: " << candy.calorie << endl;
}

