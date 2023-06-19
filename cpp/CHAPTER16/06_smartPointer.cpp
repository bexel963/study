/*
	auto_ptr<string> ps(new string("I reigned lonely as a cloud."));
	auto_ptr<string> vocation;
	vocation = ps;		// error

		: ���α׷��� ���� ��ü�� ���� �� �� ������ �õ��ϱ� ������ ��������.
		  (ps�� ������ ������ �� �ѹ�, vocation�� ������ ������ �� �� ��)

	- �� ������ �ذ��ϴ� ���
		1) ���縦 �����ϵ��� ���� �����ڸ� �����Ѵ�.
		   �׷��� �� ��ü�� �ٸ� ��ü�� ���纻�� �ǹǷ�, �� �����ʹ� ���� �ٸ� ��ü�� �����ϰ� �ȴ�.
		2) �ϳ��� ����Ʈ �����͸��� Ư�� ��ü�� ������ �� �ֵ��� ������ ������ �����Ѵ�.
		   ����Ʈ �����Ͱ� �� ��ü�� �����ϰ� �ִ� ��쿡��, �ı��ڰ� �� ��ü�� �����Ѵ�.
		   �׷��� ����, ������ ���� �������� ������Ų��.
		   �̰��� auto_ptr, unique_ptr���� ����ϴ� �����̴�.
		3) �ϳ��� Ư���� ��ü�� �����ϴ� ����Ʈ �����͵��� �� ������ �����ϴ� �ξ� �� �ȶ��� ����Ʈ �����͸� �����Ѵ�.
		   �̰��� ���� ī�����̶� �Ѵ�. ������ ������ ���� ī������ 1�� �����Ѵ�.
		   � ����Ʈ �������� ������ ���� ������ ���� ī������ 1�� ���ҵȴ�.
		   ���� ������ ����Ʈ �������� ������ ������ �� delete�� ȣ��ȴ�.
		   �̰��� shared_ptr �����̴�.
*/

#include <iostream>
#include <string>
#include <memory>

int main()
{
	using namespace std;
	auto_ptr<string> films[5] =
	{
		auto_ptr<string>(new string("Fowl Balls")),
		auto_ptr<string>(new string("Duck Walks")),
		auto_ptr<string>(new string("Chicken Runs")),
		auto_ptr<string>(new string("Turkey Errors")),
		auto_ptr<string>(new string("Goose Eggs"))
	};
	auto_ptr<string> pwin;
	pwin = films[2];		// films[2]�� �������� ����	=> films[2]�� �� �̻� �� ���ڿ��� �������� �ʴ´�. (null)	=> �̸� �����Ϸ� �ϸ� ���α׷� ũ����(Crash) �߻�.
	/*
		- auto_ptr ��ſ� shared_ptr�� ����ϸ� ����� ����ȴ�.
		  (shared_ptr�� ����Ϸ���, C++11 shared_ptr Ŭ������ �����ϴ� �����Ϸ��� �ʿ��ϴ�.)

			: pwin = films[2]; �������� pwin�� films[2]�� ���� ��ü�� ����Ű�� �ִ�. �׸���, ���� ī��Ʈ�� 1���� 2�� �ö󰣴�.
			  ���α׷��� ��������, �ı��ڴ� ���������� ����� pwin�̶�� ù ��° ��ü�� ȣ���ؾ� �Ѵ�.
			  �ı��ڴ� ���� ī��Ʈ�� 1�� ���δ�. �׸��� shared_ptr�� �迭�� ������� �����ȴ�.
			  ����������, films[2]�� �ı��ڴ� ���� ī��Ʈ�� 0���� ����� ���Ե� �޸𸮸� �����Ѵ�.
	*/

	cout << "������ �ְ��� ���� ��ȭ�� �ĺ��Դϴ�.\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;

	cout << "�����ڴ� " << *pwin << "!\n";
	cin.get();

	return 0;
}

/*
	- unique_ptr�� auto_ptró�� ������ ������ ������ �ִ�.
	  �׷��� unique_ptr�� ���α׷� ũ���ð� �߻��ϴ� ���� �ƴ϶�, �ش� �������� ������ ������ �߻��Ѵ�.

			pwin = films[2];	// compile error
*/