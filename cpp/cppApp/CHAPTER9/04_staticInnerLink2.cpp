#include <iostream>

extern int tom;				// �ܺ� ���� ���
static int dick = 10;		// ���� ����, ���θ�ũ	
int harry = 200;			// ���� ����, �ܺθ�ũ (�ܺ� ���� ����)

void remote_access()
{
	using namespace std;
	cout << "remote_access()�� �����ϴ� �� ������ �ּ�: \n";
	cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
}