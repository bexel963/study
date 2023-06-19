/*
	- string Ŭ������ string ��� ������ ���� �����ȴ�.
	- string.h, cstring ��������� string Ŭ������ �ƴ϶� C��Ÿ���� ���ڿ��� ó���ϴ� C���̺귯�� ���ڿ� �Լ����� �����Ѵ�.
*/

/*
	- string Ŭ������ �����ڵ�..
		
		1. string(const char* s)
		2. string(size_type n, char c)				: ���� c�� ��� �ʱ�ȭ�� ���� n���� string ��ü�� �����Ѵ�.
		3. string(const string& str)
		4. string()									: ũ�Ⱑ 0�� ����Ʈ string ��ü�� ����
		5. string(const char* s, size_type n)		: string ��ü�� s�� �����ϴ� NBTS�� �ʱ�ȭ�ϵ�, NBTS�� ũ�⸦ �ʰ��ϴ��� n���� ���ڱ��� �����Ѵ�.
													  ���� �Ű������� ������ ���ڵ��� ������ ��Ÿ����.
		
		   template<class Iter>
		6. string(Iter begin, Iter end)
			: Iter�� �����͵��� �Ϲ�ȭ�̴�.

		7. string(const string& str, size_type pos, size_type n = npos)	: str�� �ִ� pos ��ġ���� �����ؼ� str�� ������ ���ų�, n ���ڸ� ����ϵ� str�� ���� �Ѿ �� ����.
																		  �� string ��ü�� �Ϻθ� ������ ��ü�� �����Ѵ�.
		8. string(string&& str) noexcept

		9. string(initializer_list<char> li)		: string ��ü�� �ʱ��� ��� li�� �ִ� ���ڷ� �ʱ�ȭ�Ѵ�.		
													  string Ŭ������ ����Ʈ �ʱ�ȭ�� �����ϰ� �Ѵ�.
			string piano_man = { 'L', 'i', 's', 'z', 't' };
			string comp_lang = { 'L', 'i', 's', 'P' };
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	// 1
	string one("Lottery Winner!"); 
	cout << one << endl;

	// 2
	string two(20, '$');
	cout << two << endl;

	// 3
	string three(one);
	cout << three << endl;		

	one += " Oops!";
	cout << one << endl;		// Lottery Winner Oops!

	two = "Sorry! That was ";
	three[0] = 'P';				// Porry! That was

	// 4
	string four;
	four = two + three;	
	/*
		- �����ε� ������ +�� ����Ͽ� �ӽ� string ��ü�� �����Ѵ�.
		  �� �ӽ� string��ü�� �����ε� ������ = �� ����Ͽ� four ��ü�� ���Եȴ�.
		  + �����ڴ� �������� �����ε��Ǿ� �ֱ� ������, ��2 �ǿ������� ��ġ�� string ��ü, C��Ÿ���� ���ڿ�, �ϳ��� char�� ���� �� �� �ִ�.
	*/

	cout << four << endl;		// Sorry! That was Pottery Winner

	char alls[] = "All's well that ends well";

	// 5
	string five(alls, 20);
	/*
		- ���� �Ű������� C��Ÿ���� ���ڿ� ���̸� �ʰ��ϴ��� ��û�� ������ŭ ������ ���縦 �����Ѵ�.
		  ������ 20�� 40���� �ٲٸ� alls �ڿ� �ִ� �޸� ������ ���� �ڵ�� �ν��ϰ�, 15���� ������ ���ڸ� �����δ�.
	*/
	cout << five << "!\n";		// All's well that ends!

	// 6
	string six(alls + 6, alls + 10);
	/*
		- alls+6, alls+10 �� �� �� char* �� �������̱� ������, ���ø��� Iter�� char* ������ ��ü�Ǿ� ���ȴ�.
	*/
	cout << six << ", ";					// well,
	string seven(&five[6], &five[10]);		
	/*
		- string seven(five + 6, five + 10)
			: �迭�� �̸����� �޸�, ��ü�� �̸��� �� ��ü�� �ּҷ� ���ֵ��� �ʴ´�.
			  ��, five�� �����Ͱ� �ƴϹǷ� five + 6 �� ���ǹ��� ���� �ȴ�.
			  five[6]�� �ϳ��� char�� ���̴�. �׷��� &five[6]�� �ּ��̴�. ���� �װ��� �� �����ڿ� �Ű������� ����� �� �ִ�.
	*/
	cout << seven << "...\n";				// well...

	// 7
	string eight(four, 7, 16);
	cout << eight << "in motion!" << endl;	// That was Pottery in motion!
	
	return 0;
}

/*
	- =+ �����ڴ� �������� �����ε� �Ǿ� �����Ƿ�, string ��ü�� ���� ���ڵ� ������ �� �ִ�.
	- = �����ڵ� �����ε��Ǿ� string ��ü, C��Ÿ���� ���ڿ�, �ϳ��� �ܼ��� char�� ���� string ��ü�� ������ �� �ִ�.
	- [] �����ڰ� �����ε��Ǿ� �迭 ǥ�⸦ ����Ͽ� string ��ü�� ��� �ִ� �������� ���ڵ鿡 ������ �� �ִ�.
*/

/*
	
*/