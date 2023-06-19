

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
		cout << "���� = " << volume << endl;
		cout << "ä�� = " << channel << endl;
		cout << "��� = " << (mode == Antenna ? "������ ���" : "���̺� ���") << endl;
		cout << "�Է� = " << (input == TV ? "TV" : "DVD") << endl;
	}
}
