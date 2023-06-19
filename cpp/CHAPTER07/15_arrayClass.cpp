#include <iostream>
#include <array>
#include <string>

const int Seasons = 4;
const std::array<std::string, Seasons> Sname = { "Spring", "Summer", "Fall", "Winter" };

void fill(std::array<double, Seasons>* pa);
void show(std::array<double, Seasons> da);

int main()
{
	std::array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);

	return 0;
}

void fill(std::array<double, Seasons>* pa)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << "에 소요되는 비용: ";
		cin >> (*pa)[i];
		// pa는 array<double, 4>객체에 대한 포인터이기 때문에 *pa는 객체이다.
		// 그리고 (*pa)[i]는 그 객체에 있는 원소이다.
		// 괄호는 연산자 우선순위 때문에 필요하다.
	}
}

void show(std::array<double, Seasons> da)
{
	using namespace std;
	double total = 0.0;
	cout << "\n계절별 비용\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Sname[i] << " : $" << da[i] << endl;
		total += da[i];
	}

	cout << "총 비용: $" << total << endl;
}