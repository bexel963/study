#include <iostream>
using std::cout;
using std::endl;

template <class T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i) : item(i) { }
	template <class C, class D> friend void show2(C&, D&);
};

template <class C, class D> void show2(C& c, D& d)
{
	cout << c.item << ", " << d.item << endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);

	cout << "hfi1, hfi2: ";
	show2(hfi1, hfi2);
	// 특수화 => void show2<ManyFriend<int>&, ManyFriend<int>&>(ManyFriend<int>& c, ManyFriend<int>& d);
	/*
		- 이것은 ManyFriend의 모든 특수화에 대해 프렌드이기 때문에, 이 함수는 모든 특수화들의 item 멤버에 접근할 수 있다.
		  그러나 ManyFriend<int> 객체들에 대한 접근만을 사용한다.
	*/

	cout << "hfdb, hfi2: ";
	show2(hfdb, hfi2);
	// => void show2<ManyFriend<double>&, ManyFriend<int>&>(ManyFriend<double>& c, ManyFriend<int>& d);
	/*
		- 이것은 ManyFriend의 모든 특수화에 대해 프렌드이기 때문에, 이 함수는 모든 특수화들의 item 멤버에 접근할 수 있다.
		  이 함수는 ManyFriend<int> 객체의 item 멤버와, ManyFriend<double> 객체의 item 멤버에 대한 접근을 사용한다.
	*/

	return 0;
}

/*
	- 바운드 템플릿 프렌드 함수들은 클래스의 바깥에서 선언된 템플릿의 템플릿 특수화들이다.
	  예를들어, int 클래스 특수화는 int 함수 특수화를 얻는 형식이다.
	- 템플릿을 클래스 안에 선언함으로써, 언바운드 프렌드 함수를 생성할 수 있다.
	  이 때 모든 함수 특수화는 모든 클래스 특수화에 대해 프렌드이다.
	  언바운드 프렌드들의 경우에, 프렌드 템플릿 데이터형 매개변수들은 템플릿 클래스 데이터형 매개변수들과 다르다.
	  
*/