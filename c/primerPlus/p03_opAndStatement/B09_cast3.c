#include <stdio.h>

const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;	// 1킬로미터의 마일 수 

int main(void)
{
	double distk, distm;	// 달린 거리(각각 킬로미터 수와 마일 수)
	double rate;			// 평균속도(시간당 마일 수로)
	int min, sec;			// 달린 시간(분, 초)
	int time;				// 달린 시간(초)
	double mtime;			// 1마일을 달린 시간(초)
	int mmin, msec;		// 1마일을 달린 시간(분, 초)

	printf("이 프로그램은 미터단위계로 측정한 달리기 기록을\n");
	printf("1마일을 달린 시간과, 평균속도로 변환한다.\n");

	printf("달린 거리를 킬로미터 수로 입력하시오.\n");
	scanf("%lf", &distk);

	printf("달린 시간을 분 수와 초 수로 입력하시오.\n");
	printf("먼저 분 수부터 입력하시오.\n");
	scanf("%d", &min);
	printf("이제 초 수를 입력하시오.\n");
	scanf("%d", &sec);
	
	time = min * S_PER_M + sec;
	distm = M_PER_K * distk;
	rate = distm / time * S_PER_H;

	// 시간 / 거리 = 마일당 시간
	mtime = (double)time / distm;
	mmin = (int)mtime / S_PER_M;
	msec = (int)mtime % S_PER_M;
	printf("당신은 %1.2f킬로미터(%1.2f마일)를 %d분, %d초에 달렸다.\n", distk, distm, min, sec);
	printf("이 페이스는 1마일을 %d분, %d초에 달린 것에 해당한다.\n", mmin, msec);
	printf("평균 속도는 %1.2fmph였다.\n", rate);

	return 0;
	
}