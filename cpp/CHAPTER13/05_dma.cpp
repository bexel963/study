#include "dma.h"
#include <cstring>

// baseDMA �޼����
baseDMA::baseDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}
baseDMA::~baseDMA()
{
	delete[] label;
}
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "��ǥ: " << rs.label << std::endl;
	os << "���: " << rs.rating << std::endl;
	return os;
}

// lacksDMA �޼����
lacksDMA::lacksDMA(const char* c, const char* l, int r) : baseDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char* c, const baseDMA& rs) : baseDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "����: " << ls.color << std::endl;
	return os;
}

// hasDMA �޼����
hasDMA::hasDMA(const char* s, const char* l, int r) : baseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char* s, const baseDMA& rs) : baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
/*
	- hasDMA ���� �����ڴ� hasDMA �����Ϳ��� �������� �� �����Ƿ� �������� baseDMA ������ ó���Ϸ��� baseDMA ���� �����ڸ� ȣ���ؾ� �Ѵ�.
	  ���⼭ ��� �ʱ��� ����Ʈ�� baseDMA �����ڿ� hasDMA ������ �����ϴ� �Ϳ� �ָ��ؾ� �Ѵ�.
	  hasDMA �������� �Ű������� ����ϴ� baseDMA �����ڴ� ����. �׷��� �װ��� ���� �ʿ䰡 ����.
	  �ֳ��ϸ� baseDMA ���� �����ڰ� baseDMA �������� �Ű������� ����ϰ� �ְ�, ���� Ŭ���� ������ �Ļ����� ������ �� �ֱ� �����̴�.
	  �׷��Ƿ� �� baseDMA ���� �����ڰ�, hasDMA �Ű������� baseDMA �κ��� ����Ͽ�, �� ��ü�� baseDMA �κ��� �����Ѵ�.
*/

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);		// ���� Ŭ���� �κ��� �����Ѵ�.
	delete[] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}
/*
	- hasDMA�� ���� �޸� ������ ����ϱ� ������, hasDMA�� ������� ���� �����ڸ� �ʿ�� �Ѵ�.
	  �װ��� hasDMA �޼����̱� ������, �װ͸��� hasDMA �����Ϳ� ���������� ������ �� �ִ�.
	  �׷����� �ұ��ϰ�, �Ļ� Ŭ������ ����� ���� �����ڴ�, ��ӹ��� baseDMA ���� Ŭ���� ��ü�� ���� ������ ó���� �� �־�� �Ѵ�.
	  ���� Ŭ���� ���� �����ڸ� ��������� ȣ�������ν� �̰��� ó���� �� �ִ�.	  
		
				baseDMA::operator=(hs);

	  ������ ǥ�� ��� �Լ� ǥ�⸦ ��������ν�, ��� ���� ���� �����ڸ� ����� �� �ֵ��� ����Ѵ�.
	  *this = hs; �� ���� �ϸ� �����Ϸ��� hasDMA::operator=()�� ����ϰ� �ǰ�, �̰��� ��� ȣ���� ����Ų��.
*/

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;	// operator<<(ostream&, const baseDMA&)�� ���� ���� �������� ��ȯ
	os << "��Ÿ��: " << hs.style << std::endl;
	return os;
}
/*
	- �� �Լ��� hasDMA Ŭ������ �������̱� ������, style ����� ������ �� �ִ�.
	  �׷��� �� �Դ� baseDMA Ŭ������ ���ؼ��� �����尡 �ƴϱ� ������ rabel�� rating�� ������ �� ����.
	  �� ������ ���� �ذ�å�� baseDMA Ŭ������ ���� �������� operator<<() �� ����ϴ� ���̴�.
	  �׷��� ������� ��� �Լ��� �ƴϱ� ������, ��� �Լ��� ����� �������� ��Ÿ���� ���� ��� ���� ���� �����ڸ� ����� �� ����.
	  �� ������ ���� �ذ�å��, ���� �������� ��ȯ�� ����Ͽ� ���� ��ġ�� ���� �ùٸ� �Լ��� ������ �� �ֵ��� �ϴ� ���̴�.
*/

/*
	- ����
		: ���� Ŭ������ �Ļ� Ŭ������ �� �� ���� �޸� ����, �Ļ� Ŭ���� �ı���, ���� ������, ���� �����ڸ� ����� ��
		  �̵��� ��� ���� Ŭ���� ������ ó���ϱ� ���� �׵��� ���� Ŭ���� �������� ����ؾ� �Ѵ�.
		  �� ����� �䱸 ������ ���� �ٸ� �� ���� ������� �̷������.

		  1) �ı���
			: �װ��� �ڵ����� �̷������.
		  2) ������
			: �װ��� ��� �ʱ��� ����Ʈ���� ���� Ŭ���� ���� �����ڸ� ȣ�������ν� �̷�����ų�, ����Ʈ �����ڰ� �ڵ����� ȣ��ȴ�.
		  3) ���� ������
			: �װ��� ���� Ŭ���� ���� �������� ����� ȣ�⿡�� ��� ���� ���� �����ڸ� ��������ν� �̷������.
*/