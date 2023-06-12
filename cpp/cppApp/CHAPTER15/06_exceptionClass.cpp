/*
	- exception ��� ������ C++ �� �� �����ϱ� ���� ����ϴ� �ٸ� ���� Ŭ�������� ���� Ŭ������ ����ϴ� exception Ŭ������ �����Ѵ�.
	  exception Ŭ������ whta() �̶�� �ϳ��� ���� ��� �Լ��� �־�����. �װ��� �ý����� Ư���� ���� �ϳ��� ���ڿ��� �����Ѵ�.

				  #include <exception>

				  class bad_hmean : public std::exception
				  {
				  public:
					  const char* what() { return "hmean()�� �߸��� �Ű�����"; }
					  ...
				  };

				  class bad_gmean : public std::exception
				  {
				  public:
					  const char* what() { return "gmean()�� �߸��� �Ű�����"; }
					  ...
				  };

				  try {
					  ...
				  }
				  catch (std::exception& e)
				  {
					  cout << e.what() << endl;
				  }
		
*/

/*
	- stdexcept ��������� �� ���� ���� Ŭ�������� �� �����Ѵ�.
			1) logic_error Ŭ����
			2) runtime_error Ŭ����
	  �̵��� exception���κ��� public���� �Ļ��ȴ�.
	  �������� �Ű������� string ��ü�� what() �� ���� C��Ÿ�� ���ڿ��� ���ϵ� ���� �����͸� �����Ѵ�.

				  class logic_error : public exception
				  {
				  public:
					  explicit logic_error(const string& what_arg);
					  ...
				  }

				  class runtime_error : public exception
				  {
				  public:
					  explicit runtime_error(const string& what_arg);
					  ...
				  }
*/

/*
	- logic_error �йи�
		: �Ϲ����� �� �������� �����Ѵ�.
		: Ŭ������
			domain_error
			invalid_argument
			length_error
			out_of_bounds
		: ������ Ŭ������, ����ڰ� what() �� ���� ���ϵǴ� ���ڿ��� �����ϴ�, logic_error�� �����ڿ� ����, �����ڸ� ������ �ִ�.

	- domain_error
		���ǿ� -> �Լ��� ���ǵǴ� ����� �̷����
		ġ��   -> �� �Լ��� �����ϴ� ����� �̷����
			ex) ���� �Լ��� ���ǿ� -> -���� ~ +����
			    ���� �Լ��� ġ��   -> -1 ~ +1
				��ũ������ ���ǿ�  -> -1 ~ +1
				��ũ������ ġ��    -> -���� ~ +����

				std::sin() �Լ��� �Ű������� �����ϴ� �Լ��� �ۼ��Ѵٸ�, �Ű������� -1 ~ 1 ������ ���ǿ��� ��� �� �� �Լ��� 
				domain_error ��ü�� �߻���Ű���� �� �� �ִ�.

	- invalid_argument
		: ������� �ʴ� ���� �Լ��� ���޵Ǿ��ٴ� ���� ����ڿ��� ����Ѵ�.

	- length_error
		: ���ϴ� �׼��� ���� ��ŭ ����� ������ ����� �� ���ٴ� ���� ��Ÿ���� �� ���ȴ�.

	- out_of_bounds
*/

/*
	- runtime_error
		: ������ ��ư� ���浵 �����, �����ϴ� ���ȿ� ��Ÿ�� �� �ִ� �������� �����Ѵ�.
			range_error
			overflow_error
			underflow_error

		: ������ Ŭ������, ����ڰ� what() �� ���� ���ϵǴ� ���ڿ��� �����ϴ�, runtime_error�� �����ڿ� ����, �����ڸ� ������ �ִ�.

	- range_error
		: ����÷γ� �����÷� ���� ��� ����� �Լ��� ������ ġ���� ��� ���� �ִ�. �׷��� ��Ȳ���� range_error ���ܸ� ����� �� �ִ�.
*/

/*
	- ��� ���� Ŭ�������� �������� ���� �ٸ� Ŭ���� �̸����� ������ ���� ���������� ���������� ó���� �� �ְ� ����Ѵٴ� ���̴�.
	  ����, ��� ����� ���Ѵٸ� �׵��� �ϰ������� �Բ� �ٷ�� ���� ����Ѵ�.
				try{
					...
				}
				catch(out_of_bounds& oe)
				{
					...
				}
				catch(logic_error& oe)
				{
					...
				}
				catch(exception& oe)
				{
					....
				}
*/

/*
	- bad_alloc ���ܿ� new
		: C++ �ý��۵��� new�� ����� �� �Ͼ�� �޸� ���� ������ �ذ��ϴ� �� ���� ���
			1) �޸� ��û�� ������ų �� ���� ��� new�� �� �����͸� �����Ѵ�.
			2) new�� bad_alloc ���ܸ� �߻���Ų��.

		: new ������Ͽ��� exception Ŭ�������� public���� �Ļ��� bad_alloc Ŭ������ ������ ����ִ�.
*/

// - ���ܰ� �����Ǹ� ���α׷��� ��ӹ��� what() �޼��尡 �����ϴ�, �ý��۸��� �ٸ� �޽����� ����ϰ� ��� ����Ǵ� ���α׷�.....

#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

struct Big
{
	double stuff[20000];
};

int main()
{
	Big* pb;
	
	try {
		cout << "ū �޸� ��� ������ ��û�ϰ� �ֽ��ϴ�.\n";
		pb = new Big[100000];		// 1,600,000,000 ����Ʈ ����
	}
	catch (bad_alloc& ba)
	{
		cout << "���ܰ� �����Ǿ����ϴ�.\n";
		cout << "�޸� ��� ���� ��û�� �źεǾ����ϴ�.\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "�޸� ����� ���������� ���ԵǾ����ϴ�.\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;

	return 0;
}

/*
	- ��κ��� �ҽ� �ڵ�� new�� �����ϸ� null �����͸� �����ϵ��� �ۼ��Ǿ��ִ�.
	  �Ϻ� �����Ϸ����� ����ڰ� ���ϴ� �ൿ�� �÷��׳� ����ġ�� �����Ͽ� ������ �� �ֵ��� ���ο� new�� �����Ѵ�.
	  ���� ǥ���� null�� �����ϴ� ������ new�� ��ü�ϴ� ���¸� �����ϰ� �ִ�.

	- ���ο� new�� ������ ���� ����Ѵ�.
			int* pi = new (std::nothrow) int;
			int* pa = new (std::nothrow) int[500];
*/

//int main()
//{
//	Big* pb;
//
//	pb = new (std::nothrow) Big[10000];
//	if (pb == 0)
//	{
//		cout << "�޸� ��� ���� ��û�� �źεǾ����ϴ�.\n";
//		exit(EXIT_FAILURE);
//	}
//}