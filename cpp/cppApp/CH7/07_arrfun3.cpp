#include <iostream>

const int Max = 5;
int fill_array(double[], int);
void show_array(const double[], int);
void revalue(double, double[], int);

int main()
{
	using namespace std;
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);

	if (size > 0)
	{
		cout << "재평가율을 입력하시오: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "잘못 입력했습니다. 수치를 입력하세오: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "프로그램을 종료합니다.\n";
	cin.get();
	cin.get();

	return 0;
}

int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << (i + 1) << "번 부동산의 가격: ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "입력 불량, 입력 과정을 끝내겠습니다.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}
void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << "번 부동산: $";
		cout << ar[i] << endl;
	}
}
void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}