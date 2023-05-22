#include <iostream>
#include <new>	// ��ġ ���� new ������ ���

/*
	new�� new[] �����ڴ� ���� �� ���� �Լ��� ȣ���Ѵ�.

	void* operator new(std::size_t);	// new���� ȣ��
	void* operator new[](std::size_t);	// new[]���� ȣ��

	int* pi1 = new int;
		=> int* pi1 = new(sizeof(int)); �� ȣ���Ѵ�.

	int* pi2 = new int[40];
		=> int* pi2 = new(40 * sizeof(int)); �� ȣ���Ѵ�.
*/
struct where
{
	double x;
	double y;
	double z;
};
const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	using namespace std;

	float* p_fees = new float[20];
	int* pi = new int(6);						// *pi�� 6���� �ʱ�ȭ
	double* pd = new double(99.99);			
	where* one = new where{ 2.5, 5.3, 7.2 };	// �������� ����ü �ʱ�ȭ (�ʱ�ȭ ����Ʈ ���) -> C++11������ ����
	int* ar = new int[4]{ 1, 2, 3, 4 };			// �������� ���� �ʱ�ȭ (�ʱ�ȭ ����Ʈ ���) -> C++11������ ����
	int* pin = new int{ 6 };					// �ʱ�ȭ ����Ʈ�� ����� *pin �ʱ�ȭ -> C++11
	double* pdo = new double{ 99.99 };	
	

	double* pd1, * pd2;
	int i;

	cout << "new�� ��ġ ���� new�� ù ��° ȣ��: \n";
	pd1 = new double[N];
	pd2 = new (buffer) double[N];

	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "�޸� �ּ�: \n" << pd1 << " : ��;      " << (void*)buffer << " : ����" << endl;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";    ";
		cout << &pd2[i] << "�� " << pd2[i] << ";" << endl; 
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��:  \n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];	// pd4�� buffer�� ������ �����.
	
	for (i = 0; i < N; i++)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd3[i] << "�� " << pd3[i] << ";    ";
		cout << &pd4[i] << "�� " << pd4[i] << ";" << endl;
	}
	
	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��: \n";
	delete [] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "�޸� ����:\n";
	for (i = 0; i < N; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";    ";
		cout << &pd2[i] << "�� " << pd2[i] << ";" << endl;
	}

	delete[] pd1;
	delete[] pd3;
	// ��ġ ���� new�� ���� ���� �޸𸮸� delete�� ����Ͽ� �������� �ʴ´�.
	// buffer�� ���� ������ �޸𸮴� ���� �޸��̱� �����̴�.
	// delete�� ������ new�� ���� ���Ե� �� �޸𸮸� �����ϴ� �����Ϳ��� ����� �� �ִ�.

	return 0;
}