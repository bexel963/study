#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template <class T, int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() { }
	explicit ArrayTP(const T& v);
	virtual T& operator[](int i);
	virtual T operator[](int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T& v)
{
	for (int i = 0; i < n; i++)
		ar[i] = v;
}

template <class T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cerr << "�迭�� ��踦 ����� ����: " << i << "--> �߸��� �ε����Դϴ�.\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cerr << "�迭�� ��踦 ����� ����: " << i << "--> �߸��� �ε����Դϴ�.\n";
		std::exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif


/*
	- T: �������� �Ű� ����, n: ���� �Ű�����

	- ArrayTP<double, 12> eggWeights;

		: �� �ڵ�� �����Ϸ����� ArrayTP<double, 12> ��� Ŭ������ �����ϰ�, �� Ŭ������ eggWeights ��ü�� �����϶�� �����Ѵ�.
		  �� Ŭ������ ������ ��, �����Ϸ��� T�� n�� ���� double�� 12�� ��ü�Ѵ�.
		
	- ���� �Ű������� �� ���� ������ ������.
		1) ������, ������, ���� �����Ͱ� ���� �Ű������� �� �� �ִ�.
		   �׷��� double m�� ������ ������, double& rm �̳� double* pm�� ���� �Ű������� ����ȴ�.
		2) ���ø� �ڵ�� ���� �Ű������� ���� �����ϰų� �װ��� �ּҸ� ���� �� ����.
		   �׸��� ���ø��� ��üȭ�� ��, ���� �Ű������� ���Ǵ� ���� ��� �����̾�� �Ѵ�.

	- ���� �Ű����� ���� ����� ���� ū ������, �� �迭 ũ�Ⱑ �ڽŸ��� ���ø��� ���� �����Ѵٴ� ���̴�.
			
			ArrayTP<double, 12> eggWeights;
			ArrayTP<double, 13> donuts;
			: ���� �ٸ� �� ���� Ŭ���� ������ �����Ѵ�.

			Stack<int> eggs(12);
			Stack<int> dunkers(13);
			: Ŭ���� ������ �ϳ��� �����Ѵ�. �׸��� ũ�� ������ �� Ŭ������ ���� �����ڿ� ���޵ȴ�.
			  �̿� ���� ������ ���� ����� �迭 ũ�⸦ ���ǿ� �ڵ�� ���� ���� ���� �ʰ� Ŭ���� ����� �����ϱ� ������ �� �� ���뼺�� �ִ�.
			  
	- ������ Ŭ������ �����ϴ� �Ͱ� ������ ��ũ�е��� ���ø� Ŭ������ ������ �� �ִ�.
			1) ���� Ŭ������ ������ �� �� �ִ�.
			2) ���� Ŭ������ �� ���� �ִ�.
			3) �ٸ� ���ø��鿡 �������� �Ű������� �� ���� �ִ�.

			template <class T>
			class Array
			{
			private:
				T entry;
				...
			};

			1) ���
				template <class Type>
				class GrowArray : public Array<Type> { ... };	
			
			2) �������� ���
				template <class Tp>
				class Stack
				{
					Array<Tp> ar;
					...
				};

			3) �������� �Ű������� ���
				Array < Stack<int> > asi;

*/
