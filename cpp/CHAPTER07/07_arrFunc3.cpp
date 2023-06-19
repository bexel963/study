#include <iostream>

const int Max = 5;
int fill_array(double[], int);
void show_array(const double[], int);
void revalue(double, double[], int);

int main()
{
	using namespace std;
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);

	if (size > 0)
	{
		cout << "�������� �Է��Ͻÿ�: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "�߸� �Է��߽��ϴ�. ��ġ�� �Է��ϼ���: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "���α׷��� �����մϴ�.\n";
	cin.get();
	cin.get();

	return 0;
}

int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << (i + 1) << "�� �ε����� ����: ";
		cin >> temp;
		if (!cin)
		{
			/*
				- cin�� ���� �˻翡 ���� ������ �Է��� ���� ���ο� ���� true �Ǵ� false�� bool������ ��ȯ�ȴ�.
				- 'q' �� �Է��ϸ� cin >> �� 'q'�� ���� �ƴ϶�� �ν��Ѵ�.
				  �׷��� 'q'�� �Է� ť�� �״�� ���� �ΰ�, false�� ��ȯ�� ���� �����Ͽ� ������ �����Ų��.
				- ���α׷��� �Է� ������ �̾ �ٽ� �Է��� �޾Ƶ��� �ʿ䰡 �ִٸ�, cin.clear()�� ����Ͽ� �Է� ���� ���·� �����ϰ�,
				  ���ο� �Է��� �����ϴ� �ҷ� �Է�('q')�� �����ؾ� �Ѵ�.
			*/
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "�Է� �ҷ�, �Է� ������ �����ڽ��ϴ�.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}
void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << "�� �ε���: $";
		cout << ar[i] << endl;
	}
}
void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}