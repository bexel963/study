/*
	- ���α׷��� �ϳ��� ���ڸ� ���ڿ��� �߰��� ��, �̹� ������� �̿� �޸𸮸� ħ���� ���� �ֱ� ������,
	  ���ڿ��� ���ڸ����� ���� �ڶ�� �� �� ����.
	  �׷��� ���ο� ����� �����ϰ�, ������ ������ ���ο� ��ġ�� �����ؾ� �Ѵ�.
	  �� ���� �ϴ� ���� ���� ��ȿ������ �� �ִ�. �׷��� ���� C++ �ý��۵��� ���� ���ڿ����� �ξ� ū �޸� �����
	  �����Ͽ� ���ڿ��� �ڶ� �� �ִ� ������ �����Ѵ�.
	  �׷��� ����, �� ���ڿ��� ��ħ�� �� ũ�⸦ �ʰ��ϰ� �Ǹ�, ���α׷��� �� ũ���� �� ���� ���ο� ����� �����Ͽ�
	  �������� ũ�� ���� ���� ���ڿ��� �ڶ� �� �ְ� �� ���� ������ �����Ѵ�.
	  capacity()�� ���� ����� ũ�⸦ �����ϰ�, reserve()�� �� ����� ���� �ּ� ũ�⸦ ����ڰ� ��û�ϰ� �Ѵ�.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	
	cout << "ũ��:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	
	cout << "�뷮:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;

	empty.reserve(50);
	cout << "empty.reserve(50) ���� �뷮: " << empty.capacity() << endl;

	return 0;
}

/*
	- c_str() �޼���
		: string ��ü -> C��Ÿ���� ���ڿ�
		
		: open()�� C��Ÿ�� ���ڿ� �Ű������� �䱸�Ѵ�.
			
			string filename;
			cout << .���ϸ��� �Է��Ͻÿ�: ";
			cin >> filename;
			ofstream fout;

			fout.open(filename.c_str());		
*/

/*
	- string Ŭ������ ���ø� Ŭ������ �����ϰ� �ִ�.

			template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
			basic_string
			{
				...
			}

		: �� Ŭ�������� ������ ���� �� ���� typedef�� ��� �ִ�.

			typedef basic_string<char> string;
			typedef basic_string<wchar_t> wstring;
			typedef basic_string<char16_t> u16string;
			typedef basic_string<char32_t> u32string;

			=> �̴� char �Ӹ� �ƴ϶�, wchar_t��, wchar16_t��, wchar32_t���� �����ϴ� ���ڿ��� ����� �� �ְ� ����Ѵ�.
*/