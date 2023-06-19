/*
	- 관계 연산자들은 세 가지 방식으로 오버로딩되어 있기 때문에, string 객체를 다른 string객체와 비교할 수 있고,
	  string 객체를 C스타일의 문자열과 비교할 수 있으며, C스타일의 문자열을 string 객체와 비교할 수 있다.

			string snake1("cobra");
			string snake2("coral");
			char snake3[20] = "anaconda";

			if(snake1 < snake2)		=> operator<(const string&, const string&)
			if(snake1 == snake3)	=> operator==(const string&, const char*)
			if(snake1 != snake2)	=> operator!=(const char*, const string&)

	- size(), length() 는 둘 다 어떤 문자열에 들어 있는 문자 수를 리턴한다.

			if(snake1.length() == snake2.size())

		: length()는 string 클래스의 오래된 버전부터 사용해 온 것이고, size()는 STL 호환성을 위해 추가된 것이다.
*/

/*
	- 문자열 안에 들어 있는 부분 문자열이나 어떤 문자를 다양한 방법으로 검색할 수 있다.

	- 오버로딩된 find() 메서드들....
		
		1. size_type find(const string& str, size_type pos = 0) const
			: 호출한 문자열의 pos 위치에서부터 시작하여 처음으로 발생하는 부분 문자열 str을 검색한다.
			  부분 문자열이 발견되면 첫 문자의 인덱스를 리턴한다. 그렇지 않으면 string::npos를 리턴.
		2. size_type find(const char* s, size_type pos = 0) const

		3. size_type find(const char* s, size_type pos = 0, size_type n) const
			: 호출한 문자열의 pos 위치에서부터 시작하여 s에 있는 처음 n개의 문자로 구성되는 부분 문자열이 
			  처음 나오는 것을 찾는다. 부분 문자열이 발견되면 첫 문자의 인덱스를 리턴한다. 그렇지 않으면 string::npos를 리턴.
		4. size_type find(char ch, size_type pos = 0) const
			: 호출한 문자열의 pos 위치에서부터 시작하여 문자 ch가 처음 나오는 것을 찾는다.
			  문자가 발견되면 그것의 인덱스를 리턴한다. 그렇지 않으면 string::npos를 리턴.

	- rfind()
		: 가장 마지막으로 발생하는 부분 문자열 또는 문자를 찾는다.

	- find_first_of()
		: 호출한 문자열에서 매개변수에 있는 문자들 중 가장 먼저 발생하는 문자를 찾는다.

				string snake1("cobra");
				int where = snake1.find_first_of("hark");	// r의 위치인 인덱스 3을 리턴

	- find_last_of()
		: 매개변수에 있는 문자들 중 가장 나중에 발생하는 문자를 찾는다.

				int where = snake1.find_last_of("hark");	// a의 위치인 인덱스 4를 리턴

	- find_first_not_of()
		: 호출한 문자열에서 매개변수에 없는 첫 문자를 찾는다.

				int where = snake1.find_first_not_of("hark");	// c가 "hark"에 없기 때문에 c의 위치인 인덱스 0을 리턴
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
	
	cout << "영어 단어 게임을 하시겠습니까? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordList[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;

		cout << "수수께끼 단어를 추측해 보십시오." << length << "개의 문자로 이루어져 있습니다." << endl;
		cout << "한 번에 한 문자씩 추측하십시오.\n 틀릴 수 있는 기회: " << guesses << "번\n";
		cout << "추측하는 단어: " << attempt << endl;
		
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "문자를 추측하십시오: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "이미 추측한 문자입니다. 다시 하십시오.\n";
				continue;
			}

			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "땡! 틀렸습니다.\n";
				--guesses;
				badchars += letter;	// += 연산자의 오버로딩 버전 중의 하나가 개별적인 문자들을 string 객체에 덧붙일 수 있다는 사실을 활용한다.
			}
			else
			{
				cout << "딩동댕! 맞았습니다.\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);	// 같은 문자가 있는지 검사
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "추측하는 단어: " << attempt << endl;
			
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "틀리게 추측한 문자들: " << badchars << endl;
				cout << "틀릴 수 있는 기회: " << guesses << "번\n";
			}
		}

		if (guesses > 0)
			cout << "그렇습니다. 그것이 수수께끼 단어입니다.\n";
		else
			cout << "안타깝습니다. 수수께끼 단어는 " << target << "입니다.\n";

		cout << "게임을 다시 하겠습니까? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "프로그램을 종료합니다.\n";

	return 0;
}

/*
	- string 객체들은 관계 연산자들이 오버로딩되어 있기 때문에, 수치 변수들을 다루는 것과 동일한 방식으로 문자열들을 다룰 수 있다.
	  C스타일의 문자열을 가지고 strcmp()를 사용하는 것보다 이것이 훨씬 편리하다.

	- 변수 npos는 string 클래스의 static 멤버이다. npos의 값은 string 객체가 지정할 수 있는 최대 허용 문자 수이다.
	  인덱스는 0부터 시작하므로, npos는 가장 큰 인덱스보다 1만큼 크다.
	  따라서 그것으로 문자나 문자열 검색이 실패했다는 것을 나타낼 수 있다.
*/