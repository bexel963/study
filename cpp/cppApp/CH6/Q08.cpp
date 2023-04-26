// �ؽ�Ʈ ������ ����, ������ ������ ���� ������ �а�, �� ���Ͽ� ��� �ִ� ���ڵ��� ���� �����ϴ� ���α׷�

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int SIZE = 20;

int main()
{
	string fileName = "wordList.txt";
	char word[SIZE];
	int etc = 0;
	int consonant = 0;
	int gather = 0;

	ifstream inFile;

	inFile.open(fileName);
	if (!inFile.is_open())
	{
		cout << fileName << " ������ �� �� �����ϴ�. " << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}
	
	while (inFile >> word)
	{
		cout << word << endl;
		if (!isalpha(word[0]))
			etc++;
		else
		{
			switch (word[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				gather++;
				break;
			default:
				consonant++;
			}
		}
	}
	if (inFile.eof())
		cout << "���� ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";

	cout << "�������� �����ϴ� �ܾ� ��: " << gather << endl;
	cout << "�������� �����ϴ� �ܾ� ��: " << consonant << endl;
	cout << "��Ÿ: " << etc << endl;

	return 0;
}