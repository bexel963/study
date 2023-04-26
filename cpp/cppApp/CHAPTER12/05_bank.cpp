#include <iostream>
#include <cstdlib>		// rand(), srand()
#include <ctime>		// time()
#include "queue.h"		

const int MIN_PER_HR = 60;

bool newcustomer(double x);	// 새 고객이 도착했는가?

int main()
{
	using namespace std;
	using std::srand;
	using std::time;

	srand(time(0));		// rand()의 무작위 초기화

	cout << "사례 연구: 히서 은행의 ATM\n";
	cout << "큐의 최대 길이를 입력하십시오: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "시뮬레이션 시간 수를 입력하십시오: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;	// 시뮬레이션 주기 수
	
	cout << "시간당 평균 고객 수를 입력하십시오: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;		// 큐가 가득 차서 발길을 돌린 고객 수
	long customers = 0;		// 큐에 줄을 선 고객 수
	long served = 0;		// 거래를 처리한 고객 수
	long sum_line = 0;		// 큐의 누적 길이
	int wait_time = 0;		// ATM이 빌 때까지 대기하는 시간
	long line_wait = 0;		// 고객들이 줄을 서서 대기한 누적시간

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);		// cycle이 도착한 시간이 된다.
				line.enqueue(temp);		// 큐에 새 고객 추가.
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);			// 다음 고객을 받는다.
				wait_time = temp.ptime();	// wait_time을 설정한다.
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
	}

	// 시뮬레이션 결과 출력
	if (customers > 0)
	{
		cout << " 큐에 줄을 선 고객 수: " << customers << endl;
		cout << "거래를 처리한 고객 수: " << served << endl;
		cout << "  발길을 돌린 고객 수: " << turnaways << endl;
		cout << "       평균 큐의 길이: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "       평균 대기 시간: "
			<< (double)line_wait / served << "분\n";
	}
	else
		cout << "고객이 한 명도 없습니다.\n";
	cout << "완료!\n";

	return 0;
}

bool newcustomer(double x)
{
	return rand() * x / RAND_MAX < 1;
}