// getline(cin, string)

#include <iostream>
#include <string>

using namespace std;

const int Upper = 10000;

struct Contributor
{
	string name;
	double donation;
};

int main()
{
	int num;

	cout << "인원 수 입력: ";
	cin >> num;
	
	Contributor* ctb = new Contributor[num];
	for (int i = 0; i < num; i++)
	{
		cout << "<" << i+1 << "번째 사람>" << endl;
		cout << "이름 입력: ";
		cin >> ctb[i].name;
		cout << "기부금 입력: ";
		cin >> ctb[i].donation;
	}
	if (num <= 0)
		cout << "기부자가 없습니다.";
	
	cout << "\n<고액 기부자 목록>" << endl;
	for (int i = 0; i < num; i++)
	{
		if (ctb[i].donation >= Upper)
		{
			cout << ctb[i].name << endl;
			cout << ctb[i].donation << endl;
		}
	}

	cout << "\n<소액 기부자 목록>" << endl;
	for (int i = 0; i < num; i++)
	{
		if (ctb[i].donation < Upper)
		{
			cout << ctb[i].name << endl;
			cout << ctb[i].donation << endl;
		}
	}

	return 0;
}