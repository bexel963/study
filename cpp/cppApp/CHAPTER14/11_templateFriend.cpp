/*
	- 템플릿의 프렌드
		1) 템플릿이 아닌 프렌드
		2) 바운드 템플릿 프렌드	-> 클래스가 구체화될 때 클래스의 데이터형에 의해 프렌드의 데이터형이 결정된다.
		3) 언바운드 템플릿 프렌드	-> 프렌드의 모든 특수화가 그 클래스의 각 특수화에 대해 프렌드들이다.
*/

/*
	1) 템플릿 클래스에 대한 템플릿이 아닌 프렌드 함수
				template <class T>
				class HasFriend
				{
					friend void counts();
					...
				};
	   위 선언은 counts() 함수를 그 템플릿의 가능한 모든 구체화들에 대해 프렌드로 만든다.
	   예를들어, counts()는 HasFirend<int> 클래스와 HasFriend<string> 클래스 모두에 대해서 프렌드이다.
	   프렌드는 HasFriend 객체에 어떻게 접근할 수 있을까?
		   1) 전역 객체에 접근할 수 있다.
		   2) 전역포인터를 사용하여 전역이 아닌 객체에 접근할 수 있다.
		   3) 템플릿 클래스의 static 데이터 멤버에 접근할 수 있다. 그러한 static 데이터 멤버들은 객체와 따로 분리되어 존재한다.
	
	   어떤 프렌드 함수에 템플릿 클래스 매개변수를 제공하기를 원한다고 가정할 때 friend void report(HasFriend&); 와 같은 구문은 불가능하다.
	   HasFriend 객체와 같은 것은 없기 때문...., HasFriend<short>와 같은 특별한 특수화만이 존재한다...
	   따라서 템플릿 클래스 매개변수를 제공하려면, 하나의 특수화를 나타내야 한다.
				template <class T>
				class HasFriend
				{
					friend void report(HasFriend<T>&);	// 바운드 템플릿 프렌드
					...
				};

	   HasFriend<int> hf; 과 같이 특별한 데이터형의 객체를 선언할 때 컴파일러는 템플릿 매개변수 T를 int로 대체한다.
	   이것은 다음과 같은 형식의 프렌드 선언을 제공할 것이다.
				template <class T>
				class HasFriend
				{
					friend void report(HasFriend<int>&);	// 바운드 템플릿 프렌드
					...
				};

	   즉, HasFriend<int>로 선언한 객체의 report()는 HasFriend<int> 클래스에 대한 프렌드가 된다.
	       HasFriend<double>로 선언한 객체의 report()는 HasFriend<double> 클래스에 대해 프렌드인, 오버로딩 버전의 report()가 된다.
	   report()는 템플릿 함수가 아니다. 단지 그것은 템플릿을 매개변수로 가진다.
	   이것은 사용하려는 프렌드들에 대해서 명시적 특수화를 정의해 주어야 한다는 것을 의미한다.
				void report(HasFriend<short>&) {...};	// short를 위한 명시적 특수화
				void report(HasFriend<int>&) {...};		// int를 위한 명시적 특수화
		  
*/

#include <iostream>
using std::cout;
using std::endl;

template <class T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void report(HasFriend<T>&);		// 템플릿 매개변수
};

// 각 특수화는 자신만의 static 데이터 멤버를 가진다.
template <class T>
int HasFriend<T>::ct = 0;

// 모든 HasFriend<T> 클래스에 대해 템플릿이 아닌 프렌드
void counts()
{
	cout << "int 카운트: " << HasFriend<int>::ct << "; ";
	cout << "double 카운트: " << HasFriend<double>::ct << endl;
}

// HasFriend<int> 클래스에 대해 템플릿이 아닌 프렌드
void report(HasFriend<int>& hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

// HasFriend<double> 클래스에 대해 템플릿이 아닌 프렌드
void report(HasFriend<double>& hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout << "선언된 객체 없음: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "hfi1 선언 후: ";
	counts();
	HasFriend<int> hfi2(20);
	cout << "hfi2 선언 후: ";
	counts();

	HasFriend<double> hfdb(10.5);
	cout << "hfdb 선언 후: ";
	counts();

	report(hfi1);
	report(hfi2);
	report(hfdb);

	return 0;
}