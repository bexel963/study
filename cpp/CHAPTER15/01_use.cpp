#include <iostream>
#include "friendClass.h"

int main()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV�� �ʱ� ���� \"\n";
	s42.setting();
	s42.onOff();
	s42.channelUp();
	cout << "\n42\" TV�� ����� ������: \n";
	s42.setting();

	Remote grey;

	grey.set_channel(s42, 10);
	grey.volUp(s42);
	grey.volDown(s42);
	cout << "\n������ ��� �� 42\" TV�� ������:\n";
	s42.setting();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_channel(s58, 28);
	cout << "\n58\" TV�� ������: \n";
	s58.setting();

	return 0;
}