#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const char* Sname[Seasons] = { "Spring", "Summer", "Fall", "Winter" };

void fill(std::array<double, Seasons>* pa);
void fill(double*);
void show(std::array<double, Seasons> da);
void show(double*);

struct Expenses
{
	double arr[Seasons];
};
int main()
{
	std::array<double, Seasons> expenses;
	Expenses exp;

	//fill(&expenses);
	fill(exp.arr);
	//show(expenses);
	show(exp.arr);

	return 0;
}

void fill(std::array<double, Seasons>* pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << "�� �ҿ�Ǵ� ���: ";
		cin >> (*pa)[i];
	}
}
void fill(double* pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << "�� �ҿ�Ǵ� ���: ";
		cin >> pa[i];
	}
}
void show(std::array<double, Seasons> da)
{
	using namespace std;
	double total = 0.0;
	cout << "\n������ ���\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << " : $" << da[i] << endl;
		total += da[i];
	}

	cout << "\n�� ���: $" << total << endl;
}
void show(double* da)
{
	using namespace std;
	double total = 0.0;
	cout << "\n������ ���\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << ": $" << da[i] << endl;
		total += da[i];
	}

	cout << "\n�� ���: $" << total << endl;
}