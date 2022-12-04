#define QUIT 5
#define HOTEL1 180.00
#define HOTEL2 225.00
#define HOTEL3 225.00
#define HOTEL4 355.00
#define DISCOUNT 0.95
#define STARS "***********************"

int menu(void);			// 메뉴판
int getnights(void);		// 원하는 숙박 일수 리턴
void showprice(double rate, int nights);	// 객실 요금과 숙박 일수로부터 총 투숙 요금을 계산하여 그 결과를 화면에 표시
