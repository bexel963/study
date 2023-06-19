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
	// 컴포지션과 달리, 명시적 객체 이름들이 생략되었고, 인라인 생정자에서 멤버 이름 대신에 클래스 이름이 사용된다.
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
	- has-a 관계를 구현하는 제2의 수단으로 private 상속을 제공한다.
		: private 상속에서는, 기초 클래스의 public 멤버와 protected 멤버가 파생 클래스의 private 멤버가 된다.
		  즉, 기초 클래스의 메서드들이 파생 객체의 public 인터페이스의 일부가 되지 않는다. (= 파생 클래스가 기초 클래스의 인터페이스를 상속받지 않는다.)
		  그러나 파생 클래스의 멤버 함수들 안에서 그것들을 사용할 수 있다.
		: 컨테인먼트는, 객체의 이름이 있는 멤버 객체로 클래스에 추가한다. 
		  반면에 private상속은 객체를 이름이 없는 상속된 객체로 클래스에 추가한다.
		  상속에 의해 추가된 객체나, 컨테인먼트에 의해 추가된 객체를 모두 종속 객체라고 부른다.
		: private 상속은 컨테인먼트와 동일한 기능을 제공한다. 즉, 구현은 획득하지만 인터페이스는 획득하지 않는다. -> has-a 관계를 구현하는 데 사용할 수 있다.
*/

/*
	- private 상속
		: private 상속을 사용하려면, 클래스를 정의할 때 public 대신에 private를 키워드로 사용해야 한다.
		  (디폴트는 private이다. 그래서 접근 제한자를 생략하면 private 상속이 된다.)
		: 위 Student 클래스는 private 데이터를 가질 필요가 없다. 상속되는 두 기초 클래스가 필요한 데이터 멤버들을 모두 제공하기 때문이다.
		  컨테인먼트 버전의 Student 클래스는 명시적으로 이름이 지정된 두 개의 객체를 멤버로 제공하지만, private 상속 버전은 이름이 없는 두 개의 종속 객체를 상속된 멤버로 제공한다.
		: private 상속은 기초 클래스 메서드를 파생 클래스 메서드의 안에서만 사용할 수 있도록 제한한다.
		  그러나 때로는 기초 클래스 기능을 public으로 사용하고 싶을 때가 있을 것이다.
		  컨테인먼트 버전 에서는, public인 Student::Average() 함수 안에서 valarray 클래스의 객체를 사용하여 size()와 sum() 메서드를 사용했다.
		  그러나 private 상속 버전에서는 클래스 이름과 사용 범위 결정 연산자를 사용하여 기초 클래스의 메서드를 호출할 수 있다.
		  즉, 컨테인먼트 접근 방식은 객체 으름을 사용하여 메서드를 호출하고, private 상속은 클래스 이름과 사용 범위 결정 연산자를 사용한다.
			=> 사용 범위 결정 연산자는 기초 클래스 메서드에 접근하는 것을 허용한다.
*/


/*
	- using을 사용하여 접근 다시 정의하기
		: 어떤 특정 기초 클래스 메서드를 파생 클래스에서 public으로 사용할 수 있게 하는 방법
			1) 기초 클래스 메서드를 사용하는 파생 클래스 메서드를 정의한다.
				double Student::sum() const
					{
						return std::valarray<double>::sum();
					}
			2) using 선언 사용
				class Student : private std::string, private std::valarray<double>
					{
						...
						public:
							using std::valarray<double>::min;
							using std::valarray<double>::max;
							using std::valarray<double>::operator[];
							...
					};
				using 선언은 valarray의 메서드를 마치 public의 Student 메서드인 것처럼 사용할 수 있게 만든다.			
				using 선언은 소괄호, 함수 시그내처, 리턴형 없이 멤버 이름만 사용한다.
				using 선언을 사용하는 접근은 상속에만 적용되고 컨테인먼트에는 적용되지 않는다.
		
*/