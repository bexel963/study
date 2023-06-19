#include <iostream>
#include <cstdlib>		// rand(), srand()
#include <ctime>		// time()
#include "queue.h"		

const int MIN_PER_HR = 60;

bool newcustomer(double x);	// �� ���� �����ߴ°�?

int main()
{
	using namespace std;
	using std::srand;
	using std::time;

	srand(time(0));		// rand()�� ������ �ʱ�ȭ

	cout << "��� ����: ���� ������ ATM\n";
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ�: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "�ùķ��̼� �ð� ���� �Է��Ͻʽÿ�: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;	// �ùķ��̼� �ֱ� ��
	
	cout << "�ð��� ��� �� ���� �Է��Ͻʽÿ�: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;		// ť�� ���� ���� �߱��� ���� �� ��
	long customers = 0;		// ť�� ���� �� �� ��
	long served = 0;		// �ŷ��� ó���� �� ��
	long sum_line = 0;		// ť�� ���� ����
	int wait_time = 0;		// ATM�� �� ������ ����ϴ� �ð�
	long line_wait = 0;		// ������ ���� ���� ����� �����ð�

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);		// cycle�� ������ �ð��� �ȴ�.
				line.enqueue(temp);		// ť�� �� �� �߰�.
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);			// ���� ���� �޴´�.
				wait_time = temp.ptime();	// wait_time�� �����Ѵ�.
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}
	}

	// �ùķ��̼� ��� ���
	if (customers > 0)
	{
		cout << " ť�� ���� �� �� ��: " << customers << endl;
		cout << "�ŷ��� ó���� �� ��: " << served << endl;
		cout << "  �߱��� ���� �� ��: " << turnaways << endl;
		cout << "       ��� ť�� ����: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "       ��� ��� �ð�: "
			<< (double)line_wait / served << "��\n";
	}
	else
		cout << "���� �� �� �����ϴ�.\n";
	cout << "�Ϸ�!\n";

	return 0;
}

bool newcustomer(double x)
{
	return rand() * x / RAND_MAX < 1;
}