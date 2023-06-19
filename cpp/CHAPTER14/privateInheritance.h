#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> ArrayDb;
	std::ostream& arr_out(std::ostream& os) const;
public:
	// �������ǰ� �޸�, ����� ��ü �̸����� �����Ǿ���, �ζ��� �����ڿ��� ��� �̸� ��ſ� Ŭ���� �̸��� ���ȴ�.
	Student() : std::string("Null Student"), ArrayDb() { }
	explicit Student(const std::string& s) : std::string(s), ArrayDb() { }
	explicit Student(int n) : std::string("Nully"), ArrayDb(n) { }
	Student(const std::string& s, int n) : std::string(s), ArrayDb(n) { }
	Student(const std::string& s, const ArrayDb& a) : std::string(s), ArrayDb(a) { }
	Student(const char* str, const double* pd, int n) : std::string(str), ArrayDb(pd, n) { }
	~Student() { }

	double Average() const;
	double& operator[](int i);
	double operator[](int i) const;
	const std::string& Name() const;

	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif


/*
	- has-a ���踦 �����ϴ� ��2�� �������� private ����� �����Ѵ�.
		: private ��ӿ�����, ���� Ŭ������ public ����� protected ����� �Ļ� Ŭ������ private ����� �ȴ�.
		  ��, ���� Ŭ������ �޼������ �Ļ� ��ü�� public �������̽��� �Ϻΰ� ���� �ʴ´�. (= �Ļ� Ŭ������ ���� Ŭ������ �������̽��� ��ӹ��� �ʴ´�.)
		  �׷��� �Ļ� Ŭ������ ��� �Լ��� �ȿ��� �װ͵��� ����� �� �ִ�.
		: �����θ�Ʈ��, ��ü�� �̸��� �ִ� ��� ��ü�� Ŭ������ �߰��Ѵ�. 
		  �ݸ鿡 private����� ��ü�� �̸��� ���� ��ӵ� ��ü�� Ŭ������ �߰��Ѵ�.
		  ��ӿ� ���� �߰��� ��ü��, �����θ�Ʈ�� ���� �߰��� ��ü�� ��� ���� ��ü��� �θ���.
		: private ����� �����θ�Ʈ�� ������ ����� �����Ѵ�. ��, ������ ȹ�������� �������̽��� ȹ������ �ʴ´�. -> has-a ���踦 �����ϴ� �� ����� �� �ִ�.
*/

/*
	- private ���
		: private ����� ����Ϸ���, Ŭ������ ������ �� public ��ſ� private�� Ű����� ����ؾ� �Ѵ�.
		  (����Ʈ�� private�̴�. �׷��� ���� �����ڸ� �����ϸ� private ����� �ȴ�.)
		: �� Student Ŭ������ private �����͸� ���� �ʿ䰡 ����. ��ӵǴ� �� ���� Ŭ������ �ʿ��� ������ ������� ��� �����ϱ� �����̴�.
		  �����θ�Ʈ ������ Student Ŭ������ ��������� �̸��� ������ �� ���� ��ü�� ����� ����������, private ��� ������ �̸��� ���� �� ���� ���� ��ü�� ��ӵ� ����� �����Ѵ�.
		: private ����� ���� Ŭ���� �޼��带 �Ļ� Ŭ���� �޼����� �ȿ����� ����� �� �ֵ��� �����Ѵ�.
		  �׷��� ���δ� ���� Ŭ���� ����� public���� ����ϰ� ���� ���� ���� ���̴�.
		  �����θ�Ʈ ���� ������, public�� Student::Average() �Լ� �ȿ��� valarray Ŭ������ ��ü�� ����Ͽ� size()�� sum() �޼��带 ����ߴ�.
		  �׷��� private ��� ���������� Ŭ���� �̸��� ��� ���� ���� �����ڸ� ����Ͽ� ���� Ŭ������ �޼��带 ȣ���� �� �ִ�.
		  ��, �����θ�Ʈ ���� ����� ��ü ������ ����Ͽ� �޼��带 ȣ���ϰ�, private ����� Ŭ���� �̸��� ��� ���� ���� �����ڸ� ����Ѵ�.
			=> ��� ���� ���� �����ڴ� ���� Ŭ���� �޼��忡 �����ϴ� ���� ����Ѵ�.
*/


/*
	- using�� ����Ͽ� ���� �ٽ� �����ϱ�
		: � Ư�� ���� Ŭ���� �޼��带 �Ļ� Ŭ�������� public���� ����� �� �ְ� �ϴ� ���
			1) ���� Ŭ���� �޼��带 ����ϴ� �Ļ� Ŭ���� �޼��带 �����Ѵ�.
				double Student::sum() const
					{
						return std::valarray<double>::sum();
					}
			2) using ���� ���
				class Student : private std::string, private std::valarray<double>
					{
						...
						public:
							using std::valarray<double>::min;
							using std::valarray<double>::max;
							using std::valarray<double>::operator[];
							...
					};
				using ������ valarray�� �޼��带 ��ġ public�� Student �޼����� ��ó�� ����� �� �ְ� �����.			
				using ������ �Ұ�ȣ, �Լ� �ñ׳�ó, ������ ���� ��� �̸��� ����Ѵ�.
				using ������ ����ϴ� ������ ��ӿ��� ����ǰ� �����θ�Ʈ���� ������� �ʴ´�.
		
*/