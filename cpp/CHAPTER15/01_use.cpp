#include <iostream>
#include "friendClass.h"

int main()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV의 초기 설정 \"\n";
	s42.setting();
	s42.onOff();
	s42.channelUp();
	cout << "\n42\" TV의 변경된 설정값: \n";
	s42.setting();

	Remote grey;

	grey.set_channel(s42, 10);
	grey.volUp(s42);
	grey.volDown(s42);
	cout << "\n리모콘 사용 후 42\" TV의 설정값:\n";
	s42.setting();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_channel(s58, 28);
	cout << "\n58\" TV의 설정값: \n";
	s58.setting();

	return 0;
}