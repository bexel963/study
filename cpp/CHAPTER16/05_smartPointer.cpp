/*
	- smart pointer�� ������ó�� �ൿ�ϴ� Ŭ���� ��ü������, �� ���� �߰� ����� ���Ѵ�.

	- ���� �ִ� �ڵ�

			void remmoder(string& str)
			{
				string* ps = new string(str);
				...
				str = ps;
				return;
			}
			: �� �Լ���ȣ��� ������ �� �޸𸮸� ���������� �װ��� �������� �ʴ´�.
			  delete ps; �� �߰��ϴ� ���� �ּ��� �ذ�å�� �ƴѴ�. (������ ���ɼ� ����..)

	- �Լ��� ���������� ����� �� �Ǵ� ���ܰ� �߻��Ͽ� ����� ��, ���� ������ ���� �޸𸮷κ��� �����ȴ�.
	  �׷��� ps �����Ͱ� �����ϰ� �ִ� �޸𸮰� �����ȴ�. �̶� ps �����Ͱ� �����ϴ� �޸𸮵� �԰� �����ȴٸ� ���� ���̴�.
	  �̰��� ps�� ������ ������ �� ���α׷��� � �߰� ��ġ�� ���ؾ� �Ѵٴ� ���� �ǹ��Ѵ�.
	  �̷��� �߰� ���񽺴� �⺻ ���������鿡 ���ؼ��� �������� �ʰ�, �ı��� ��Ŀ������ ���ؼ� Ŭ�����鿡 ���ؼ��� �����ȴ�.
	  �׷��� ps�� Ŭ���� ��ü�� �ƴ϶� �Ϲ� �������� ���� ������ �ȴ�.
	  ps�� ��ü���ٸ�, ps�� ������ ������ �� �װͿ� ���� ���õǴ� �޸𸮵� �ı��ڸ� ���ؼ� �Բ� ������ �� �ֱ� �����̴�.
	  �̰��� auto_ptr�� ź���� ����̴�.
*/

/*
	- ����Ʈ �������� ���
			1) auto_ptr
			2) unique_ptr
			3) shared_ptr
		: ����Ʈ ������ ���ø����� ���� new�� ���� ������� �ּҸ� ������ �����͸� �����Ѵ�.
		  ����Ʈ �����Ͱ� ������ ������ ��, �ı��ڴ� delete�� ����Ͽ� �޸𸮸� �����Ѵ�.
		  ����, ���� new�� �����ϴ� �ּҸ� �� �� ���� ��ü �� �ϳ��� �����ϰ� �Ǹ�, ���߿� �޸𸮸� ������ �ʿ䰡 ������,
		  ����Ʈ ������ ��ü�� ������ ������ ��, �ڵ������� �޸𸮰� �����ȴ�.
		: �̷��� ����Ʈ ������ ��ü�� �� �ϳ��� �����ϱ� ���ؼ��� ���ø��� �����ϴ� memory ��� ������ �ҽ� �ڵ忡 �����ؾ� �Ѵ�.
		  �� ����, �Ϲ����� ���ø� ������ ����Ͽ� �ʿ��� �������� ������ ��üȭ �Ѵ�.

				template<class X> 
				class auto_ptr 
				{
				public:
					explicit auto_ptr(X* p=0) throw();	// ����Ʈ ������ ������
					...
				};

				auto_ptr<double> pd(new double);	// new double�� new�� ������ ���� ���Ե� �޸𸮸� ����Ű�� �������̴�.
				auto_ptr<string> ps(new string);
*/
/*
	- �Ϲ� �����Ϳ� ��
				double* pd = new double;
				auto_ptr<double> ap(new double);
*/


#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s)
	{
		std::cout << "��ü�� �����Ǿ����ϴ�.\n";
	}
	~Report()
	{
		std::cout << "��ü�� �����Ǿ����ϴ�.\n";
	}
	void comment() const
	{
		std::cout << str << std::endl;
	}
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("auto_ptr"));
		ps->comment();
	}
	{
		std::shared_ptr<Report> ps(new Report("shared_ptr"));
		ps->comment();
	}
	{
		std::unique_ptr<Report> ps(new Report("unique_ptr"));
		ps->comment();
	}

	return 0;
}

/*
	- �� ������ Ŭ�������� �Ű������� �����͸� �޾Ƶ��̱� ���� ����� �����ڸ� ������ �ִ�.
	  ����, �����͸� auto_ptr�� ��ȯ�ϱ� ���� �ڵ� �� ��ȯ�� ��� �ȴ�.

			share_ptr<double> pd;
			double* p_reg = new double;
			
			pd = p_reg;							// ������ ����(�Ͻ��� ��ȯ)
			pd = (share_ptr<double>)p_reg;		// ����(����� ��ȯ)

			share_ptr<double> pshared = p_reg;	// ������ ����(�Ͻ��� ��ȯ)
			share_ptr<double> pshared(p_reg)	// ����(����� ��ȯ)
			
	- ����Ʈ ������ ���ø� Ŭ�������� �Ϲ� ������ó�� ������ �� �ִ�.

	- ����Ʈ �����͸� ����ϸ� �ȵǴ� ���

			string vacation("I wandered lonely as a cloud.");
			shared_ptr<string> pvac(&vacation);		// error

		: pvac�� ������ ������ �� ���α׷��� delete�Ϸ��� �޸𸮰� heap�� �������� �ʱ� ������ �� �ڵ�� �߸��� ���̴�.
*/