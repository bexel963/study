#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char word[5] = "?ate";

	for (char ch = 'a'; strcmp(word, "mate"); ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	cout << "루프가 끝난 후에 단어는 " << word << "입니다.\n";

	return 0;
}