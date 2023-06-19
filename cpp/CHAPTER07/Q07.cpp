#include <iostream>

const int Max = 5;
double* fill_array(double*, double*);
void show_array(const double*, double*);
void revalue(double, double*, double*);

int main()
{
	using namespace std;
	double properties[Max];

	double* lastAddr = fill_array(properties, properties+Max);

	show_array(properties, lastAddr-1);

	if ((lastAddr-1)-properties > 0)
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
		revalue(factor, properties, lastAddr - 1);
		show_array(properties, lastAddr - 1);
	}
	cout << "프로그램을 종료합니다.\n";
	cin.get();
	cin.get();

	return 0;
}

double* fill_array(double* ar, double* limit)
{
	using namespace std;
	double temp;
	int n = limit - ar;
	int i;
	for (i = 0; i < n; i++)
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
	return &ar[i+1];
}
void show_array(const double* ar, double* last)
{
	using namespace std;

	int n = last - ar;
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << "번 부동산: $";
		cout << ar[i] << endl;
	}
}
void revalue(double r, double* ar, double* last)
{
	int n = last - ar;
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}