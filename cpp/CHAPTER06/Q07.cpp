#include <iostream>
#include <string>

using namespace std;
const int SIZE = 20;

int main()
{
	char word[SIZE];
	int etc = 0;
	int consonant = 0;
	int gather = 0;

	cout << "�ܾ���� �Է��Ͻÿ� (�������� q): \n";
	while ((cin>>word) && strcmp(word, "q\0"))
	{
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

	cout << "�������� �����ϴ� �ܾ� ��: " << gather << endl;
	cout << "�������� �����ϴ� �ܾ� ��: " << consonant << endl;
	cout << "��Ÿ: " << etc << endl;

	return 0;
}