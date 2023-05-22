#include <iostream>
#include <fstream>
#include <cstdlib>

const int SIZE = 60;

int main()
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile;
	
	cout << "������ ������ �̸��� �Է��Ͻÿ�: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << filename << " ������ �� �� �����ϴ�. " << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}
	if (inFile.eof())
		cout << "���� ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";

	if (count == 0)
		cout << "�����Ͱ� �����ϴ�.\n";
	else
	{
		cout << "���� �׸��� ����: " << count << endl;
		cout << "�հ�: " << sum << endl;
		cout << "���: " << sum / count << endl;
	}
	inFile.close();

	return 0;
}