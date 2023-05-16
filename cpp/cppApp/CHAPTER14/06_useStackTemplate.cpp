/*
	1. 비서실에서 한 수레의 결재 서류들을 대통령에게 전달한다.
	2. 미결상자가 비어 있으면, 대통령은 그 수레에서 가장 위에 있는 서류를 꺼내 자신의 미결 상자에 넣는다.
	3. 미결상자가 가득 차 있으면, 대통령은 미결상자에서 가장 위에 있는 서류를 꺼내 결제한 후 기결상자에 넣는다.
	4. 미결상자가 비어 있지도 않고 가득 차 있지도 않으면, 대통령은 미결상자에서 가장 위에 있는 서류를 꺼내 처리할 수도있고,
	   아니면 수레에서 그 다음 서류를 꺼내 미결상자에 옮겨 놓을 수도 있다.
			-> 이거는 동전을 던져 자기가 취할 행동을 결정한다.

	: 수레에 실려 있는 서류들을 각각 나타내는 문자열들을 지시하는 포인터들의 배열을 사용하여 이 상황을 시뮬할 수 있다.
	: 미결상자는 스택을 사용하여 나타낼 수 있고, 기결상자는 또 다른 포인터들의 배열을 사용하여 나타낼 수 있다.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stackTemplate.h"

const int Num = 10;

int main()
{
	std::srand(std::time(0));	// 난수 발생기에 씨를 뿌린다.
	std::cout << "스택의 크기를 입력하십시오: ";
	int stackSize;
	std::cin >> stackSize;

	Stack<const char*> st(stackSize);			// 미결상자

	const char* in[Num] = {						// 한 수레의 결재 서류들
				" 1: 노미호", " 2: 주리혜",
				" 3: 이몽룡", " 4: 성춘향",
				" 5: 이수일", " 6: 심순애",
				" 7: 박문수", " 8: 홍길동",
				" 9: 김두한", "10: 하야시",
	};

	const char* out[Num];						// 기결상자

	int processed = 0;
	int nextIn = 0;
	while (processed < Num)
	{
		if (st.isEmpty())
			st.push(in[nextIn++]);
		else if (st.isFull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextIn < Num)
			st.push(in[nextIn++]);
		else
			st.pop(out[processed++]);
	}
	
	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;

	std::cout << "프로그램을 종료합니다.\n";

	return 0;
}

/*
	- 문자열들은 이동하지 않는다. 하나의 문자열을 스택에 푸시하면, 실제로는 기존의 문자열을 지시하는 
	  새로운 포인터가 생성된다. 즉, 그것은 기존 문자열의 주소를 값으로 가지는 포인터를 생성한다.
	  하나의 문자열을 스택에서 팝하면, 그 주소 값이 out 배열에 복사된다.
	  이 프로그램은 포인터들의 배열이 하나의 문자열 상수 집합으로 초기화되기 때문에 const char* 를 데이터 형으로 사용한다./