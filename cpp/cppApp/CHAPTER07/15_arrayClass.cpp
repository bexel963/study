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
		cout << Sname[i] << "�� �ҿ�Ǵ� ���: ";
		cin >> (*pa)[i];
		// pa�� array<double, 4>��ü�� ���� �������̱� ������ *pa�� ��ü�̴�.
		// �׸��� (*pa)[i]�� �� ��ü�� �ִ� �����̴�.
		// ��ȣ�� ������ �켱���� ������ �ʿ��ϴ�.
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

	cout << "�� ���: $" << total << endl;
}