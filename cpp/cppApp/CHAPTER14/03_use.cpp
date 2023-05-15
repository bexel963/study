#include <iostream>
#include "beforeMI.h"
const int LIM = 4;

int main()
{
	Waiter bob("ȫ�浿", 314L, 5);
	Singer bev("������", 522L, 3);

	Waiter w_temp;
	Singer s_temp;

	Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	for (int i = 2; i < LIM; i++)
		pw[i]->Set();
	for (int i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}

	return 0;
}