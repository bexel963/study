#include <iostream>
#include <string>

int main()
{
	using namespace std;
	cout << "�ܾ� �ϳ��� �Է��Ͻʽÿ�: ";
	string word;
	cin >> word;

	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << "\n����.\n";

	return 0;
}