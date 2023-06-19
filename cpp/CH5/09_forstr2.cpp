#include <iostream>
#include <string>

int main()
{
	using namespace std;
	cout << "단어를 하나 입력하십시오: ";
	string word;
	cin >> word;

	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << word << "\n종료\n";

	return 0;
}