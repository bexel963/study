#include <iostream>

const int Cities = 5;
const int Years = 4;

int main()
{
	using namespace std;
	const char* cities[Cities] =
	{
		"Seoul",
		"Jeju",
		"Busan",
		"Gangneung",
		"Daegu"
	};

	int maxtemps[Years][Cities] =
	{
		{35, 32, 33, 36, 35},
		{33, 32, 34, 35, 31},
		{33, 34, 32, 35, 34},
		{36, 35, 34, 37, 35}
	};
	
	cout << "2009년부터 2012년까지의 연중 최고 온도\n\n";
	for (int city = 0; city < Cities; ++city)
	{
		if(city==3)
			cout << cities[city] << ":\t";
		else
			cout << cities[city] << ":\t\t";
		for (int year = 0; year < Years; ++year)
			cout << maxtemps[year][city] << "\t";
		cout << endl;
	}

	return 0;
}