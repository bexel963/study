

#include <iostream>
#include "friendClass.h"

bool Tv::volUp()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::volDown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::channelUp()
{
	if (channel < maxChannel)
		channel++;
	else
		channel = 1;
}
void Tv::channelDown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxChannel;
}
void Tv::setting() const
{
	using std::cout;
	using std::endl;
	cout << "TV = " << (state == Off ? "OFF" : "ON") << endl;
	if (state == On)
	{
		cout << "볼륨 = " << volume << endl;
		cout << "채널 = " << channel << endl;
		cout << "모드 = " << (mode == Antenna ? "지상파 방송" : "케이블 방송") << endl;
		cout << "입력 = " << (input == TV ? "TV" : "DVD") << endl;
	}
}
