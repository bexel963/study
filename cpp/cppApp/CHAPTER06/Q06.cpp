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

	cout << "�ο� �� �Է�: ";
	cin >> num;
	
	Contributor* ctb = new Contributor[num];
	for (int i = 0; i < num; i++)
	{
		cout << "<" << i+1 << "��° ���>" << endl;
		cout << "�̸� �Է�: ";
		cin >> ctb[i].name;
		cout << "��α� �Է�: ";
		cin >> ctb[i].donation;
	}
	if (num <= 0)
		cout << "����ڰ� �����ϴ�.";
	
	cout << "\n<��� ����� ���>" << endl;
	for (int i = 0; i < num; i++)
	{
		if (ctb[i].donation >= Upper)
		{
			cout << ctb[i].name << endl;
			cout << ctb[i].donation << endl;
		}
	}

	cout << "\n<�Ҿ� ����� ���>" << endl;
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