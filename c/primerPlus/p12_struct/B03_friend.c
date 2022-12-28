#include <stdio.h>
#define LEN 20

struct names {
	char first[LEN];
	char last[LEN];
};
struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

/*
	- 구조체를 가리키는 포인터
		: struct guy* him;		// 구조체 guy를 가리키는 포인터 him 선언
		  struct guy barney;	// 구조체 guy형 변수 barney 선언
		  him = &barney;

		  him->income = 100;
		  barney.income = 100;	// 위 코드랑 같음
		
		: 배열의 경우와는 달리, 구조체의 이름은 구조체의 주소가 아니다. 그러므로 &연산자를 사용해야 한다.
		: fellow는 구조체의 배열이다. 이것은 fellow[0]이 구조체라는것을 의미한다.
		  그래서 him이 fellow[0]을 가리키도록 초기화 하려면 아래 코드 처럼 해야한다.
				him = &fellow[0];

				him->income = 100;
				fellow[0].income = 100;	// 위, 아래 코드와 같음
				(*him).income = 100;	// .연산자가 *연산자보다 우선순위가 높기 때문에 괄호가 필요하다.

		: 일부 시스템에서 구조체의 크기가 부분들의 합보다 클 수 있다. 이것은 시스템이 데이터를 배치하는 특성 때문에 부분들 사이에 틈이 생기기 때문이다.
*/
int main(void)
{
	struct guy fellow[2] = {
		{
			{"Ewen", "Villard"},
			"grilled salmon",
			"personality coach",
			681112.00
		},
		{
			{"Rodney", "Swillbelly"},
			"tripe",
			"tabloid editor",
			23240.00
		}
	};
	
	struct guy* him;

	printf("주  소 #1: %p #2: %p\n", &fellow[0], &fellow[1]);
	printf("주  소 #1: %p #2: %p\n", fellow, &fellow[1]);
	him = &fellow[0];
	printf("포인터 #1: %p #2: %p\n", him, him + 1);

	printf("him->income은 $%.2f, (*him).income은 $%.2f\n", him->income, (*him).income);
	him++;
	printf("him->favfood는 %s, him->handle.last는 %s\n", him->favfood, him->handle.last);

	return 0;
}