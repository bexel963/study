#include <iostream>

extern double warming;	// external.cpp���� ������ �������� warming�� ���

void update(double);
void local();

using std::cout;

void update(double dt)	// ���� ������ �����Ѵ�.
{
	extern double warming;	// ������ �缱��
	warming += dt;
	cout << "���� warming�� " << warming << "���� ���ŵǾ����ϴ�.\n";
}

void local()
{
	double warming = 0.8;
	
	cout << "���� warming�� " << warming << "���Դϴ�.\n";
	cout << "�׷���, ���� warming�� " << ::warming;
	cout << "���Դϴ�.\n";
}