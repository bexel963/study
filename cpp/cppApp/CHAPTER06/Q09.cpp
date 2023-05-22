#include <iostream>
#include <fstream>

using namespace std;

struct Contributor
{
	string name;
	double donation;
};

int main()
{
	int num;
	char input[20];

	ifstream inFile;
	inFile.open("donationList.txt");
	if (!inFile.is_open())
	{
		cout << "donationList.txt ������ �� �� �����ϴ�. " << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}

	inFile >> num;
	Contributor* cbt = new Contributor[num];
	int idx = 0;
	int cnt = 0;

	while (inFile.getline(input, 20))
	{
		if (isalpha(input[0]))
		{
			cbt[idx].name = input;
		}					
		else
		{
			if (cnt == 0)
				continue;
			cbt[idx].donation = atoi(input);
			idx++;
		}
		cnt++;
	}

	cout << endl;
	if (inFile.eof())
		cout << "���� ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";
	cout << endl;

	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		cout << cbt[i].name << endl;
		cout << cbt[i].donation << endl;
	}

	return 0;
}