#include <iostream>

#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
private:
	char* str;		// �� Ŭ���� ������ ���ڿ� ��ü�� ���� �������� �������� �ʴ´ٴ� ���̴�.
	int len;
	static int num_strings;		// ��ü�� ��
public:
	StringBad(const char*);
	StringBad();
	~StringBad();

	StringBad(const StringBad&);				// ���� ������
	StringBad& operator=(const StringBad&);		// ���� ������

	friend std::ostream& operator<<(std::ostream&, const StringBad&);
};

#endif
