#include <iostream>

int main()
{
	long long population;
	long long numberOfAmericans;
	float rate;

	std::cout << "���� �α����� �Է��Ͻÿ�: ";
	std::cin >> population;
	std::cout << "�̱��� �α����� �Է��Ͻÿ�: ";
	std::cin >> numberOfAmericans;
	
	rate = ((float)numberOfAmericans / population) * 100;

	std::cout << "���� �α������� �̱��� �����ϴ� ������ " << rate << "%�̴�." << std::endl;

	return 0;
}