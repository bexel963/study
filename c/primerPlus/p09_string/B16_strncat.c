#include <stdio.h>
#include <string.h>
#include "myString.h"

#define SIZE 30
#define BUGSIZE 13

/*
	- strcat()은 두 번째 문자열이 첫 번째 배열에 맞는지 검사하지 않는다.
	  첫 번째 배열에 공간을 충분히 할당하지 않는다면, 배열을 채우고 남는 여분의 문자들이 인접한 메모리 위치로 흘러넘치는 사태가 일어날 수 있다.
*/
int main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes.";
	char bug[BUGSIZE];
	int available;

	// 1. strcat()을 사용하기 전에 두 배열 길이의 합을 구한다.
	//    널 문자를 위한 공간을 마련하기 위해 결합된 길이에 1을 더한다.
	puts("네가 가장 좋아하는 꽃이 뭐냐?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
	{
		strcat(flower, addon);
	}
	puts(flower);

	// 2. strncat()사용.
	//    3번째 인자로 전달한 개수에 도달하거나 널 문자를 만나면 추가를 멈춘다.
	//    널 문자를 카운트하기 때문에, bug배열은 최초의 문자열(널 문자는 빼고), 최대 13개의 추가되는 문자들, 종결 널 문자를 충분히 저장할 수 있을만큼 커야한다.
	puts("네가 제일 좋아하는 벌레는 뭐냐?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);

	return 0;
}
