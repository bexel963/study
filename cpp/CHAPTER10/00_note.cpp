/*
	< ������ ���α׷��� ��� >
	- ó���ؾ� �� ������ �켱������ ������ ���߰�, �׷��� ���� �����͸� ǥ���� ����� ã�´�.

	< OOP >
	- ��ü�� �����ϴ� �� �ʿ��� �����Ϳ�, ����ڰ� �� �����͸� �ٷ�� ����� ���� �����ϸ鼭, ����ڰ� �����ϴ� ��Ĵ�� ��ü�� ������ �����.
	  �̷��� �������̽��� �����ϰ� �� ��, �������̽��� ������ ���� ���¸� �����ϴ� ������ ���ư���.

	< �߻�ȭ >
	- ������ ����� �������̽��� ǥ���ϴ� ��.
	  � ������ ���� �ʼ����� ������ ��ɵ��� �߻�ȭ�ϰ�, �װ����� �ذ�å�� ǥ���ϴ� ��.
	  �߻�ȭ�� ���ؼ� ����� ���� ������������ ���ư���.
	  C++������ Ŭ������ �߻�ȭ �������̽��� �����ϴ� ����� ���� ���������̴�.

	< �������� >
	- �װ��� ������� ������ �� �ִ� ���꿡 ���� ���ǵȴ�.
	  � ������ int������ �����ϰų� float���� �����ϴ� �����ͷ� �����Ѵٰ� �� ��, �׷��� ������ ���� �޸𸮸� �����ϴ� ���� �ƴ϶�,
	  �� ������������ ������ �� �ִ� ��������� �Բ� ���ǵǴ� ���̴�.
	- ����� �⺻ ���������� ���, ���ۿ� ���� �������� �����Ϸ��� ����ȴ�
	  �׷��� ����� ���� ���������� �����Ѵٸ�, ���α׷��Ӱ� �̿� ���� ������ ���� �����ؾ� �Ѵ�.

	< Ŭ���� >
	- �߻�ȭ�� ����� ���� ������������ ��ȯ�� �ִ� C++�� �����̴�.
	  Ŭ������ ������ ǥ���� �����͸� �����ϴ� �޼������ �ϳ��� ��Ű�� �ȿ� �����Ѵ�.
	   
	< Ŭ���� ���� >
	- step1) Ŭ���� ���� -> ������ ����� public �������̽�, ����Լ��� �̿��Ͽ� ������ ǥ���� �����Ѵ�.
						   (Ŭ������ ���並 ����)
	- step2) �޼��� ���� -> Ŭ���� ����Լ��� ��� �����Ǵ����� �����Ѵ�.
						   (���� ������ ����)

	< �������̽� >
	- �� �ý��� ���� ��ȣ �ۿ��� ���� ����� �����ӿ�ũ
	- ���α׷� �������̽���, ������� �ǵ��� ��ǻ�Ϳ� ����Ǿ� �ִ� Ư�� ������ ��ȯ�ϴ� ���� ����Ѵ�.

	< �߻�ȭ -> ĸ��ȭ >
	- Ŭ���� ����� public �������̽��� �������� ������ �и��Ϸ��� ����Ѵ�.
	  �� ��, public �������̽��� ������ �߻�ȭ�� ��Ÿ����.
	- �������� �������� ���� �����Ͽ� �߻�ȭ�� �и��ϴ� ���� ĸ��ȭ��� �Ѵ�.
		ex1) ������ ����(�����͸� Ŭ������ private �κп� �ִ� ��)
			 -> private �κп� �ִ� ������ public ����Լ��� ���ؼ��� ���� �����ϴ�.
			 -> �����Ϳ� ���� �������� ���ϰ� ���� �� �Ӹ� �ƴ϶�, ������ ǥ���� ��� �Ǿ��ִ����� ����
			    Ŭ���� ����ڰ� �Ű� ���� �ʵ��� �� �ش�.
		ex2) Ŭ���� �Լ����� ���Ǹ� Ŭ���� ����� ������ ���Ͽ� �ִ� ��	

	< ���� >
	1. Ŭ����
		: ����� ���� ���������� ���� �̴�.
		: Ŭ���� ������ �����͸� �����ϴ� ����� �����͵鿡 �����Ͽ� �׵��� �����ϴ� �� ����� �� �ִ� �޼������ �����Ѵ�.
	2. �߻�ȭ
		: Ŭ������ Ŭ���� �޼����� public �������̽��� ���� Ŭ���� ��ü�� ������� ������ �� �ִ� �����ڵ��� �����Ѵ�.
	3. ����
		: Ŭ������ ������ ����鿡 ���� private�� ����Ͽ�, ��� �Լ��� ���ؼ��� �� �����Ϳ� ������ �� �ִ�.
	4. ĸ��ȭ
		: ������ ǥ���� �޼��� �ڵ�� ���� ���� ������ ����ڿ��� ���еǾ� �ִ�.

	< ��ü ���� >
	- � Ŭ������ �� ��ü�� ������ ��, ������ �� ��ü�� ��ü�� �������� ������(��, Ŭ���� �����)�� ���� ���� ������ ������.
	  �׷��� ���� Ŭ������ ���ϴ� ��� ��ü����, Ŭ���� �޼������ �� ī�Ǿ� �𿩼� ������ ������ Ŭ���� �޼��� ������ �����Ѵ�.
	- ����Լ��� ȣ���Ѵٴ� ����, �ٸ� OOP ���� �޽����� �����ٴ� ���� ���� ���̴�.
	  �׷��Ƿ�, �� ���� ���� �ٸ� ��ü�� ���� �޽����� �����ٴ� ����, ���� �޼��带 ȣ���Ͽ� �װ��� �� ���� ���� �ٸ�
	  ��ü�� �����Ѵٴ� ���� ���� ���̴�.
*/

/*
	< ������ >
	- �� Ŭ������ ��ü�� ������ ������ ȣ��Ǵ� Ư���� ������ Ŭ���� ��� �Լ��̴�.
	- C++�� ������� ��ǥ ���� �ϳ���, Ŭ���� ��ü�� ǥ�� ���������� ����ϵ��� ����� �� �ְ� ����� ���̴�.
	  �׷��� Ŭ������ �����͵��� private ���� ��� ������ �־� ǥ�� �������� ó�� �ʱ�ȭ �� �� ����.
	  �� ������ �ذ��ϱ� ���� C++��, ���ο� ��ü�� �����ϰ� �׵��� ������ ����� ���� ������ �ִ� Ŭ���� �����ڶ�� Ư���� ��� �Լ��� �����Ѵ�.
	- �����ڴ� ��ü�� ������ �� ���α׷��� �ڵ����� ȣ���Ѵ�.

	- �������� ����, ����, ���

		: ���� (����Ʈ �Ű������� ����ϴ� �������� ����)
			Stock(const string& co, long n = 0, double pr = 0.0);

		: ����
			Stock::Stock(const string& co, long n, double pr)
			{
				company = co;
				if(n<0)
				{
					std::cerr << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares�� 0���� �����մϴ�.\n";
					shares = 0;
				}
				else
					shares = n;
				share_val = pr;
				set_tot();
			}

		: ���
		  : �����ڰ� ��ü�� ����� ���� ������ �������� ��ü�� ���� �����̹Ƿ�, ������ ȣ�⿡ ��ü�� ����� �� ����.
			�����ڴ� ��ü�� ���� ȣ��Ǵ� ���� �ƴ϶�, ��ü�� �����ϴ� �� ���ȴ�.
			  1) ������ ȣ��
					Stock garment = Stock("Furry Mascon", 50, 2.5);
			  2) �Ͻ��� ȣ��
					Stock garment("Furry Mascon", 50, 2.5);
			  3) ���� �޸� ������ ���� ȣ��
					Stock* pstock = new Stock("Furry Mascon", 50, 2.5);		// �� ���, ��ü�� �̸��� ������ ���� �ʴ�.

	< ����Ʈ ������ >
	- ����ڰ� ��� �����ڵ� �������� ���� ��쿡�� �����Ϸ��� ����Ʈ �����ڸ� �����Ѵ�.

	- �������� ����, ����, ���
		: ����
			Stock();
		: ����(�� ���� ���)
			: �� ���� ��� �� ����ڴ� �ϳ��� ����Ʈ �����ڸ� ���� �� �ִ�. -> �� ���� ����� �� ����Ͽ� �� ���� ����Ʈ �����ڸ� ����� �� �ȴ�.
				1) ��� �Ű������� ����Ʈ ���� �����ϴ� ��.
					Stock(const string& co = "Error", int n = 0, double pr = 0.0);
				2) �Լ� �����ε��� ����Ͽ� �Ű������� ���� �� �ϳ��� �����ڸ� ���� �ϴ� ��.
					Stock::Stock()
					{
						company = "no name";
						shares = 0;
						share_val = 0;
						total_val = 0;
					}
		: ���
			1) ������ ȣ��
				Stock first = Stock();
			2) �Ͻ��� ȣ��
				Stock first;
			3) ���� �޸� ������ ���� ȣ��
				Stock* pFirst = new Stock;

	- ����
		: �Ǽ��� ����Ʈ �����ڰ� �ƴ� �������� �Ͻ����� ������ �����ϸ� �� �ȴ�.
		: ����Ʈ �����ڸ� �Ͻ������� ȣ���� ���� ��ȣ�� ����ϸ� �� �ȴ�.

	< �ı��� >
	- ��ü�� ������ ������ ��������, ���α׷��� �ı��ڸ� Ư���� ��� �Լ��� �ڵ����� ȣ���Ѵ�.
	- �ı��ڰ� ȣ��Ǵ� ������ �����Ϸ��� �����Ѵ�.
	- Ŭ�������� �ݵ�� �ı��ڰ� �־�� �Ѵ�. ����ڰ� �ı��ڸ� �������� ������, �����Ϸ��� ����Ʈ �ı��ڸ� �����Ѵ�.

	< const ��� �Լ� >
	- �ʿ��� �� �Լ��� ���� �Ű������� const ������ const �����͸� ����ؾ� �ϵ���,
	  ȣ�� ��ü�� �����ϸ� �� �Ǵ� Ŭ���� �޼������ const�� ������ �Ѵ�.
		void show() const;			// const��� �Լ� ���� -> ȣ�� ��ü�� �������� �ʴ´ٰ� ����Ѵ�.
		void Stock()::show() const	// ���� �κп��� const�� �ٿ��ش�.

	< this >
	- �ϳ��� �޼��尡 �� ���� ��ü�� ���ÿ� ó���� �ʿ䰡 �ִ�.
	  �װ��� �����ϰ� �ϱ� ���ؼ� C++�� this��� Ư���� �����͸� �����Ѵ�.
	- this �����ʹ� ��� �Լ��� ȣ���ϴ� �� ���� ��ü�� �����Ѵ�.
	- �⺻������ this�� �� �޼��忡 ���� �Ű������� ���޵ȴ�.
	- �Ϲ�������, �����ڿ� �ı��ڸ� ������ ��� Ŭ���� �޼������ �� �޼��带 ȣ���ϴ� ��ü�� �ּҷ� �����Ǵ� �ϳ��� this�����͸� ���´�.
	- ȣ���� ��ü�� �޼��尡 ��ü������ ������ �ʿ䰡 ���� ��쿡��, *this�� ����� �� �ִ�.
*/

/*
	< ��ü �迭 >
	- ��ü �迭�� ����� �ʱ�ȭ�� ǥ�� ���������� �迭�� ��İ� ����.
	- ������ ���ҿ� ���� �����ڸ� ȣ���Ͽ� �ʱ�ȭ �Ѵ�.
		const int STKS = 4;
		Stock stocks[STKS] = {
			Stock("NanoSmart", 12.5, 20),
			Stock(),
			Stock("Boffo Objects", 200, 2.0),
			Stock("Monolithic Obellisks", 130, 3.25)
		};
	- ��ü���� �迭�� �ʱ�ȭ�ϴ� �� ����� ó���� ����Ʈ �����ڸ� ����Ͽ� �迭�� ���ҵ��� �����Ѵ�.
	  �׷� ���� �߰�ȣ �ȿ� �ִ� �����ڵ��� �ӽ� ��ü�� �����ϰ�, �� ������ �迭 ���ҿ� �����Ѵ�.
	  �׷��Ƿ� Ŭ���� ��ü���� �迭�� �����Ϸ��� Ŭ������ �ϳ��� ����Ʈ �����ڸ� ������ �Ѵ�.
*/

/*
	< Ŭ���� ��� ���� >
	- ��� �Լ����� ������ ������ ��� ���� ���� �����ڸ� ����ؾ� �Ѵ�.
		void Stock::update(double price) 
		{
			...
		}
	- Ŭ���� ��� �̸��� ����� ������ ��Ȳ�� ���� ���� ��� ������(.)�� ���� ��� ������(->) �Ǵ� ��� ���� ���� ������(::)�� ����ؾ� �Ѵ�.

	< Ŭ���� ��� ���� ��� >
	- ��� ��ü���� �����ϴ� �ϳ��� ����� ����� ���� �߸��� ���
		class Stock
		{
		private:
			const int Months = 12;
			double costs[Months];
			...
		}
	  �� �ڵ�� ������ -> Ŭ������ �����ϴ� ���� ��ü�� ��� ������� �����ϴ� ������, �� ��ü�� �����ϴ� ���� �ƴϱ� �����̴�.
						 ���� ���� ������ ��� ������ ��ü�� ������ ������ ���õ��� �ʴ´�.
	
	- �ùٸ� ��� �� ����
	1. Ŭ���� �ȿ� ����ü ����
		class Bakery
		{
		private:
			enum { Months = 12; }
			double consts[Months];
			...
		}
	  ����ü�� �����ϴ� ����, Ŭ���� ������ ����� �������� �ʴ´�. 
	2. static ���
		class Bakery
		{
		private:
			static const int Months = 12;
			double consts[Months];
			...
		}
	  static ����� ��ü ���� �ƴ϶� �ٸ� ���� ������� �Բ� ����Ǵ� Months��� �ϳ��� ����� �����Ѵ�.
	  �׷��� ��� Bakery ��ü���� �ϳ��� Months ����� �����Ѵ�.
*/

/*
	< �߻�ȭ �������� - Abstract Data Type >
	- ADT�� �� �ý����� �������� �͵��� ������ �ʰ�, ���������� �Ϲ������� �����ϴ� ���̴�.
	- Ŭ������ ����ϴ� ���� ADT�� ������ �� �ִ� ���� ����̴�.
	- ���� ADT
		# �� ������ ������ �� �ִ�.
		# ������ ����⿡ �׸��� �߰��� �� �ִ�.
		# ������ ����⿡�� �׸��� ������ �� �ִ�.
		# ������ ���� �� �ִ��� �˻��� �� �ִ�.
		# ������ ��� �ִ��� �˻��� �� �ִ�.
	- Ŭ������ ADT ����
		: public ��� �Լ���� ���� ������ ��Ÿ���� �������̽��� �����ϴ� Ŭ������ �����Ѵ�.
		: public �������̽��� private�� ������ �巯���� �ʰ�, '������ �����Ѵ�.' '�׸��� Ǫ���Ѵ�.' ���� �Ϲ����� ���� ǥ���ؾ� �Ѵ�.
		: ���� �������� ������ private ������ ������� ����Ѵ�.

		
*/