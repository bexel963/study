/*
	- ���� �����ڵ��� �� ���� ������� �����ε��Ǿ� �ֱ� ������, string ��ü�� �ٸ� string��ü�� ���� �� �ְ�,
	  string ��ü�� C��Ÿ���� ���ڿ��� ���� �� ������, C��Ÿ���� ���ڿ��� string ��ü�� ���� �� �ִ�.

			string snake1("cobra");
			string snake2("coral");
			char snake3[20] = "anaconda";

			if(snake1 < snake2)		=> operator<(const string&, const string&)
			if(snake1 == snake3)	=> operator==(const string&, const char*)
			if(snake1 != snake2)	=> operator!=(const char*, const string&)

	- size(), length() �� �� �� � ���ڿ��� ��� �ִ� ���� ���� �����Ѵ�.

			if(snake1.length() == snake2.size())

		: length()�� string Ŭ������ ������ �������� ����� �� ���̰�, size()�� STL ȣȯ���� ���� �߰��� ���̴�.
*/

/*
	- ���ڿ� �ȿ� ��� �ִ� �κ� ���ڿ��̳� � ���ڸ� �پ��� ������� �˻��� �� �ִ�.

	- �����ε��� find() �޼����....
		
		1. size_type find(const string& str, size_type pos = 0) const
			: ȣ���� ���ڿ��� pos ��ġ�������� �����Ͽ� ó������ �߻��ϴ� �κ� ���ڿ� str�� �˻��Ѵ�.
			  �κ� ���ڿ��� �߰ߵǸ� ù ������ �ε����� �����Ѵ�. �׷��� ������ string::npos�� ����.
		2. size_type find(const char* s, size_type pos = 0) const

		3. size_type find(const char* s, size_type pos = 0, size_type n) const
			: ȣ���� ���ڿ��� pos ��ġ�������� �����Ͽ� s�� �ִ� ó�� n���� ���ڷ� �����Ǵ� �κ� ���ڿ��� 
			  ó�� ������ ���� ã�´�. �κ� ���ڿ��� �߰ߵǸ� ù ������ �ε����� �����Ѵ�. �׷��� ������ string::npos�� ����.
		4. size_type find(char ch, size_type pos = 0) const
			: ȣ���� ���ڿ��� pos ��ġ�������� �����Ͽ� ���� ch�� ó�� ������ ���� ã�´�.
			  ���ڰ� �߰ߵǸ� �װ��� �ε����� �����Ѵ�. �׷��� ������ string::npos�� ����.

	- rfind()
		: ���� ���������� �߻��ϴ� �κ� ���ڿ� �Ǵ� ���ڸ� ã�´�.

	- find_first_of()
		: ȣ���� ���ڿ����� �Ű������� �ִ� ���ڵ� �� ���� ���� �߻��ϴ� ���ڸ� ã�´�.

				string snake1("cobra");
				int where = snake1.find_first_of("hark");	// r�� ��ġ�� �ε��� 3�� ����

	- find_last_of()
		: �Ű������� �ִ� ���ڵ� �� ���� ���߿� �߻��ϴ� ���ڸ� ã�´�.

				int where = snake1.find_last_of("hark");	// a�� ��ġ�� �ε��� 4�� ����

	- find_first_not_of()
		: ȣ���� ���ڿ����� �Ű������� ���� ù ���ڸ� ã�´�.

				int where = snake1.find_first_not_of("hark");	// c�� "hark"�� ���� ������ c�� ��ġ�� �ε��� 0�� ����
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;

const int NUM = 26;
const string wordList[NUM] = { "apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage",
							   "health", "insult", "jackal", "keeper", "loaner", "manage", "nonce",
							   "onset", "plaid", "quilt", "remote", "stolid", "train", "useful",
							   "valid", "whence", "xenon", "yearn", "zippy" };

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	std::srand(std::time(0));
	char play;
	
	cout << "���� �ܾ� ������ �Ͻðڽ��ϱ�? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordList[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;

		cout << "�������� �ܾ ������ ���ʽÿ�." << length << "���� ���ڷ� �̷���� �ֽ��ϴ�." << endl;
		cout << "�� ���� �� ���ھ� �����Ͻʽÿ�.\n Ʋ�� �� �ִ� ��ȸ: " << guesses << "��\n";
		cout << "�����ϴ� �ܾ�: " << attempt << endl;
		
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "���ڸ� �����Ͻʽÿ�: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "�̹� ������ �����Դϴ�. �ٽ� �Ͻʽÿ�.\n";
				continue;
			}

			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "��! Ʋ�Ƚ��ϴ�.\n";
				--guesses;
				badchars += letter;	// += �������� �����ε� ���� ���� �ϳ��� �������� ���ڵ��� string ��ü�� ������ �� �ִٴ� ����� Ȱ���Ѵ�.
			}
			else
			{
				cout << "������! �¾ҽ��ϴ�.\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);	// ���� ���ڰ� �ִ��� �˻�
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "�����ϴ� �ܾ�: " << attempt << endl;
			
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Ʋ���� ������ ���ڵ�: " << badchars << endl;
				cout << "Ʋ�� �� �ִ� ��ȸ: " << guesses << "��\n";
			}
		}

		if (guesses > 0)
			cout << "�׷����ϴ�. �װ��� �������� �ܾ��Դϴ�.\n";
		else
			cout << "��Ÿ�����ϴ�. �������� �ܾ�� " << target << "�Դϴ�.\n";

		cout << "������ �ٽ� �ϰڽ��ϱ�? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

/*
	- string ��ü���� ���� �����ڵ��� �����ε��Ǿ� �ֱ� ������, ��ġ �������� �ٷ�� �Ͱ� ������ ������� ���ڿ����� �ٷ� �� �ִ�.
	  C��Ÿ���� ���ڿ��� ������ strcmp()�� ����ϴ� �ͺ��� �̰��� �ξ� ���ϴ�.

	- ���� npos�� string Ŭ������ static ����̴�. npos�� ���� string ��ü�� ������ �� �ִ� �ִ� ��� ���� ���̴�.
	  �ε����� 0���� �����ϹǷ�, npos�� ���� ū �ε������� 1��ŭ ũ��.
	  ���� �װ����� ���ڳ� ���ڿ� �˻��� �����ߴٴ� ���� ��Ÿ�� �� �ִ�.
*/