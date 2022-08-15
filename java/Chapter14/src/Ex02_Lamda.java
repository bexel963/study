
/*
 	- ���ٽ��� Ÿ�԰� ����ȯ
	    interface MyFunction {
	 		void method();
	 	}
	  	MyFunction f = (MyFunction)( () -> { } );
	  	Object ojb = (Object)( () -> { } );
	  	- ���ٽ��� MyFunction�������̽��� ���� �������� �ʾ�����, �� �������̽��� ������ Ŭ������ ��ü�� ������ �����ϱ� ������ ���� ���� ����ȯ�� ����Ѵ�.
	  	  �׸��� �� ����ȯ�� ������ �����ϴ�.
	  	- ���ٽ��� �̸��� ���� �� ��ü�ε��� ObjectŸ�����δ� ����ȯ �� �� ����.
	  	  ���ٽ��� ���� �Լ��� �������̽��θ� ����ȯ�� �����ϴ�. ���� ObjectŸ������ ����ȯ �Ϸ���, ���� �Լ��� �������̽��� ����ȯ ������Ѵ�.
	  	  	- Object obj = (Object)(MyFunction)( () -> { } );
	  	  	- String str = ((Object)(MyFunction)( () -> { } )).toString();	// ObjectŬ������ toString()�� ����ϱ����� Object Ÿ������ ����ȯ.
 */
@FunctionalInterface
interface MyFunction2 {
	void myMethod();
}

public class Ex02_Lamda {

	public static void main(String[] args) {

		MyFunction2 f = () -> System.out.println("Hello World!!");
		Object obj = (MyFunction)(() -> System.out.println("Hello World!!"));
		String str = ((Object)(MyFunction)(() -> System.out.println("Hello World!!"))).toString();
		
		System.out.println(f);
		System.out.println(obj);
		System.out.println(str);
		
//		System.out.println(() -> System.out.println("Hello World!!"));	// ���� - ���ٽ��� ObjectŸ������ ����ȯ �ȵ�.
		System.out.println((MyFunction2)(() -> System.out.println("Hello World!!")));
//		System.out.println(((MyFunction2)(() -> System.out.println("Hello World!!"))).toString());	// ����
		System.out.println(((Object)(MyFunction2)(() -> System.out.println("Hello World!!"))).toString());
		
		// �Ϲ����� �͸� ��ü���, ��ü�� Ÿ���� '�ܺ�Ŭ�������̸�$��ȣ' �� ���� �������� Ÿ���� �����Ǿ��� �ٵ�,
		// ���ٽ��� Ÿ���� '�ܺ�Ŭ�����̸�$$Lambda$��ȣ' �� ���� �������� �Ǿ��ִ�.
	}

}
