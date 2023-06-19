#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Beta
{
private:
	template <class V>		// 내포된 템플릿 클래스 멤버
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) : val(v) { }
		void show() const { cout << val << endl; }
		V value() const { return val; }
	};

	hold<T> q;		// 템플릿 객체
	hold<int> n;	// 템플릿 객체
public:
	Beta(T t, int i) : q(t), n(i) { }

	template <class U>		// 템플릿 메서드
	U blab(U u, T t) { return (n.value() + q.value()) * u / t; }
	/*
		- 이 메서드가 호출될 때 매개변수의 값에 의해 암시적으로 결정되는 데이터형(U) 하나와, 그 객체의 구체화 데이터형에 의해 결정되는 데이터형(T)를 하나 가진다.
	*/
	
	void show() const { q.show(); n.show(); }	
};

int main()
{
	Beta<double> guy(3.5, 3);
	cout << "T가 double로 설정되었습니다.\n";
	guy.show();
	cout << "V가 double인 T로 설정되었고, 그 다음에 V가 int로 설정되었습니다.\n";

	cout << guy.blab(10, 2.3) << endl;		
	cout << "U가 int로 설정되었습니다.\n";
	/*
		- 데이터형이 섞여 있을 때 자동 데이터형 변환이 일어나 blab()에 있는 계산이 double형으로 수행되더라도 U형인 리턴값은 int가 된다.
	*/

	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U가 double로 설정되었습니다.\n";
	/*
		- 첫 번째 매개변수와는 다르게, 두 번째 매개변수의 데이터형은 함수 호출에 의해 설정되지 않는다.
					cout << guy.blab(10, 3) << endl;
		  위 처럼 호출하더라도 여전히 blab()을 blab(int, double)로 구현할 것이다. 그리고 3은 보통의 함수 원형 규칙에 의하여 double형으로 변환될 것이다.
	*/
	
	cout << "프로그램 종료\n";

	return 0;
}