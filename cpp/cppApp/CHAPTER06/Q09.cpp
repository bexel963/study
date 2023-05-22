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
		cout << "donationList.txt 파일을 열 수 없습니다. " << endl;
		cout << "프로그램을 종료합니다.\n";
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
		cout << "파일 끝에 도달했습니다.\n";
	else if (inFile.fail())
		cout << "데이터 불일치로 입력이 종료되었습니다.\n";
	else
		cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";
	cout << endl;

	cout << num << endl;
	for (int i = 0; i < num; i++)
	{
		cout << cbt[i].name << endl;
		cout << cbt[i].donation << endl;
	}

	return 0;
}