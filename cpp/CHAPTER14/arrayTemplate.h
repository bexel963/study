#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <class T, int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() { }
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
	virtual T operator[](int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}

template <class T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "배열의 경계를 벗어나는 에러: " << i << "--> 잘못된 인덱스입니다.\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "배열의 경계를 벗어나는 에러: " << i << "--> 잘못된 인덱스입니다.\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif


/*
	- T: 데이터형 매개 변수, n: 수식 매개변수

	- ArrayTP<double, 12> eggWeights;

		: 위 코드는 컴파일러에게 ArrayTP<double, 12> 라는 클래스를 정의하고, 그 클래스의 eggWeights 객체를 생성하라고 지시한다.
		  그 클래스를 정의할 때, 컴파일러는 T와 n을 각각 double과 12로 대체한다.
		
	- 수식 매개변수는 몇 가지 제약이 따른다.
		1) 정수형, 열거형, 참조 포인터가 수식 매개변수가 될 수 있다.
		   그래서 double m은 허용되지 않지만, double& rm 이나 double* pm은 수식 매개변수로 혀용된다.
		2) 템플릿 코드는 수식 매개변수의 값을 변경하거나 그것의 주소를 얻을 수 없다.
		   그리고 템플릿을 구체화할 때, 수식 매개변수에 사용되는 값은 상수 수식이어야 한다.

	- 수식 매개변수 접근 방식의 가장 큰 단점은, 각 배열 크기가 자신만의 템플릿을 각각 생성한다는 것이다.
			
			ArrayTP<double, 12> eggWeights;
			ArrayTP<double, 13> donuts;
			: 서로 다른 두 개의 클래스 선언을 생성한다.

			Stack<int> eggs(12);
			Stack<int> dunkers(13);
			: 클래스 선언을 하나만 생성한다. 그리고 크기 정보는 그 클래스를 위한 생성자에 전달된다.
			  이와 같은 생성자 접근 방식은 배열 크기를 정의에 코드로 직접 적어 넣지 않고 클래스 멤버로 저장하기 때문에 좀 더 융통성이 있다.
			  
	- 보통의 클래스에 적용하는 것과 동일한 테크닉들을 템플릿 클래스에 적용할 수 있다.
			1) 기초 클래스의 역할을 할 수 있다.
			2) 성분 클래스가 될 수도 있다.
			3) 다른 템플릿들에 데이터형 매개변수가 될 수도 있다.

			template <class T>
			class Array
			{
			private:
				T entry;
				...
			};

			1) 상속
				template <class Type>
				class GrowArray : public Array<Type> { ... };	
			
			2) 성분으로 사용
				template <class Tp>
				class Stack
				{
					Array<Tp> ar;
					...
				};

			3) 데이터형 매개변수로 사용
				Array < Stack<int> > asi;

*/
