#include <iostream>
using std::cout;
#include "stonewt.h"

/*
	- ǥ�� ���������� � ���� ǥ�� ���������� �� ������ �����ϴ� ������ �ۼ��ϸ�, �� ���������� ���� ȣȯ�� ��, C++�� �� ���� ����������
	  ���Թ޴� ���忡 �ִ� ������ ������ ������������ �ڵ����� ��ȯ�Ѵ�.
			long count = 8;		// int�� -> long��
			double time = 11;	// int�� -> double��
			int side = 3.33;	// double�� -> int��
	  ������ ��ġ ������������ ��� �⺻������ ������ ���� ��Ÿ����, C++�� �������� ��ȯ�� ���� ���� ��Ģ�� �����ϱ� ������, �̷��� ���� �������� �ٸ��� �����Ѵ�.

	- C++�� ȣȯ���� �ʴ� ���������� �ڵ����� ��ȯ���� �ʴµ� �� �� ���� �������� ��ȯ�� �̿��� �� �ִ�.
			int* p = (int*)10;		// p�� �ּ� 10�� �����Ѵ�.

	- �⺻ ���������̳� �ٸ� � Ŭ������ ����� ���õǾ� �־�, ���� ���� ��ȯ�� �� �ִ� Ŭ������ ������ �� �ִ�.
	  �׷��� ���, �ڵ� ��ȯ�� �� ������ ���� ��ȯ�� �� ������ ����ڰ� C++���� ������ �� �ִ�.
*/

Stonewt::Stonewt(double lbs)	// ��ȯ�Լ� (double�� ���� Stonewt ��ü�� ��ȯ�ϴ� ���ø�)
{
	stone = (int)lbs / Lbs_per_stn;
	pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
	pounds = lbs;
}
/*
	- �ϳ��� �Ű������� ����ϴ� �����ڴ�, �� �Ű������� ���������� Ŭ���������� ��ȯ�ϴ� ���� �����Ѵ�.
	  �� �����ڰ� Ű���� explicit�� ���ѵ� ��쿡��, ����� �������� ��ȯ�� �� �� �ִ�.

	- C++����, �ϳ��� �Ű������� ���ϴ� �����ڴ� �� �Ű����� ���������� ���� Ŭ���������� ��ȯ�ϴ� ���赵ó�� �����Ѵ�.
			Stonewt myCat;
			myCat = 19.6;		// Stonewt(double)�� ����Ͽ� 19.6�� Stonewt���� ��ȯ�Ѵ�.
							   Stonewt(double)�� ����Ͽ� Stonewt �ӽ� ��ü�� �����ϰ� �ʱⰪ���� 19.6�� ����Ѵ�.
							   �׷��� ���� ����� �������� �ӽ� ��ü�� ������ myCat�� �����Ѵ�.
							   �� ������ ����� �������� ��ȯ�� �ʿ� ���� �ڵ����� �̷�����Ƿ� �Ͻ��� �������� ��ȯ�̶�� �Ѵ�.

	- �ϳ��� �Ű������� ����� �� �ִ� �����ڸ��� �̿� ���� ��ȯ �Լ��� �����Ѵ�.
	- �Ű������� �������� �ϳ� ���� ���� ����Ʈ ���� ������ ���, ��ȯ �Լ��� ������ �Ѵ�.

	- �Ͻ��� �������� ��ȯ�� ���ۿ��� ���� ���� explicit ��� ���ο� Ű���尡 �߰� �Ǿ���.
	  explicit Ű����� ���� ���� ���� �Ͻ��� �������� ��ȯ�� ���ϰ� ���´�. �׷��� ����� �������� ���� ��ȯ�� ������ ���ȴ�.
			explicit Stonewt(double lbs);
			Stonewt myCat;
			myCat = 19.6;				// �Ͻ��� �������� ��ȯ -> Error
			myCat = Stonewt(19.6);		// ����� �������� ��ȯ -> OK
			myCat = (Stonewt)19.6;		// ����� �������� ��ȯ -> OK				

	- �����Ϸ��� Stonewt(double) �Լ��� ������ ���� ��Ȳ���� ����Ѵ�.
		1) Stonewt ��ü�� double�� ������ �ʱ�ȭ�� ��
		2) Stonewt ��ü�� double�� ���� ������ ��
		3) Stonewt�� �Ű������� ����ϴ� �Լ��� double�� ���� ������ ��
		4) Stonewt�� ���� �����ϵ��� ����� �Լ��� double�� ���� �����Ϸ��� �õ��� ��
		5) double�� ��� ��ȣ���� �ʰ� double������ ��ȯ�� �� �ִ� ���� ���������� ����� ��
				Stonewt jumbo(700);		// int�� -> double�� -> Stonewt(double) ���
				jumbo = 7300;			// int�� -> double�� -> Stonewt(double) ���	
		   ����, �� Ŭ������ Stonewt(long) �����ڵ� ���� ������ �ξ��ٸ� �����Ϸ��� �̵� ������ ������ �ź��Ѵ�. (��ȣ)
*/


Stonewt::Stonewt(int stn, double lbs)	// ��ȯ�Լ� �ƴ�.
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() { }

void Stonewt::show_stn() const
{
	cout << stone << "����, " << pds_left << "�Ŀ��\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << "�Ŀ��\n";
}

std::ostream& operator<<(std::ostream& os, Stonewt s)
{
	cout << s.pounds << "�Ŀ��\n";

	return os;
}

// ��ȯ �Լ� ����
Stonewt::operator int() const
{
	return (int)(pounds + 0.5);
}
Stonewt::operator double() const
{
	return pounds;
}
/*
	- Stonewt wolfe(285.7);
	  double host = wolfe;		// ����?

	- �����ڴ� � ���������� Ŭ���������� ��ȯ�ϴ� �͸� ����Ѵ�.
	  �� ������ �ݴ�� �ϱ� ���ؼ���, ��ȯ �Լ���� �θ��� Ư���� ������ C++������ �Լ��� ����ؾ� �Ѵ�.
	  ��ȯ �Լ��� ����� ���� ���� �������� ��ȯ�̴�. ���� �Ϲ����� ���� �������� ��ȯ ó�� ����ϸ� �ȴ�.
			double host = double(wolfe);		// ���1
			doble thinker = (double)wolfe;		// ���2
			double star = wolfe;				// ���3 - �����Ϸ��� ��ȯ �Լ��� �Ͻ������� ���
	  ���3���� �������� Stonewt���̰� ������ double���̶�� ���� �ν��� �����Ϸ���, ����ڰ� �� ������ �ذ��� �� �ִ�
	  ��ȯ �Լ��� �����ߴ��� ã�ƺ���, ���� �׷��� ���Ǹ� ã�� �� ���ٸ�, �����Ϸ��� Stonewt���� double���� ������ �� ���ٴ�
	  ���� �޽����� ��������.

	- ��ȯ �Լ� �ۼ�
			operator typeName();
	  : ��ȯ �Լ��� Ŭ������ �޼��忩�� �Ѵ�.
	  : ��ȯ �Լ��� �������� ������ �� �ȴ�.
	  : ��ȯ �Լ��� �Ű������� ������ �� �ȴ�. -> typeName �κ��� � ������������ ��ȯ�� ������ �˷��ֹǷ�...

	- ��ȣ�� 
		ex1) cout << "Poppins: " << poppins << "�Ŀ��\n";  <- ������ ���� �� �Ǿ��ִٰ� ����... 
			int������ ��ȯ�ؾ� �ϴ��� double������ ��ȯ�ؾ� �ϴ��� ��ȣ�ϱ� ������ ������ ����..
		ex2) long gone = poppins;
			int��, double�� �� �� long�� ������ ������ �� �־ ��ȣ��..
		
		=> ����� ��ȯ�� ����Ͽ� �Ͻ��� ��ȯ�� ���ɼ��� ���ִ� ���� ����.
				explicit operator int() const;
				explicit operator double() const;
		   �̷��� ������ �ִٸ�, ����ڴ� ��������� ȣ���� ��쿡�� ����ȯ�� ����� �� �ִ�.

	- ��ȯ �Լ� -> ��ȯ �Լ�
		Stonewt::operator int() { return int (pounds + 0.5); }
		int plb = (int)poppins;
		->
		int Stonewt::Stone_to_Int() { return int (pounds + 0.5); }
		int plb = poppins.Stone_to_Int();
			
*/

Stonewt Stonewt::operator+(const Stonewt& st) const
{
	double pds = pounds + st.pounds;
	Stonewt sum(pds);
	return sum;	
}
Stonewt operator-(const Stonewt& st1, const Stonewt& st2)
{
	double pds = st1.pounds - st2.pounds;
	Stonewt sum(pds);
	return sum;
}

/*
	- double�� ���� Stonewt�� ���� ���ϱ�
		1) friend operator+(const Stonewt&, const Stonewt&);
			: Stonewt(double) �����ڸ� ����Ͽ� double�� �Ű������� Stonewt�� �Ű������� ��ȯ�Ѵ�.
		2) Stonewt operator+(double);
		3) friend Stonewt operator+(double, Stonewt&);

		total = jennySt + kennyD;	==> 2�� ȣ��
		total = kennyD + jennySt;	==> 3�� ȣ��
*/