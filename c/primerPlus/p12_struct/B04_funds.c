#include <stdio.h>
#define FUNDLEN 50

// 함수에 구조체 전달하기
struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);
double sum2(const struct finds*);
double sum3(struct funds moolah);

int main(void)
{
	struct funds stan = {
		"국민은행",
		304.72,
		"동아상호신용금고",
		9237.11
	};
	
	printf("Stan 씨의 총 잔고는 $%.2f입니다.\n", sum(stan.bankfund, stan.savefund));	// 구조체의 멤버 전달
	printf("Stan 씨의 총 잔고는 $%.2f입니다.\n", sum2(&stan));						// 구조체의 주소 전달
	printf("Stan 씨의 총 잔고는 $%.2f입니다.\n", sum3(stan));							// 구조체 전달

	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}
double sum2(const struct funds* money)
{
	return (money->bankfund + money->savefund);
}
double sum3(struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}

/*
	- sum3()이 호출되었을 때, moolah라는 이름의 자동변수가 funds 템플릿에 따라 만들어진다.
	  그러면 이 구조체의 멤버들은 구조체 stan의 대응하는 멤버들이 가지고 있는 값의 복사본으로 각각 초기화 된다.
	  따라서 원본 구조체의 복사본을 사용하여 계산이 이루어진다.
	
	- 최신의 C는 한 구조체를 다른 구조체에 대입하는 것을 허용한다. 배열의 경우에는 이것을 할 수 없다.
	  n_data와 o_data가 같은 데이터형의 구조체라면, 다음과 같이 할 수 있다.
			o_data = n_data;	
	  이것은 o_data의 각 멤버에 n_data의 대응하는 각 멤버의 값이 대입되게 한다. 멤버가 배열일 경우에도 동작한다.
	  또한 같은 데이터형의 구조체라면, 한 구조체를 다른 구조체로 초기화할 수 있다.
			struct name right_field = {"Ruthie", "George"};
			struct name captain = right_field;
*/