#include <cstring>
#include "stringImproving.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

String::String()
{
	len = 4;

	// str = "����Ʈ ���ڿ�";		-> X - new[] �� ����
	// str = new char;			-> X - [] �� ����
	// str = 0;					-> O
	// str = nullptr;			-> O
	str = new char[1];
	str[0] = '\0';
	// �� �� ���� str = 0; ���� ��ü�� �� �ִ�. (str�� �� �����ͷ� �����Ѵ�.)
	// c++98 �������� 0�� ���� �� 0 �� null pointer�� �� ���� �ǹ̰� �־���.
	// c++11 ���ʹ� str = nullptr; �� ǥ���Ѵ�. (nullptr�� Ű����)

	num_strings++;
}
/*
	- str=new char; == str=new char[1];
		: �� ���� ��� ���� ũ���� �޸𸮸� �����Ѵ�. �ٸ�, ù ��° ������ �� Ŭ������ �ı��ڿ� ȣȯ���� �ʴ´�.
		  delete [] �� ����ϴ� ����, new [] �� ����Ͽ� �ʱ�ȭ��Ų ������ �� �� �����Ϳ� ȣȯ�ȴ�.
		: delete [] �� �ٸ� ������� �ʱ�ȭ��Ų �����Ϳ� �Բ� ������� ���� ����� ��� ���� �� �� ����.

	- str = new char;
		: new�� ����������, ��Ȯ�� ũ���� �޸𸮸� ��û���� ���Ѵ�.
		  �׷��Ƿ� new�� ������ �ϳ��� ���� �� �ִ� ũ���� ����� �����Ѵ�. 
		  �� ��ġ�� �� ���ڿ��� �����Ϸ��� �õ��ϸ� �޸� ������ �߻��� ���̴�.
*/

// ��ȯ �Լ� (�Ű������� �ϳ��� ������..)
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

// ���� ������
String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String::~String()
{
	--num_strings;
	delete[] str;		// ��� �����ڰ� �̰Ͱ� ������ �Ѵ�.
}

// String�� String�� �����Ѵ�.
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
/*
	- ������ ���ڿ��� String ��ü�� ���� 
			String name;
			char temp[40];
			cin.getline(temp, 40);

			name = temp;
	  : (����1)
		�� �ڵ忡�� ���α׷��� String(const char*) �����ڸ� ����Ͽ�, temp�� ����� ���ڿ��� ���纻�� ����ִ�,
	    String �ӽ� ��ü�� �����Ѵ�.
	    (�ϳ��� �Ű������� ����ϴ� �����ڴ� ��ȯ �Լ��� ������ �����Ѵ�. - 11��)
		�׷��� ���� ���α׷��� String& String::operator=(const String&) �Լ��� ����Ͽ�, �� �ӽ� ��ü�� ������
		name ��ü�� �����Ѵ�.
		���������� ���α׷��� ~String() �ı��ڸ� ȣ���Ͽ� �� �ӽ� ��ü�� �ı��Ѵ�.
*/

// C ��Ÿ���� ���ڿ��� String�� �����Ѵ�.
String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
/*
	- ����1�� �� �� ȿ�������� ����� ���� ���� �����, ���� �����ڸ� �����ε��Ͽ� ������ ���ڿ��� ���� �ٷ� �� �ְ� �ϴ� ���̴�.
*/

char& String::operator[](int i)
{
	return str[i];
}
/*
	- [] ��ȣ�� �ϳ��� �������̴�. operator[]() ��� �޼��带 ����Ͽ� �� �����ڸ� �����ε��� �� �ִ�.
			char city[40] = "Amsterdam";
			cout << city[0] << endl;	// ���� 'A'�� ���
	  : city�� ù ��° �ǿ������̰�, 0�� �� ��° �ǿ������̴�.

			String opera("The Magic Flute");
	  : opera[4] ��� ǥ���� ���Ǹ�, C++�� String::operator[](int i) ���� �޼��� ���Ǹ� ã�´�.
		��ġ�ϴ� ������ �����Ϸ��� ã�Ҵٸ� opera[4] ��� ǥ���� opera.operator[](4) �Լ��� ��ü�ȴ�.
		��, opera ��ü�� �� �޼��带 ȣ���ϰ� ���ϰ��� opera.str[4] �̴�. 'M'
		�� public �޼��尡 private �����Ϳ� ���������� ������ ����̴�.

	  : �������� char& ������ �����߱� ������, �ϳ��� Ư�� ���ҿ� ���� �����ϴ� ���� �����Ѵ�.
			String means("might");
			means[0] = 'r';			==> means.operator[](0) = 'r';  ==> means.str[0] = 'r';
*/

const char& String::operator[](int i) const
{
	return str[i];
}
/*
	- C++�� const �Լ� �ñ׳�ó�� const�� �ƴ� �Լ� �ñ׳�ó�� �����Ѵ�
	  �׷��� const String��ü�� ����� �� �ִ� operator[]()�� ��2�� ������ ������ �� �ִ�.
	  �� ���Ǹ� ��� �����Ѵٸ�, ������ String ��ü���� �б⾲�� ������ ��� ���ǰ�, const String �����Ϳ��� �б� ���ٸ� ���ȴ�.
		String text("Once upon a time");
		const String answer("futile");
		cout << text[1];	// operator[]()�� const�� �ƴ� ���� ���
		cout << answer[1];	// operator[]()�� const ���� ���
		cin >> text[1];		// operator[]()�� const�� �ƴ� ���� ���
		cin >> answer[1];	// ������ ����!!
*/

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
/*
	- strcpm()�� ù ��° �Ű������� �� ��° �Ű��������� �տ� ���� ������ �����Ѵ�.
	- ����� < �����ڰ� �̹� bool���� ���� �����ϰ� �ֱ� ������ �ٷ� return �ڿ� �ڵ带 �־ �ȴ�.
	- �� �Լ����� ������� �����, String��ü�� ������ C��Ÿ���� ���ڿ��� ���� �� �ִ�.
		if("love" == answer)
		=> if(operator==("love", answer))
		=> if(operator==(String("love"), answer))	// �����Ϸ��� ������ �� ��� �ϳ��� ����Ͽ� �̷��� ��ȯ�Ѵ�.
*/

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}
/*
	- ���⼭ �������� ostream�� �ƴ϶� ostream&�� �Ǿ�� �Ѵ�.
	  ostream �������� ����ϸ�, ostream ���� �������� ȣ���� �䱸�� ���̴�.
	  ostream Ŭ������ public ��������ڸ� ������ �ʴ´�.
	  �޼��峪 �Լ��� ostream Ŭ������ ���� public ���� �����ڰ� ���� Ŭ������ ��ü�� �����Ѵٸ�, ��ü�� ���� ������ �����ؾ� �Ѵ�.
	  �����̵�, cout�� ���� ������ �����ϴ� ����, ȣ���ϴ� �Լ��� ��� �����ȿ� �̹� cout�� ����ֱ� ������
	  ������ ����Ű�� �ʴ´�. (vector.cpp line-175)
*/

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get()!='\n')
		continue;

	return is;
}

int String::HowMany()
{
	return num_strings;
}
/*
	- static Ŭ���� ��� �Լ�
		: ��� �Լ��� static���� �����ϴ� ���� �����ϴ�.
		  Ű���� static�� �Լ� ���ǰ� �ƴ϶� �Լ� ���� ��Ÿ���� �Ѵ�.
		: static ��� �Լ��� ��ü�� ���� ȣ��� �ʿ䰡 ����. static ��� �Լ��� this �����͵� ���� �ʴ´�.
		: static ��� �Լ��� � Ư�� ��ü�͵� �������� �ʱ� ������, ����� �� �ִ� ������ ����� static ������ ����ۿ� ����.
*/

/*
	- NULL, 0, nullptr
		: �� �����ʹ� 0 �Ǵ� NULL�� Ÿ���� �� �ִ�. NULL�� �������� ��� ���Ͽ� 0���� ���ǵǾ��ִ� ��ȣ ����̴�.
		  C ���α׷��ӵ��� ���� �� ���� ������ ���̶�� ����� ���� �ʱ� ���� 0 ��� NULL�� ����Ѵ�.
		  �׵��� �� �� ���ڸ� ��Ÿ�� ������ 0 ��� '\0'�� ����Ѵ�. (�� ���� ���ڶ�� ����� ���� �ʱ� ���ؼ�...)
		: NULL ��ſ� ���� ������ 0�� ����ϱ� ���� nulptr Ű���带 ������� �����Ѵ�.
*/



/*
	- �����ڿ� new�� ����� �� ���ǻ���
		1) �����ڿ��� new�� ����Ͽ� ������ ����� �ʱ�ȭ�Ѵٸ�, �ı��ڿ� �ݵ�� delete�� ����ؾ� �Ѵ�.
		2) new�� delete�� ����� ���� ������ �Ѵ�. new�� delete�� ¦�� �̷��, new[]�� delete[]�� ¦�� �̷��� �Ѵ�.
		3) �����ڰ� ���� ���� ���, ��� ���ȣ�� ����ϵ��� �ƴϸ� ��� ���ȣ ���� ����ϵ���, ��� �����ڰ� ���� �������
		   new�� ����ؾ� �Ѵ�.
		4) �ı��ڴ� �ϳ��ۿ� �����Ƿ�, ��� �����ڰ� �� �ı��ڿ� ������ �Ѵ�.
		   �׷��� �ϳ��� �����ڿ��� new�� ����Ͽ� �����͸� �ʱ�ȭ�ϰ�, �ٸ� �����ڿ��� �� ������(NULL �Ǵ� 0)�� �ʱ�ȭ�ϴ� ����
		   ����� �ȴ�.
		   �� ������ ���ȣ�� �ְ� ���� delete �����ڸ� �� �����Ϳ� ������ �� �ֱ� �����̴�.
*/