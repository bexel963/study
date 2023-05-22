#include <iostream>

using namespace std;

void menu();

int main()
{
	char input;
	menu();

	while ((input = cin.get()) && input != 'q')
	{
		cin.get();
		switch (input)
		{
		case 'c':
			cout << "카메라 선택!!\n";
			break;
		case 'p':
			cout << "피아노 선택!!\n";
			break;
		case 't':
			cout << "나무 선택!!\n";
			break;
		case 'g':
			cout << "게임 선택!!\n";
			break;
		default:
			cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q): ";
		}
	}
	return 0;
}

void menu()
{
	cout << "다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q)" << endl;
	cout << "c) camera\t\tp) pianist\nt) tree\t\t\tg) game\n";
}