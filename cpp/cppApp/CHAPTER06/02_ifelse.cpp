#include <iostream>

int main()
{
	char ch;

	std::cout << "타이핑하시면, 반복 수행하겠습니다.\n";
	std::cin.get(ch);

	while (ch != '.')
	{
		if (ch == '\n')
			std::cout << ch;
		else
			std::cout << ++ch;
		std::cin.get(ch);
	}
	std::cout << "\n혼란스럽게 해서 죄송합니다.\n";

	return 0;
}