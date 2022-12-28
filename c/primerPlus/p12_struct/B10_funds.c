#include <stdio.h>
#define FUNDLEN 50
#define N 2

// 구조체 배열을 사용하는 함수

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds*, int);

int main(void)
{
	struct funds jones[N] = {
		{
			"국민은행",
			4032.27,
			"동아상호신용금고",
			8543.94
		},
		{
			"우리은행",
			3620.88,
			"대한상호신용금고",
			3802.91
		}
	};
	
	/*
		- 배열 이름을 사용하여 그 배열에 있는 첫 번째 구조체의 주소를 함수에 전달 할 수 있다.
		  각괄호 배열 표기를 사용하여 그 배열에 있는 연속적인 구조체들에 접근할 수 있다.
				sum(&jones[0], n);
		  위와 같은 호출은 jones와 &jones[0]이 같은 주소이기 때문에, 배열 이름을 사용하는 것과 동일한 효과를 낸다.
		  즉, 배열 이름을 사용하는 것은, 구조체 주소를 간접적으로 전달하는 방법에 불과하다.
	*/
	printf("Jones 씨네 두 형제의 총 잔고는 $%.2f입니다.\n", sum(jones, N));

	return 0;
}

double sum(const struct funds* money, int n)
{
	double total;
	int i;

	for (i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;

	return total;
}