
public class Ex08 {

	public static void main(String[] args) {
		System.out.println("main(String[] args)�� ���� �Ǿ���");
		firstMethod();
		System.out.println("main(String[] args)�� ���� �Ǿ���");
	}
	
	static void firstMethod() {
		System.out.println("firstMethod()�� ���� �Ǿ���");
		secondMethod();
		System.out.println("firstMethod()�� ���� �Ǿ���");
	}
	static void secondMethod() {
		System.out.println("secondMethod()�� ���� �Ǿ���");
		System.out.println("secondMethod()");
		System.out.println("secondMethod()�� ���� �Ǿ���");
	}
}
