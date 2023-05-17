#include <iostream>
#include <string>

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) { }
	Pair() { }
};

template <class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}
template <class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}

int main()
{
	using std::cout;
	using std::endl;
	using std::string;

	Pair<string, int> ratings[4] =
	{
		Pair<string, int>("이동갈비", 5),
		Pair<string, int>("태릉갈비", 4),
		Pair<string, int>("수원갈비", 5),
		Pair<string, int>("LA갈비", 3)
	};

	int joints = sizeof(ratings) / sizeof(Pair<string, int>);
	cout << "등급: \t 갈비 종류\n";
	for (int i = 0; i < joints; i++)
		cout << ratings[i].second() << ":\t " << ratings[i].first() << endl;
	cout << "조정된 등급:\n";
	ratings[3].first() = "LA떡갈비";
	ratings[3].second() = 6;

	cout << ratings[3].second() << ":\t" << ratings[3].first() << endl;

	return 0;

}

/*
	- 하나 이상의 데이텋여 매개변수를 사용하는 템플릿을 만들 수 있다.
*/

/*
	- 클래스 템플릿 디폴트 데이터형 매개변수
		template <class T1, class T2 = int> 
		class Topo { ... };

		Topo<double, double> m1;	
		Topo<double> m2;			// T1은 double, T2는 int

	  : 클래스 템플릿 데이터형 매개변수에는 디폴트 값을 제공할 수 있지만, 함수 템플릿 매개변수에는
	    디폴트 값을 제공할 수 없다.
*/