const int Len = 40;
struct golf
{
	char fullname[Len];
	int handicap;
};

void setgolf(golf& g, const char* name, int hc);	// 비대화식으로 구조체 세팅
int setgolf(golf& g);								// 대화식으로 구조체 세팅
void handicap(golf& g, int hc);						// 핸디캡을 새로운 값으로 설정
void showgolf(const golf& g);						// 구조체 내용 출력
