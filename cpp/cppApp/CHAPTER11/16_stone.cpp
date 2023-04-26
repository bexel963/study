#include <iostream>
#include "stonewt.h"
using std::cout;

void display(const Stonewt, int);

int main()
{
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);	// == Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	cout << "�³� ������ ������: ";
	pavarotti.show_stn();
	
	cout << "Ž���� ������: ";
	wolfe.show_stn();
	
	cout << "������� ������: ";
	taft.show_lbs();

	cout << "---------------------------------------\n";
	pavarotti = 276.8;	// ��ȯ�� ���� �����ڸ� ����Ѵ�.
	taft = 325;			// taft = Stonewt(325) �� ����.
	cout << "���� �Ļ縦 ��ģ �� �׳� ������ ������: ";
	pavarotti.show_stn();
	cout << "���� �Ļ縦 ��ģ �� ������� ������: ";
	taft.show_lbs();
	cout << "������ ������ �׺��� �� ���̴�.\n";
	display(422, 2);
	cout << "���� �ǰ��� �ִ��� ���̴�.\n";

	cout << "---------------------------------------\n";
	cout << "           <��ȯ �Լ� �׽�Ʈ>\n";
	
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;	// �Ͻ��� ��ȯ
	cout << "double������ ��ȯ => ";
	cout << "Poppins: " << p_wt << "�Ŀ��\n";
	cout << "int������ ��ȯ => ";
	cout << "Poppins: " << (int)poppins << "�Ŀ��\n";

	return 0;
}

void display(const Stonewt st, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "��! ";
		st.show_stn();
	}
}