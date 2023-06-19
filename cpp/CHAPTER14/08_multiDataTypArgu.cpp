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

/*
	- 클래스 템플릿은 암시적 구체화, 명시적 구체화, 명시적 특수화 를 사용할 수 있다는 점에서 함수 템플릿과 비슷하다.
	  템플릿은 클래스를 포괄형으로 서술하는 반면에, 특수화는 구체적인 하나의 데이터형을 사용하여 생성한 클래스 선언이다.

	1) 암시적 구체화 (지금까지 사용한 구체화...)
		: 사용하기를 원하는 데이터형을 나타내는 하나 또는 그 이상의 객체를 선언한다. 그러면 컴파일러는 포괄적인 켐플릿이 제공하는 설계도를
		  사용하여 하나의 특수화된 클래스 정의를 생성한다.

					ArrayTP<double, 30>* pt;	// 암시적 구체화

		  컴파일러는 객체가 요구될 때까지 그 클래스의 암시적 구체화를 생성하지 않는다.
		  아래 구문은 컴파일러에게 하나의 클래스 정의와, 그 정의에 따라 생성되는 하나의 객체를 생성하라고 지시한다.

					ArrayTP<double, 30>* pt;			// 포인터, 아직 객체가 필요 없다.
					pt = new ArrayTP<double, 30>;		// 이제 객체가 요구된다.

	2) 명시적 구체화
		: 키워드 template을 사용하여 클래스를 선언하고, 사용하려는 데이터형을 나타냈을 때, 컴파일러는 명시적 구체화를 생성한다.
		  그 선언은 템플릿 정의와 동일한 이름 공간 안에 있어야 한다.

					template class ArrayTP<string, 100>;	// 클래스 선언
						-> 위의 경우, 컴파일러는 그 클래스의 객체가 아직 생성되거나 언급되지 않았더라도, 메서드 정의를 포함하여 그 클래스 정의를 생성한다.

					ArrayTP<string, 100>;					// 클래스 생성

	3) 명시적 특수화
		: 포괄적인 템플릿 대신에, 사용하려는 특정한 데이터형을 위한 정의이다. 때로는 템플릿이 특정형에 맞게 구체화될 때 조금 다르게 행동하도록 수정해야 하는 경우가 있다.
		  ex) 정렬된 배열을 나타내는 클래스를 위한 템플릿을 정의했다고 가정..
		      이 때 항목들이 배열에 추가될 때 정렬이 이루어진다.

					template <class T>
					class SortedArray
					{
						...
					};

			  위 클래스에서 T가 수치라면 이것은 잘 동작하고, T가 클래스형이라면 T::operator>() 메서드가 정의되어 있을 때 잘 동작한다.
			  그러나 T가 char*형으로 나타내는 문자열이라면 이것은 동작하지 않는다. 실제 템플릿은 동자 하겠지만,
			  문자열들이 알파벳순이 아니라 그들이 저장되어 있는 주소를 기준으로 정렬된다. 그러므로 > 대신에 strcmp()를 사용하는 클래스 정의가 필요하다..
			  그러한 경우에 명시적 템플릿 특수화를 제공할 수 있다. 이것은 포괄적인 데이터형 대신에 구체적인 하나의 데이터형에 맞게 정의된 템플릿 형식을 취한다.
			  특수화된 템플릿과 포괄적인 템플릿이 둘 다 구체화 요구에 적합한 상황에서 어느 하나를 선택해야 한다면, 컴파일러는 특수화된 버전을 사용한다.

			  특수화 형식 => template<> class Classname<specialized-type-name> { ... };
					
					template<> class SortedArray<char*>
					{
						...			<= 이 구현 코드는 배열의 값들을 비교하기 위해 > 대신 strcmp()를 사용할 것이다.
					}

					SortedArray<int> scores;		-> 포괄적인 정의를 사용
					SortedArray<char*> dates;		-> 특수화된 정의를 사용

	4) 부분적인 특수화
		: 데이터형 매개변수들 중의 어느 하나에 구체적인 데이터형을 제공할 수 있다.

					template <class T1, class T2> class Pair { ... };				// 포괄적인 템플릿
					template <class T1          > class Pair<T1, int> { ... };		// T2를 int로 설정한, 부분적인 특수화
					template <>                   class Pair<int, int> { ... };		// 완전한 명시적 특수화

		  키워드 뒤에 있는 <>는 특수화되지 않은 데이터형 매개변수들을 선언한다. 따라서 두 번째의 템플릿 선언은, T2를 int로 특수화하지만 T1은 그대로 남겨둔다.
		  데이터형을 모두 지정하면, 괄호 쌍은 비게 되고 완전한 명시적 특수화가 이루어진다.

		  여러 가지 중에서 하나를 선택해야 한다면, 컴파일러는 가장 특수화된 템플릿을 사용한다.

					Pair<double, double> p1;	// 포괄적인 Pair 템플릿 사용
					Pair<double, int> p2;		// 부분적은 특수화 Pair<T1, int>를 사용
					Pair<int, int> p3;			// 완전한 명시적 특수화 Pair<int, int>를 사용

		  포인터들을 위한 특별한 버전을 제공함으로써, 기존의 템플리을 부분적으로 특수화시킬 수 있다.

					template <class T>		// 포괄적인 버전
					class Feeb { ... };

					template <class T*>		// 포인터를 위한 부분적인 특수화
					class Feeb { ... };		// 수정된 코드...

					포인터가 아닌 데이터형을 제공하면, 컴파일러는 포괄적인 버전을 사용하고,
					포인터를 제공하면 포인터를 위한 부분적인 특수화 버전을 사용한다.

					Feeb<char> fb1;		// 포괄적인 템플릿 사용, T는 char
					Feeb<char*> fb2;	// T* 특수화를 사용, T는 char

		  부분적인 특수화 기능은 다양한 제한을 만드는 것을 허용한다.

					template <class T1, class T2, class T3>		// 포괄적인 템플릿
					class Trio
					{ 
						... 
					};

					template <class T1, class T2>				// T3을 T2 로 설정하는 특수화
					class Trio <T1, T2, T2>
					{
						...
					};

					template <class T1>							// T3과 T2를 T1* 로 설정하는 특수화
					class Trio <T1, T1*, T1*>
					{
						...
					};
					
					Trio<int, short, char*> t1;		// 포괄적인 템플릿 사용
					Trio<int, short> t2;			// Trio<T1, T2, T2> 사용
					Trio<char, char*, char*> t3;	// Trio<T1, T1*, T1*> 사용
*/