/*
	- 표준 템플리 라이브러리(STL: Standard Template Library)는 컨테이너, 이터레이터, 함수 객체, 알고리즘을 나타내는 템플릿들의 집합을 제공한다.
		1) 컨테이너		-> 배열과 같이, 여러 개의 값을 저장할 수 있는 구성 단위
		2) 알고리즘		-> 배열을 소트하거나 리스트에서 특정 값을 검색하는 것과 같은, 특별한 작업들을 수행하기 위해 사용하는 방법이다.
		3) 이터레이터	-> 배열 안에서 포인터를 사용하여 위치를 옮기듯이, 컨테이너 안에서 위치를 옮길 수 있도록 도와 주는 객체들이다. (포인터의 일반화)
		4) 함수 객체		-> 함수와 비슷한 역할을 하는 객체

		: STL을 사용하여 배열, 큐, 리스트와 같은 다양한 컨테이너들을 생성할 수 있고, 검색, 정렬 무작위화 등 다양한 작업을 수행할 수 있다.
*/

/*
	- 전산 분야에서 사용하는 '벡터'는 수학적인 벡터가 아니라 배열에 상당하는 것이다.
	- 전산 분야의 벡터는 임의로 접근할 수 있는 비슷한 값들의 집합을 저장한다.

			template<class T, class Allocator = allocator<T>>
			class vector
			{
				...
			}

		: string 클래스와 마찬가지로, 여러가지 STL 컨테이너 템플릿들이 메모리 관리에 사용할 allocator 객체를 지정하는 선택적 템플릿 매개변수를 사용한다.
		  이 템플릿 매개변수를 위한 값을 생략하면, 컨테이너 템플릿은 allocator<T> 클래스를 디폴트로 사용한다.
		  allocator<T> 클래스는 new와 delete를 표준 방식으로 사용한다.
*/

#include <iostream>
#include <string>
#include <vector>

const int NUM = 5;

int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	
	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << NUM << "개의 책 제목과 책 등급(0-10)을 입력하십시오.\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << i + 1 << "번 책의 제목을 입력하십시오: ";
		getline(cin, titles[i]);
		cout << i + 1 << "번 책의 등급(0-10)을 입력하십시오: ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "감사합니다. 당신은 다음과 같이 입력하셨습니다:\n등급\t제목\n";
	for (i = 0; i < NUM; i++)
		cout << ratings[i] << "\t" << titles[i] << endl;

	return 0;
}