#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

/*
	- 코드의 재활용성을 높이는 방법
		1) is-a 관계  -> public 상속
		2) has-a 관계 -> 컴포지션(컨테인먼트)(레이어링), private 상속, protected 상속

	- 컴포지션
		: 다른 클래스의 객체들을 멤버로 가지는(내포하는) 클래스

	- 인터페이스와 구현
		: public 상속에서, 클래스는 인터페이스와 구현을 상속한다. 인터페이스를 획득하는 것은 is-a 관계의 역할이다.
		  컨테인먼트에서는 어떤 클래스가 인터페이스 없이 구현을 획득한다. 인터페이스를 상속하지 않는 것이 has-a 관계의 역할이다.
*/
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	/*
		- typedef를 클래스 정의의 private 부분에 넣는 것은, 그것이 Student 클래스의 외부 사용자들에 의해서가 아니라 Student 구현에 내부적으로 사용될 수 있다는 것을 의미한다.
	*/

	std::string name;
	ArrayDb scores;
	std::ostream& arr_out(std::ostream& os) const;	// scores 출력을 위한 private 함수
public:
	Student() : name("Null Student"), scores() { }
	explicit Student(const std::string& s) : name(s), scores() { }
	explicit Student(int n) : name("Nully"), scores(n) { }
	/*
		- 하나의 매개변수로 호출될 수 있는 생성자는, 그 매개변수의 데이터형을 클래스형으로 암시적으로 변환하는 함수로 기능한다.
		  이 예제에서, 첫 번째 매개변수는, 그 배열에 넣을 값이 아니라, 배열의 원소 개수를 나타낸다.
		  그래서 생성자를 int-to-Student 변환 함수로 기능하게 허용하는 것은 사리에 맞지 않는다.
		  explicit를 사용하면 암시적 변환이 꺼진다.
		  만일 이 키워드를 생략하면 다음과 같은 코드를 사용할 수 있다.
				  Student doh("Homer", 10);		// name을 "Homer"로 설정하고, 원소 10개짜리 빈 배열을 만든다.
				  doh = 5;						// name을 "Nully"로 설정하고, 원소 5개짜리 빈 배열을 만든다.
												// Student(5) 생성자를 호출하여 5를 임시 Student 객체로 변환할 것이다. 그러고 나서, 대입 연산이 원래의 doh를 그 임시 객체로 대체할 것이다.
	*/

	Student(const std::string& s, int n) : name(s), scores(n) { }
	Student(const std::string& s, const ArrayDb& a) : name(s), scores(a) { }
	Student(const char* str, const double* pd, int n) : name(str), scores(pd, n) { }
	/*
		- 내포된 객체의 초기화
			-> Queue::Queue(int qs) : qsize(qs)	
					위 코드는 멤버 초기자 리스트에서 데이터 멤버의 이름을 사용한다.
			-> hasDMA::hasDMA(const hasDMA& hs) : baseDMA(hs) { ... }
					위 코드처럼 상속되는 객체의 경우에는 멤버 초기자 리스트에서 클래스 이름을 사용하여 특정한 기초 클래스 생성자를 호출한다.
			-> Student(const char* str, const double* pd, int n) : name(str), scores(pd, n) { }
					이 예제 처럼 멤버 객체의 경우에는 생성자들이 멤버 초기자 리스트에서 멤버 이름을 사용한다.
					리스트에 나오는 각 항목은 해당하는 생성자를 호출한다. 즉,
					name(str) -> string(const char*) 호출
					scores(pd, n) -> ArrayDb(const double*, int) 호출 -> valarray<double>(const double*, int)

		- C++는 어떤 객체의 나머지 부분이 생성되기 전에 모든 멤버 객체들이 먼저 생성되어야 한다고 요구한다.
		  따라서 멤버 초기자 리스트를 사용하지 않는다면, C++는 멤버 객체 클래스를 위해 정의된 디폴트 생성자를 사용한다.
		- 하나 이상의 항목들을 초기화하는 멤버 초기자 리스트를 사용한다면, 그 항목들은 멤버 초기자 리스트에 나타나는 순서대로 초기화되지 않고,
		  그들이 선언된 순서대로 초기화된다.
	*/

	~Student() { }

	double Average() const;
	const std::string& Name() const;
	double& operator[](int i);
	double operator[](int i) const;

	// name 멤버에 접근할 수 있도록 하기 위해 아래 함수들은 Student 클래스의 프렌드가 되어야 한다.
	// 또 다른 방도로, 아래 함수들은 private 데이터 멤버 name 대신에 public 메서드 Name()을 사용할 수 있다.
	friend std::istream& operator>>(std::istream& is, Student& stu);
	friend std::istream& getline(std::istream& is, Student& stu);
	friend std::ostream& operator<<(std::ostream& os, const Student& stu);
};

#endif

/*
	- valarray 클래스
		: 선언
			double gpa[5] = { 3.1, 3.5, 3.8, 2.9, 3.3 };
			valarray<double> v1;				// double형의 배열, 크기 0
			valarray<int> v2(8);				// int형 원소 8개짜리 배열		
			valarray<int> v3(10, 8);			// int형 원소 8개짜리 배열, 각각 10으로 설정
			valarray<double> v4(gpa, 4);		// double형 원소 4개짜리 배열, gpa의 첫 4개의 원소로 초기화
		: 메서드
			operator[]()
			size()
			sum()
			max()
			min()
*/