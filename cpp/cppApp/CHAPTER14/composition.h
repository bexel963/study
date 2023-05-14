#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

/*
	- �ڵ��� ��Ȱ�뼺�� ���̴� ���
		1) is-a ����  -> public ���
		2) has-a ���� -> ��������(�����θ�Ʈ)(���̾), private ���, protected ���

	- ��������
		: �ٸ� Ŭ������ ��ü���� ����� ������(�����ϴ�) Ŭ����

	- �������̽��� ����
		: public ��ӿ���, Ŭ������ �������̽��� ������ ����Ѵ�. �������̽��� ȹ���ϴ� ���� is-a ������ �����̴�.
		  �����θ�Ʈ������ � Ŭ������ �������̽� ���� ������ ȹ���Ѵ�. �������̽��� ������� �ʴ� ���� has-a ������ �����̴�.
*/
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	/*
		- typedef�� Ŭ���� ������ private �κп� �ִ� ����, �װ��� Student Ŭ������ �ܺ� ����ڵ鿡 ���ؼ��� �ƴ϶� Student ������ ���������� ���� �� �ִٴ� ���� �ǹ��Ѵ�.
	*/

	std::string name;
	ArrayDb scores;
	std::ostream& arr_out(std::ostream& os) const;	// scores ����� ���� private �Լ�
public:
	Student() : name("Null Student"), scores() { }
	explicit Student(const std::string& s) : name(s), scores() { }
	explicit Student(int n) : name("Nully"), scores(n) { }
	/*
		- �ϳ��� �Ű������� ȣ��� �� �ִ� �����ڴ�, �� �Ű������� ���������� Ŭ���������� �Ͻ������� ��ȯ�ϴ� �Լ��� ����Ѵ�.
		  �� ��������, ù ��° �Ű�������, �� �迭�� ���� ���� �ƴ϶�, �迭�� ���� ������ ��Ÿ����.
		  �׷��� �����ڸ� int-to-Student ��ȯ �Լ��� ����ϰ� ����ϴ� ���� �縮�� ���� �ʴ´�.
		  explicit�� ����ϸ� �Ͻ��� ��ȯ�� ������.
		  ���� �� Ű���带 �����ϸ� ������ ���� �ڵ带 ����� �� �ִ�.
				  Student doh("Homer", 10);		// name�� "Homer"�� �����ϰ�, ���� 10��¥�� �� �迭�� �����.
				  doh = 5;						// name�� "Nully"�� �����ϰ�, ���� 5��¥�� �� �迭�� �����.
												// Student(5) �����ڸ� ȣ���Ͽ� 5�� �ӽ� Student ��ü�� ��ȯ�� ���̴�. �׷��� ����, ���� ������ ������ doh�� �� �ӽ� ��ü�� ��ü�� ���̴�.
	*/

	Student(const std::string& s, int n) : name(s), scores(n) { }
	Student(const std::string& s, const ArrayDb& a) : name(s), scores(a) { }
	Student(const char* str, const double* pd, int n) : name(str), scores(pd, n) { }
	/*
		- ������ ��ü�� �ʱ�ȭ
			-> Queue::Queue(int qs) : qsize(qs)	
					�� �ڵ�� ��� �ʱ��� ����Ʈ���� ������ ����� �̸��� ����Ѵ�.
			-> hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs) { ... }
					�� �ڵ�ó�� ��ӵǴ� ��ü�� ��쿡�� ��� �ʱ��� ����Ʈ���� Ŭ���� �̸��� ����Ͽ� Ư���� ���� Ŭ���� �����ڸ� ȣ���Ѵ�.
			-> Student(const char* str, const double* pd, int n) : name(str), scores(pd, n) { }
					�� ���� ó�� ��� ��ü�� ��쿡�� �����ڵ��� ��� �ʱ��� ����Ʈ���� ��� �̸��� ����Ѵ�.
					����Ʈ�� ������ �� �׸��� �ش��ϴ� �����ڸ� ȣ���Ѵ�. ��,
					name(str) -> string(const char*) ȣ��
					scores(pd, n) -> ArrayDb(const double*, int) ȣ�� -> valarray<double>(const double*, int)

		- C++�� � ��ü�� ������ �κ��� �����Ǳ� ���� ��� ��� ��ü���� ���� �����Ǿ�� �Ѵٰ� �䱸�Ѵ�.
		  ���� ��� �ʱ��� ����Ʈ�� ������� �ʴ´ٸ�, C++�� ��� ��ü Ŭ������ ���� ���ǵ� ����Ʈ �����ڸ� ����Ѵ�.
		- �ϳ� �̻��� �׸���� �ʱ�ȭ�ϴ� ��� �ʱ��� ����Ʈ�� ����Ѵٸ�, �� �׸���� ��� �ʱ��� ����Ʈ�� ��Ÿ���� ������� �ʱ�ȭ���� �ʰ�,
		  �׵��� ����� ������� �ʱ�ȭ�ȴ�.
	*/

	~Student() { }

	double Average() const;
	const std::string& Name() const;
	double& operator[](int i);
	double operator[](int i) const;

	// name ����� ������ �� �ֵ��� �ϱ� ���� �Ʒ� �Լ����� Student Ŭ������ �����尡 �Ǿ�� �Ѵ�.
	// �� �ٸ� �浵��, �Ʒ� �Լ����� private ������ ��� name ��ſ� public �޼��� Name()�� ����� �� �ִ�.
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif

/*
	- valarray Ŭ����
		: ����
			double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
			valarray<double> v1;				// double���� �迭, ũ�� 0
			valarray<int> v2(8);				// int�� ���� 8��¥�� �迭		
			valarray<int> v3(10, 8);			// int�� ���� 8��¥�� �迭, ���� 10���� ����
			valarray<double> v4(gpa, 4);		// double�� ���� 4��¥�� �迭, gpa�� ù 4���� ���ҷ� �ʱ�ȭ
		: �޼���
			operator[]()
			size()
			sum()
			max()
			min()
*/