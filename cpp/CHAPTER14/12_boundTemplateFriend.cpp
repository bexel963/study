/*
	2) 템플릿 클래스에 대한 바운드 템플릿 프렌드 함수
		: 프렌드 함수들을 템플릿 자체로 만들 수 있다. => 바운드 템플릿 프렌드로 설정
*/

#include <iostream>
using std::cout;
using std::endl;

// 템플릿 원형
template <class T> void counts();
template <class T> void report(T&);

// 템플릿 클래스
template <class TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT& i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);	// 이 경우, 함수 매개변수로부터 템플릿 데이터형 매개변수(TT)를 유추할 수 있기 때문에, <>를 빈 채로 둘 수 있다.
};

template <class T>
int HasFriendT<T>::ct = 0;

// 템플릿 프렌드 함수들을 정의
template<class T>
void counts()
{
	cout << "템플릿 크기: " << sizeof(HasFriendT<T>) << ": ";
	cout << "템플릿 coutns() : " << HasFriendT<T>::ct << endl;
}

template<class T>
void report(T& hf)
{
	cout << hf.item << endl;
}

int main()
{
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);

	report(hfi1);		// report(HasFriendT<int>&)를 생성
	report(hfi2);		// report(HasFriendT<int>&)를 생성
	report(hfdb);		// report(HasFriendT<double>&)를 생성
	
	cout << "counts<int>() 출력: \n";
	counts<int>();

	cout << "counts<double>() 출력: \n";
	counts<double>();

	return 0;
}