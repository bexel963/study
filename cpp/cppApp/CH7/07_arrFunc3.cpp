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
			/*
				- cin이 조건 검사에 사용될 때에는 입력의 성공 여부에 따라 true 또는 false의 bool값으로 변환된다.
				- 'q' 를 입력하면 cin >> 은 'q'가 수가 아니라고 인식한다.
				  그래서 'q'를 입력 큐에 그대로 남겨 두고, false로 변환된 값을 리턴하여 루프를 종결시킨다.
				- 프로그램이 입력 루프에 이어서 다시 입력을 받아들일 필요가 있다면, cin.clear()를 사용하여 입력 가능 상태로 설정하고,
				  새로운 입력을 방해하는 불량 입력('q')를 제거해야 한다.
			*/
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