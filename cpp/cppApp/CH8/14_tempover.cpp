#include <iostream>

template<typename T>
void ShowArray(T[], int);

template<typename T>
void ShowArray(T* [], int);


struct debts
{
	char name[50];
	double amount;
};

int main(void)
{
	using namespace std;
	int things[6] = { 13,31,103,301,310,130 };
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}
	cout << "Mr.E의 재산 목록: \n";
	ShowArray(things, 6);
	cout << endl;
	cout << "Mr.E의 채무 목록: \n";
	ShowArray(pd, 3);

	return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
	using namespace std;
	cout << "템플릿 A\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void ShowArray(T* arr[], int n)
{
	using namespace std;
	cout << "템플릿 B\n";
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}