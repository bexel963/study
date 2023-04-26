#include <iostream>

int main()
{
	long long population;
	long long numberOfAmericans;
	float rate;

	std::cout << "세계 인구수를 입력하시오: ";
	std::cin >> population;
	std::cout << "미국의 인구수를 입력하시오: ";
	std::cin >> numberOfAmericans;
	
	rate = ((float)numberOfAmericans / population) * 100;

	std::cout << "세계 인구수에서 미국이 차지하는 비중은 " << rate << "%이다." << std::endl;

	return 0;
}