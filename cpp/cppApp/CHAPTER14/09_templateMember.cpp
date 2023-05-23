#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Beta
{
private:
	template <class V>		// ������ ���ø� Ŭ���� ���
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) : val(v) { }
		void show() const { cout << val << endl; }
		V value() const { return val; }
	};

	hold<T> q;		// ���ø� ��ü
	hold<int> n;	// ���ø� ��ü
public:
	Beta(T t, int i) : q(t), n(i) { }

	template <class U>		// ���ø� �޼���
	U blab(U u, T t) { return (n.value() + q.value()) * u / t; }
	/*
		- �� �޼��尡 ȣ��� �� �Ű������� ���� ���� �Ͻ������� �����Ǵ� ��������(U) �ϳ���, �� ��ü�� ��üȭ ���������� ���� �����Ǵ� ��������(T)�� �ϳ� ������.
	*/
	
	void show() const { q.show(); n.show(); }	
};

int main()
{
	Beta<double> guy(3.5, 3);
	cout << "T�� double�� �����Ǿ����ϴ�.\n";
	guy.show();
	cout << "V�� double�� T�� �����Ǿ���, �� ������ V�� int�� �����Ǿ����ϴ�.\n";

	cout << guy.blab(10, 2.3) << endl;		
	cout << "U�� int�� �����Ǿ����ϴ�.\n";
	/*
		- ���������� ���� ���� �� �ڵ� �������� ��ȯ�� �Ͼ blab()�� �ִ� ����� double������ ����Ǵ��� U���� ���ϰ��� int�� �ȴ�.
	*/

	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U�� double�� �����Ǿ����ϴ�.\n";
	/*
		- ù ��° �Ű������ʹ� �ٸ���, �� ��° �Ű������� ���������� �Լ� ȣ�⿡ ���� �������� �ʴ´�.
					cout << guy.blab(10, 3) << endl;
		  �� ó�� ȣ���ϴ��� ������ blab()�� blab(int, double)�� ������ ���̴�. �׸��� 3�� ������ �Լ� ���� ��Ģ�� ���Ͽ� double������ ��ȯ�� ���̴�.
	*/
	
	cout << "���α׷� ����\n";

	return 0;
}