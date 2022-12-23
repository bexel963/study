// 이 프로그램은 B07_names_str.h 에서 #ifndef 중복 포함 보호 기능을 생략하면 컴파일되지 않는다.

#include <stdio.h>
#include "B07_names_str.h"	// names_st.h의 개정판
#include "B07_names_str.h"	// 실수로 넣은 두 번째 포함

int main()
{
	names winner = { "Less", "Ismoor" };
	printf("우승자는 %s %s 씨입니다.\n", winner.first, winner.last);

	return 0;
}
