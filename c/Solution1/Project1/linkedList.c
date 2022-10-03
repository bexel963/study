#include<stdio.h>

/*
	- Single linked list (container)
		- 연결 리스트는 여러 구조체 인스턴스를 체인처럼 줄줄이 포인터로 연결한 자료구조이다.
		- 연결에 사용된 포인터 숫자가 한 개이고, 자기 다음을 가리키는 것이 특징이다.
		- 기본적인 구성은 선형이다.

	- 코딩 요령
		- 자료구조는 DB이다.
		- 구조체 배열로 테스트 한다.
		- 연결 순서를 임의로 변경 해본다.
		- 리스트 출력은 별도의 함수로 분리한다.
		- 디버거로 노드 하나씩 따라가며 메모리 위치를 확인한다.
*/
typedef struct NODE {
	int nData;
	struct NODE* next;
} NODE;

int main() {

	NODE list[5] = { 0 };

	// 값 설정
	list[0].nData = 100;
	list[1].nData = 200;
	list[2].nData = 300;
	list[3].nData = 400;
	list[4].nData = 500;

	// 연결 리스트 구조화
	list[0].next = &list[1];
	list[1].next = &list[2];
	list[2].next = &list[3];
	list[3].next = &list[4];
	list[4].next = 0;	// NULL대신 0 사용 가능 - 주소 0번지에는 절대 접근할 수 없다. (접근 즉시 프로그램 사망.)

	for (int i = 0; i < 5; i++)
		printf("list[%d].nData = %d\n", i, list[i].nData);
	printf("\n");

	NODE* pTmp = list;

	while (pTmp->next != 0) {
		printf("%p = %d\n", pTmp, pTmp->nData);
		pTmp = pTmp -> next;
	}

	return 0;
}