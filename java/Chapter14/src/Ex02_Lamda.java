import javax.security.auth.x500.X500Principal;

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
		System.out.println(((Object)(MyFunction)(() -> System.out.println("Hello World!!"))).toString());
		
	}

}
