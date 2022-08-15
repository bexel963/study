import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/*
 	- ���ٽ�
 		: �޼��带 �ϳ��� ��(expression)���� ǥ��. �޼����� �̸��� ��ȯ���� �����Ƿ� �͸��Լ�(anonymous function) ��� �Ѵ�.
 		: �޼��带 ����ó�� �ٷ�� ���� ����������.
 		
 		int max(int a, int b) {
 			return a > b ? a : b;
 		}
 		(int a, int b) -> { return a > b ? a : b; } 
 		(int a, int b) -> a > b ? a : b
 		(a, b) -> a > b ? a : b
 		
 		: ����(statement)�� �ƴ� '��' �̹Ƿ� ���� ';'�� ������ �ʴ´�.
 		: �Ű������� Ÿ���� �߷��� ������ ���� ������ �� �ִ�.
 		: ��ȯŸ�Ե� �׻� �߷��� �����ϱ� ������ ���� �����ϴ�.
 		: �Ű������� �ϳ��Ӥ��� ��쿡�� ��ȣ�� ������ �� �ִ�.
 		: ��ȣ{} ���� ������ �ϳ��� ���� ��ȣ{}�� ������ �� �ִ�. �׷��� ��ȣ{} ���� ������ return ���� ��� ��ȣ{}�� ������ �� ����.
 	
 	- �Լ��� �������̽�
 		: �ڹٿ��� ��� �޼���� Ŭ���� ���� ���ԵǾ�� �Ѵ�.
 		: ���ٽ��� �͸� Ŭ������ ��ü�� �����ϴ�.
 		
 		Object obj = new Object() {										
 						int max(int a, int b) {				=>			(a, b) -> a > b ? a : b
 							return a > b ? a : b;
 						}
 					}
 		* ��ü�� �޼��带 �ٷ���� �ش� Ÿ���� ���������� �־��Ѵ�. �͸� Ŭ������ ��ü�� ��� �ٷ��?
 			- Object obj = (a, b) -> a > b ? a : b;
 			- int value = obj.max(1, 2);	// Object Ÿ���� ���������δ� �͸�ü�� max() ��� �޼��带 �ٷ� �� ����.
 		* ���� ������ Ÿ�����δ� Ŭ���� �Ǵ� �������̽��� ����� �� �ִ�. �׸��� ���ٽİ� ������ �޼��尡 ���ǵǾ� �ִ� ���̾�� �Ѵ�.
 		  �׷��߸�, ���������� �͸� ��ü(���ٽ�)�� �޼��带 ȣ���� �� �ֱ� �����̴�.
 		
 		interface MyFunction {
 			int max(int a, int b);
 		}
 		MyFunction f = new Object() {										
 					   	  int max(int a, int b) {				=>			(a, b) -> a > b ? a : b
 							  return a > b ? a : b;
 						  }
 					   }
 			- MyFunction f = (a, b) -> a > b ? a : b;
 			- int value = f.max(1, 2);		// MyFunction Ÿ���� ���������� �͸�ü�� max() �޼��带 �ٷ� �� �ְԵȴ�.
 		* MyFunction�������̽��� ���ǵ� �޼��� max()�� ���ٽ� (a, b) -> a > b ? a : b �� �޼����� ����ΰ� ��ġ�Ѵ�. �׷��� �͸� ��ü�� ���ٽ����� ��ü�� �� �ִ�.
 		* ��ó�� MyFunction�������̽��� ������ �͸� ��ü�� ���ٽ����� ��ü�� ������ ������ ���ٽĵ� �����δ� �͸� ��ü�̰�, MyFunction�������̽��� ������ �͸� ��ü�� �޼��� max()��
 		  ���ٽ��� �Ű����� Ÿ�԰� ���� �׸��� ��ȯ���� ��ġ�ϱ� �����̴�.
 		* �ϳ��� �޼��尡 ����� �������̽��� �����ؼ� ���ٽ��� �ٷ�� ���� ������ �ڹ��� ��Ģ���� ����� �����鼭�� �ڿ�������.
 		* ���ٽ��� �ٷ�� ���� �������̽��� '�Լ��� �������̽�'��� �Ѵ�.
 			- �Լ��� �������̽����� ���� �ϳ��� �߻� �޼��常 ���ǵǾ� �־�� �Ѵ�. �׷��� ���ٽİ� �������̽��� �޼��尡 1:1�� ����� �� �ֱ� �����̴�.
 */
@FunctionalInterface
interface MyFunction {
	void run();
}
@FunctionalInterface
interface Plus {
	int plus(int a, int b);
}
@FunctionalInterface
interface Mul {
	int mul(int a);
}
public class Ex01_Lamda {

	static void execute(MyFunction f) {
		f.run();
	}
	static MyFunction getMyFunction() {
		MyFunction f = () -> System.out.println("f3.run()");
		return f;
	}
	static void num(int x, int y) {
		System.out.println("x = " + x + ", y = " + y);
	}
	public static void main(String[] args) {
		
		Mul m = x -> x * x;
		System.out.println(m.mul(2));
		
		Plus p = (a, b) -> a + b;
		System.out.println(p.plus(2, 3));
		
		System.out.println((Plus)(a, b) -> a + b);
//		num(1, (a,b)->a+b);
		int[] arr = new int[10];
		Arrays.setAll(arr, (a) -> a+a);
		System.out.println(Arrays.toString(arr));
		
		Arrays.setAll(arr, (i) -> (int)(Math.random()*10)+1);
		System.out.println(Arrays.toString(arr));
		
		MyFunction f1 = () -> System.out.println("f1.run()");	// ���ٽ��� MyFunctionŸ���� ���������� �����Ѵ�.
		
		MyFunction f2 = new MyFunction() {						// �͸� ��ü�� MyFunctionŸ���� ���������� �����Ѵ�.
			public void run() {									// �������̽��� ������ Ŭ������ �޼���� �� ���� �������� ������ �������̽��� ����� �޼����� �� ���� ������ �� �ȴ�.
				System.out.println("f2.run()");
			}
		};
		
		MyFunction f3 = getMyFunction();						// ���ٽ��� ������ ���������� �������� f3�� �����Ѵ�.
		
		f1.run();
		f2.run();
		f3.run();
		
		execute(f1);											// ���ٽ��� ������ f1�� �Ű������� �Ѱ��ش�.
		execute(() -> System.out.println("����"));				// ���ٽ��� �Ű������� �Ѱ��ش�.
		
		// * �� ó�� ���ٽ��� �̿��Ͽ� �޼��带 ����ó�� �ְ�޴� ���� ������ ����.
		// * ��ǻ� �޼��尡 �ƴ϶� ��ü�� �ְ�޴� ���̴�.
		
		
		// < ���ٽ� Ȱ�� �� >
		
		List<String> list = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");
		
		Collections.sort(list, new Comparator<String>() {		// �͸� ��ü�� �Ű������� �Ѱ��ش�.
			public int compare(String s1, String s2) {
				return s2.compareTo(s1);
			}
		});
		
		System.out.println(list);
		
		List<String> list2 = Arrays.asList("abc", "aaa", "bbb", "ddd", "aaa");
		
		Collections.sort(list2, (s1, s2) -> s2.compareTo(s1));	// ���ٽ��� �Ű������� �Ѱ��ش�.
	}

}









