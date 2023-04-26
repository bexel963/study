#include <string>

using namespace std;

class Person
{
private:
	static const int LIMIT = 25;
	string lName;
	char fName[LIMIT];
public:
	Person();
	Person(const string& lN, const char* fn = "Heyyou");

	void show() const;			// 이름 성씨 형식
	void formalShow() const;	// 성씨, 이름 형식
};
